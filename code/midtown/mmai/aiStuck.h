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
    mmai:aiStuck

    0x46B400 | public: __thiscall aiStuck::aiStuck(void) | ??0aiStuck@@QAE@XZ
    0x46B470 | void __cdecl StuckCB(class aiStuck *) | ?StuckCB@@YAXPAVaiStuck@@@Z
    0x46B4A0 | public: void __thiscall aiStuck::Init(class mmCarSim *) | ?Init@aiStuck@@QAEXPAVmmCarSim@@@Z
    0x46B4C0 | public: void __thiscall aiStuck::Impact(void) | ?Impact@aiStuck@@QAEXXZ
    0x46B4D0 | public: virtual void __thiscall aiStuck::Reset(void) | ?Reset@aiStuck@@UAEXXZ
    0x46B4E0 | public: int __thiscall aiStuck::Pegged(void) | ?Pegged@aiStuck@@QAEHXZ
    0x46B550 | public: virtual void __thiscall aiStuck::Update(void) | ?Update@aiStuck@@UAEXXZ
    0x46B770 | public: virtual void __thiscall aiStuck::AddWidgets(class Bank *) | ?AddWidgets@aiStuck@@UAEXPAVBank@@@Z
    0x46B8A0 | public: virtual void * __thiscall aiStuck::`vector deleting destructor'(unsigned int) | ??_EaiStuck@@UAEPAXI@Z
    0x46B8A0 | public: virtual void * __thiscall aiStuck::`scalar deleting destructor'(unsigned int) | ??_GaiStuck@@UAEPAXI@Z
    0x61BD60 | const aiStuck::`vftable' | ??_7aiStuck@@6B@
*/

#include "arts7/node.h"

class mmCarSim;

class aiStuck final : public asNode
{
public:
    // ??0aiStuck@@QAE@XZ
    ARTS_IMPORT aiStuck();

    // ??_GaiStuck@@UAEPAXI@Z
    // ??_EaiStuck@@UAEPAXI@Z
    // ??1aiStuck@@UAE@XZ | inline
    ARTS_IMPORT ~aiStuck() override = default;

#ifdef ARTS_DEV_BUILD
    // ?AddWidgets@aiStuck@@UAEXPAVBank@@@Z
    ARTS_IMPORT void AddWidgets(Bank* arg1) override;
#endif

    // ?Impact@aiStuck@@QAEXXZ | unused
    ARTS_IMPORT void Impact();

    // ?Init@aiStuck@@QAEXPAVmmCarSim@@@Z
    ARTS_IMPORT void Init(mmCarSim* arg1);

    // ?Pegged@aiStuck@@QAEHXZ
    ARTS_IMPORT i32 Pegged();

    // ?Reset@aiStuck@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?Update@aiStuck@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap20[0x38];
};

check_size(aiStuck, 0x58);
