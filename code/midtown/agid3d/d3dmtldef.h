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

#pragma once

/*
    agid3d:d3dmtldef

    0x533560 | public: __thiscall agiD3DMtlDef::agiD3DMtlDef(class agiPipeline *) | ??0agiD3DMtlDef@@QAE@PAVagiPipeline@@@Z
    0x533590 | public: virtual int __thiscall agiD3DMtlDef::BeginGfx(void) | ?BeginGfx@agiD3DMtlDef@@UAEHXZ
    0x533620 | public: virtual void __thiscall agiD3DMtlDef::EndGfx(void) | ?EndGfx@agiD3DMtlDef@@UAEXXZ
    0x533660 | public: virtual __thiscall agiD3DMtlDef::~agiD3DMtlDef(void) | ??1agiD3DMtlDef@@UAE@XZ
    0x533670 | public: void __thiscall agiD3DMtlDef::Activate(void) | ?Activate@agiD3DMtlDef@@QAEXXZ
    0x533750 | public: unsigned long __thiscall agiD3DMtlDef::GetHandle(void) | ?GetHandle@agiD3DMtlDef@@QAEKXZ
    0x533770 | public: virtual void * __thiscall agiD3DMtlDef::`vector deleting destructor'(unsigned int) | ??_EagiD3DMtlDef@@UAEPAXI@Z
    0x533770 | public: virtual void * __thiscall agiD3DMtlDef::`scalar deleting destructor'(unsigned int) | ??_GagiD3DMtlDef@@UAEPAXI@Z
    0x621170 | const agiD3DMtlDef::`vftable' | ??_7agiD3DMtlDef@@6B@
*/

#include "agi/mtldef.h"

class agiD3DMtlDef : public agiMtlDef
{
    // const agiD3DMtlDef::`vftable' @ 0x621170

public:
    // 0x533560 | ??0agiD3DMtlDef@@QAE@PAVagiPipeline@@@Z
    agiD3DMtlDef(class agiPipeline* arg1);

    // 0x533770 | ??_GagiD3DMtlDef@@UAEPAXI@Z
    // 0x533660 | ??1agiD3DMtlDef@@UAE@XZ
    ~agiD3DMtlDef() override;

    // 0x533670 | ?Activate@agiD3DMtlDef@@QAEXXZ
    void Activate();

    // 0x533590 | ?BeginGfx@agiD3DMtlDef@@UAEHXZ
    i32 BeginGfx() override;

    // 0x533620 | ?EndGfx@agiD3DMtlDef@@UAEXXZ
    void EndGfx() override;

    // 0x533750 | ?GetHandle@agiD3DMtlDef@@QAEKXZ
    u32 GetHandle();
};

check_size(agiD3DMtlDef, 0x88);
