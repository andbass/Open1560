/*
    Open1560 - An Open Source Re-Implementation of Midtown Madness 1 Beta
    Copyright (C) 2020 Brick

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

define_dummy_symbol(agi_print);

#include "print.h"

#include "bitmap.h"
#include "cmodel.h"
#include "pipeline.h"
#include "rsys.h"
#include "texdef.h"
#include "vertex.h"

#include <algorithm>

static mem::cmd_param PARAM_font_scale {"fontscale"};
static mem::cmd_param PARAM_alphafont {"alphafont"};

i32 agiFontWidth = 0;
i32 agiFontHeight = 0;

static Rc<agiTexDef> BuiltinFontTexture = nullptr;

// 0x557FE0 | ?InitBuiltin@@YAXXZ
ARTS_EXPORT /*static*/ void InitBuiltin()
{
    ArAssert(BuiltinFontTexture == nullptr, "Font already initialized");

    // 96 8x8 characters, from 0x20 to 0x7F
    // Split into 16 per row, with 6 rows

    i32 const font_scale = std::max(PARAM_font_scale.get_or<i32>(Pipe()->GetHeight() / 60), 8);
    bool alpha = false;

    agiFontWidth = font_scale;
    agiFontHeight = font_scale;

    Ptr<agiSurfaceDesc> surface;

    if (Pipe()->IsHardware())
    {
        alpha = PARAM_alphafont.get_or(false);
        surface = AsPtr(agiSurfaceDesc::Init(256, 64, Pipe()->GetScreenFormat()));

        Rc<agiColorModel> cmodel = AsRc(agiColorModel::FindMatch(surface.get()));

        u32 const black = cmodel->GetColor(0x00, 0x00, 0x00, alpha ? 0x00 : 0xFF);
        u32 const white = cmodel->GetColor(0xFF, 0xFF, 0xFF, 0xFF);

        u8 const* chars = CharSet;

        for (i32 i = 0; i < 96; ++i)
        {
            i32 char_x = (8 + 1) * (i % 16);
            i32 char_y = (8 + 1) * (i / 16);

            for (i32 pixel_y = 0; pixel_y < 8; ++pixel_y)
            {
                i32 y = char_y + pixel_y;

                for (i32 pixel_x = 0; pixel_x < 8; ++pixel_x)
                {
                    cmodel->SetPixel(surface.get(), char_x + pixel_x, y, ((0x80 >> pixel_x) & *chars) ? white : black);
                }

                ++chars;
            }
        }
    }
    else
    {
        agiSurfaceDesc format {sizeof(format)};
        format.Flags = AGISD_PIXELFORMAT;
        format.PixelFormat = PixelFormat_P8;

        surface = AsPtr(agiSurfaceDesc::Init(256, 64, format));

        surface->lpLut = AsRaw(Pipe()->GetTexLut(const_cast<char*>("*grey")));
        surface->MipMapCount = 3;

        u8 const* chars = CharSet;
        u8* lut = static_cast<u8*>(surface->Surface);

        for (i32 i = 0; i < 96; ++i)
        {
            i32 char_x = (8 + 1) * (i % 16);
            i32 char_y = (8 + 1) * (i / 16);

            for (i32 pixel_y = 0; pixel_y < 8; ++pixel_y)
            {
                i32 y = char_y + pixel_y;

                for (i32 pixel_x = 0; pixel_x < 8; ++pixel_x)
                {
                    lut[(y * surface->Pitch) + char_x + pixel_x] = ((0x80 >> pixel_x) & *chars) ? 0xFF : 0x00;
                }

                ++chars;
            }
        }
    }

    Rc<agiTexDef> texture = AsRc(Pipe()->CreateTexDef());

    agiTexParameters params {};
    arts_strcpy(params.Name, "*BUILTIN");
    params.Flags |= agiTexParameters::NoMipMaps | agiTexParameters::KeepLoaded;

    if (alpha)
        params.Flags |= agiTexParameters::Alpha;

    texture->Init(params, std::move(surface));

    BuiltinFontTexture = texture;
}

void agiPrint(i32 x, i32 y, i32 color, char const* text)
{
    Pipe()->Print(x, y, color, text);
}

void agiPrintInit()
{
    Pipe()->PrintInit();
}

i32 agiPrintIs3D()
{
    return Pipe()->PrintIs3D();
}

void agiPrintShutdown()
{
    return Pipe()->PrintShutdown();
}

void agiPrintf(i32 x, i32 y, i32 color, ARTS_FORMAT_STRING char const* format, ...)
{
    if (y + agiFontHeight <= 0 || y >= Pipe()->GetHeight())
        return;

    char buffer[256];

    std::va_list va;
    va_start(va, format);
    arts_vsprintf(buffer, format, va);
    va_end(va);

    agiPrint(x, y, color, buffer);
}

void agiPipeline::Print(i32 x, i32 y, [[maybe_unused]] i32 color_, char const* text)
{
    if (y + agiFontHeight <= 0 || y >= Pipe()->GetHeight())
        return;

    if (BuiltinFontTexture == nullptr)
        InitBuiltin();

    // RAST->BeginGroup();

    f32 const inv_font_w = 1.0f / BuiltinFontTexture->GetWidth();
    f32 const inv_font_h = 1.0f / BuiltinFontTexture->GetHeight();

    auto tex = agiCurState.SetTexture(BuiltinFontTexture.get());
    auto draw_mode = agiCurState.SetDrawMode(0xF);
    auto depth = agiCurState.SetZEnable(false);
    auto zwrite = agiCurState.SetZWrite(false);
    auto alpha = agiCurState.SetAlphaEnable(false);
    auto filter = agiCurState.SetTexFilter(agiTexFilter::Point);
    auto fog_mode = agiCurState.SetFogMode(agiFogMode::None);
    auto fog_color = agiCurState.SetFogColor(0x00000000);

    const u16 buf_size = 64;

    agiScreenVtx vert_buf[buf_size * 4];
    u16 index_buf[buf_size * 6];

    u32 color = 0xFFFFFFFF;
    u16 count = 0;

    while (*text)
    {
        u8 value = *text++;

        if (value >= 0x20 && value <= 0x7F)
            value -= 0x20;
        else
            value = 0;

        if (count == buf_size)
        {
            RAST->Mesh(agiVtxType::Screen, (agiVtx*) vert_buf, count * 4, index_buf, count * 6);

            count = 0;
        }

        i32 font_x = (8 + 1) * (value % 16);
        i32 font_y = (8 + 1) * (value / 16);

        agiScreenVtx* verts = &vert_buf[count * 4];
        u16* indices = &index_buf[count * 6];

        agiScreenVtx blank {0.0f, 0.0f, 0.0f, 1.0f, color, 0xFFFFFFFF, 0.0f, 0.0f};

        verts[0] = blank;
        verts[1] = blank;
        verts[2] = blank;
        verts[3] = blank;

        verts[3].x = verts[0].x = static_cast<f32>(x);
        verts[1].y = verts[0].y = static_cast<f32>(y);
        verts[3].tu = verts[0].tu = font_x * inv_font_w;
        verts[1].tv = verts[0].tv = font_y * inv_font_h;

        verts[1].x = verts[2].x = static_cast<f32>(x + agiFontWidth);
        verts[3].y = verts[2].y = static_cast<f32>(y + agiFontHeight);
        verts[1].tu = verts[2].tu = (font_x + 8) * inv_font_w;
        verts[3].tv = verts[2].tv = (font_y + 8) * inv_font_h;

        u16 base = count * 4;

        indices[0] = base + 0;
        indices[1] = base + 1;
        indices[2] = base + 2;
        indices[3] = base + 0;
        indices[4] = base + 2;
        indices[5] = base + 3;

        ++count;

        x += agiFontWidth;
    }

    if (count)
    {
        RAST->Mesh(agiVtxType::Screen, (agiVtx*) vert_buf, count * 4, index_buf, count * 6);
    }

    // RAST->EndGroup();

    agiCurState.SetTexture(tex);
    agiCurState.SetDrawMode(draw_mode);
    agiCurState.SetZEnable(depth);
    agiCurState.SetZWrite(zwrite);
    agiCurState.SetAlphaEnable(alpha);
    agiCurState.SetTexFilter(filter);
    agiCurState.SetFogMode(fog_mode);
    agiCurState.SetFogColor(fog_color);
}

b32 agiPipeline::PrintIs3D()
{
    // FIXME: If PrintIs3D is false, then Cull is technically drawing stuff outside of BeginScene.
    // This works with the agiD3DPipeline (though probably shouldn't), but fails with the agiSWPipeline, as the framebuffer is only locked between scenes.

    if (Pipe()->IsHardware())
        return false;

    return true;
}

void agiPipeline::PrintInit()
{
    if (!BuiltinFontTexture)
        InitBuiltin();
}

void agiPipeline::PrintShutdown()
{
    BuiltinFontTexture = nullptr;
}

const u8 CharSet[96 * 8] {
    // clang-format off
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ' '
    0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x18, 0x00, // '!'
    0xCC, 0xCC, 0xCC, 0x00, 0x00, 0x00, 0x00, 0x00, // '"'
    0x36, 0x6C, 0xFE, 0x6C, 0xFE, 0x6C, 0xD8, 0x00, // '#'
    0x18, 0x7E, 0xC0, 0x7C, 0x06, 0xFC, 0x30, 0x00, // '$'
    0xC2, 0xC6, 0x0C, 0x18, 0x30, 0x66, 0xC6, 0x00, // '%'
    0x38, 0x6C, 0x38, 0x70, 0xDE, 0xCC, 0x76, 0x00, // '&'
    0x30, 0x30, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, // '''
    0x0C, 0x18, 0x30, 0x30, 0x30, 0x18, 0x0C, 0x00, // '('
    0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x18, 0x30, 0x00, // ')'
    0x00, 0x6C, 0x38, 0xFE, 0x38, 0x6C, 0x00, 0x00, // '*'
    0x00, 0x18, 0x18, 0x7E, 0x18, 0x18, 0x00, 0x00, // '+'
    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x30, // ','
    0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, // '-'
    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, // '.'
    0x02, 0x06, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x00, // '/'
    0x7C, 0xCE, 0xDE, 0xF6, 0xE6, 0xC6, 0x7C, 0x00, // '0'
    0x18, 0x38, 0x18, 0x18, 0x18, 0x18, 0x7E, 0x00, // '1'
    0x7C, 0xC6, 0x06, 0x1C, 0x70, 0xC6, 0xFE, 0x00, // '2'
    0x7C, 0xC6, 0x06, 0x1C, 0x06, 0xC6, 0x7C, 0x00, // '3'
    0x1C, 0x3C, 0x6C, 0xCC, 0xFE, 0x0C, 0x0C, 0x00, // '4'
    0xFE, 0xC0, 0xFC, 0x06, 0x06, 0xC6, 0x7C, 0x00, // '5'
    0x3C, 0x60, 0xC0, 0xFC, 0xC6, 0xC6, 0x7C, 0x00, // '6'
    0xFE, 0xC6, 0x0C, 0x18, 0x30, 0x30, 0x30, 0x00, // '7'
    0x7C, 0xC6, 0xC6, 0x7C, 0xC6, 0xC6, 0x7C, 0x00, // '8'
    0x7C, 0xC6, 0xC6, 0x7E, 0x06, 0x0C, 0x78, 0x00, // '9'
    0x00, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x00, // ':'
    0x00, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x30, // ';'
    0x0C, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0C, 0x00, // '<'
    0x00, 0x00, 0x7E, 0x00, 0x00, 0x7E, 0x00, 0x00, // '='
    0x30, 0x18, 0x0C, 0x06, 0x0C, 0x18, 0x30, 0x00, // '>'
    0x3C, 0x66, 0x06, 0x0C, 0x18, 0x00, 0x18, 0x00, // '?'
    0x7C, 0xC6, 0xDE, 0xDE, 0xDE, 0xC0, 0x7C, 0x00, // '@'
    0x38, 0x6C, 0xC6, 0xC6, 0xFE, 0xC6, 0xC6, 0x00, // 'A'
    0xFC, 0x6E, 0x66, 0x7C, 0x66, 0x6E, 0xFC, 0x00, // 'B'
    0x3E, 0x62, 0xC0, 0xC0, 0xC0, 0x62, 0x3E, 0x00, // 'C'
    0xF8, 0x6E, 0x66, 0x66, 0x66, 0x6E, 0xF8, 0x00, // 'D'
    0xFE, 0x62, 0x60, 0x78, 0x60, 0x62, 0xFE, 0x00, // 'E'
    0xFE, 0x62, 0x60, 0x78, 0x60, 0x60, 0xF0, 0x00, // 'F'
    0x3E, 0x62, 0xC0, 0xC0, 0xCE, 0x66, 0x3E, 0x00, // 'G'
    0xC6, 0xC6, 0xC6, 0xFE, 0xC6, 0xC6, 0xC6, 0x00, // 'H'
    0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00, // 'I'
    0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0xCC, 0x78, 0x00, // 'J'
    0xE6, 0x66, 0x6C, 0x78, 0x78, 0x6C, 0xE6, 0x00, // 'K'
    0xF0, 0x60, 0x60, 0x60, 0x60, 0x66, 0xFE, 0x00, // 'L'
    0xC6, 0xEE, 0xFE, 0xD6, 0xC6, 0xC6, 0xC6, 0x00, // 'M'
    0xC6, 0xE6, 0xF6, 0xFE, 0xDE, 0xCE, 0xC6, 0x00, // 'N'
    0x7C, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6, 0x7C, 0x00, // 'O'
    0xFC, 0x66, 0x66, 0x7C, 0x60, 0x60, 0xE0, 0x00, // 'P'
    0x7C, 0xC6, 0xC6, 0xD6, 0xDE, 0x7C, 0x06, 0x00, // 'Q'
    0xFC, 0x66, 0x66, 0x7C, 0x78, 0x6C, 0xE6, 0x00, // 'R'
    0x7C, 0xC6, 0xE0, 0x38, 0x0E, 0xC6, 0x7C, 0x00, // 'S'
    0x7E, 0x5A, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00, // 'T'
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00, // 'U'
    0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x00, // 'V'
    0xC6, 0xC6, 0xC6, 0xD6, 0xFE, 0xFE, 0xC6, 0x00, // 'W'
    0xC6, 0x6C, 0x38, 0x38, 0x6C, 0xC6, 0xC6, 0x00, // 'X'
    0x66, 0x66, 0x66, 0x3C, 0x18, 0x18, 0x3C, 0x00, // 'Y'
    0xFE, 0xCC, 0x18, 0x30, 0x60, 0xC6, 0xFE, 0x00, // 'Z'
    0x3C, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3C, 0x00, // '['
    0x80, 0xC0, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x00, // '\'
    0x3C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x3C, 0x00, // ']'
    0x18, 0x3C, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, // '^'
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, // '_'
    0x18, 0x18, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, // '`'
    0x00, 0x00, 0x38, 0x0C, 0x7C, 0xCC, 0x76, 0x00, // 'a'
    0x60, 0x60, 0x60, 0x7C, 0x66, 0x66, 0xDC, 0x00, // 'b'
    0x00, 0x00, 0x7C, 0xC4, 0xC0, 0xC4, 0x7C, 0x00, // 'c'
    0x0C, 0x0C, 0x0C, 0x7C, 0xCC, 0xCC, 0x76, 0x00, // 'd'
    0x00, 0x00, 0x78, 0xCC, 0xFC, 0xC0, 0x7C, 0x00, // 'e'
    0x38, 0x6C, 0x60, 0xF8, 0x60, 0x60, 0xE0, 0x00, // 'f'
    0x00, 0x00, 0x76, 0xCC, 0xCC, 0x7C, 0x0C, 0x7C, // 'g'
    0xE0, 0x60, 0x60, 0x7C, 0x66, 0x66, 0x66, 0x00, // 'h'
    0x30, 0x00, 0x70, 0x30, 0x30, 0x30, 0x38, 0x00, // 'i'
    0x0C, 0x00, 0x1C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78, // 'j'
    0xE0, 0x60, 0x66, 0x6C, 0x78, 0x6C, 0x66, 0x00, // 'k'
    0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x00, // 'l'
    0x00, 0x00, 0xCC, 0xFE, 0xD6, 0xC6, 0xC6, 0x00, // 'm'
    0x00, 0x00, 0xDC, 0x66, 0x66, 0x66, 0x66, 0x00, // 'n'
    0x00, 0x00, 0x3C, 0x66, 0x66, 0x66, 0x3C, 0x00, // 'o'
    0x00, 0x00, 0xDC, 0x66, 0x66, 0x7C, 0x60, 0xE0, // 'p'
    0x00, 0x00, 0x76, 0xCC, 0xCC, 0x7C, 0x0C, 0x0E, // 'q'
    0x00, 0x00, 0xDC, 0x76, 0x60, 0x60, 0x60, 0x00, // 'r'
    0x00, 0x00, 0x78, 0xC0, 0x78, 0x0C, 0x78, 0x00, // 's'
    0x10, 0x30, 0x78, 0x30, 0x30, 0x34, 0x18, 0x00, // 't'
    0x00, 0x00, 0xCC, 0xCC, 0xCC, 0xCC, 0x76, 0x00, // 'u'
    0x00, 0x00, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x00, // 'v'
    0x00, 0x00, 0xC6, 0xC6, 0xD6, 0xFE, 0x6C, 0x00, // 'w'
    0x00, 0x00, 0xCC, 0x78, 0x30, 0x78, 0xCC, 0x00, // 'x'
    0x00, 0x00, 0xCC, 0xCC, 0xCC, 0x7C, 0x0C, 0x7C, // 'y'
    0x00, 0x00, 0xFC, 0x18, 0x30, 0x60, 0xFC, 0x00, // 'z'
    0x0E, 0x18, 0x18, 0x70, 0x18, 0x18, 0x0E, 0x00, // '{'
    0x30, 0x30, 0x30, 0x00, 0x30, 0x30, 0x30, 0x00, // '|'
    0x70, 0x18, 0x18, 0x0E, 0x18, 0x18, 0x70, 0x00, // '}'
    0x00, 0x76, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, // '~'
    0x10, 0x38, 0x6C, 0xC6, 0xC6, 0xC6, 0xFE, 0x00, // '\x7F'
    // clang-format on
};
