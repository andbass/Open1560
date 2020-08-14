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

define_dummy_symbol(mmui_graphics);

#include "graphics.h"

#include "agiworld/quality.h"
#include "mmcityinfo/state.h"
#include "pcwindis/setupdata.h"

// 0x49A050 | ?SetTexQualString@@YAXXZ
ARTS_IMPORT /*static*/ void SetTexQualString();

static extern_var(0x705804, i32, MaxTextureQuality);
static extern_var(0x7057E8, f32, LightQualityOption);

void AutoDetect(i32 renderer, i32 resolution)
{
    if (renderer == -1)
        renderer = dxiRendererChoice;

    dxiRendererInfo_t& info = dxiInfo[renderer];

    if (resolution == -1)
        resolution = info.ResChoice;

    dxiResolution& res = info.Resolutions[resolution];

    if (info.Type == 2)
        agiRQ.TerrainQuality = AGI_QUALITY_VERY_HIGH;
    else if (info.Type != 0)
        agiRQ.TerrainQuality = AGI_QUALITY_HIGH;
    else
        agiRQ.TerrainQuality = AGI_QUALITY_MEDIUM;

    if (info.Type != 0)
    {
        if (res.uTexMem > 0x2000000) // 32 MB
            agiRQ.TextureQuality = AGI_QUALITY_VERY_HIGH;
        else if (res.uTexMem > 0x400000) // 4 MB
            agiRQ.TextureQuality = AGI_QUALITY_HIGH;
        else if (res.uTexMem > 0x100000) // 1 MB
            agiRQ.TextureQuality = AGI_QUALITY_MEDIUM;
        else
            agiRQ.TextureQuality = AGI_QUALITY_LOW;

        if (info.SpecialFlags & 0x2)
            agiRQ.TextureQuality = AGI_QUALITY_LOW;
    }
    else
    {
        agiRQ.TextureQuality = (res.uWidth >= 512) ? 2 : 1;
    }

    MaxTextureQuality = 3;

    MMSTATE.EnablePaging = false;

    agiRQ.TexturedSky = true;
    agiRQ.Shadow = AGI_QUALITY_VERY_HIGH;
    agiRQ.FarClip = 1000.0;

    agiRQ.LightQuality = 3;
    LightQualityOption = static_cast<f32>(agiRQ.LightQuality);

    agiRQ.EnvMap = info.SmoothAlpha && !(info.SpecialFlags & 0x2);
    agiRQ.SphMap = info.AdditiveBlending;

    MMSTATE.DisablePeds = false;
}
