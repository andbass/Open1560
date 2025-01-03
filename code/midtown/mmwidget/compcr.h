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
    mmwidget:compcr

    0x4B7310 | public: __thiscall mmCompCRPlayer::mmCompCRPlayer(void) | ??0mmCompCRPlayer@@QAE@XZ
    0x4B7340 | public: virtual __thiscall mmCompCRPlayer::~mmCompCRPlayer(void) | ??1mmCompCRPlayer@@UAE@XZ
    0x4B73D0 | public: void __thiscall mmCompCRPlayer::Init(char *,int,char *,int,int) | ?Init@mmCompCRPlayer@@QAEXPADH0HH@Z
    0x4B7500 | public: void __thiscall mmCompCRPlayer::InitTitle(float,float,float,float,struct LocString *,struct LocString *,struct LocString *,struct LocString *,int) | ?InitTitle@mmCompCRPlayer@@QAEXMMMMPAULocString@@000H@Z
    0x4B7510 | public: void __thiscall mmCompCRPlayer::LoadBitmap(char *) | ?LoadBitmap@mmCompCRPlayer@@QAEXPAD@Z
    0x4B7570 | public: virtual void __thiscall mmCompCRPlayer::Reset(void) | ?Reset@mmCompCRPlayer@@UAEXXZ
    0x4B7580 | public: virtual void __thiscall mmCompCRPlayer::Update(void) | ?Update@mmCompCRPlayer@@UAEXXZ
    0x4B7590 | public: void __thiscall mmCompCRPlayer::SetPoints(int) | ?SetPoints@mmCompCRPlayer@@QAEXH@Z
    0x4B75B0 | public: void __thiscall mmCompCRPlayer::SetSubwidgetGeometry(void) | ?SetSubwidgetGeometry@mmCompCRPlayer@@QAEXXZ
    0x4B76B0 | public: virtual void __thiscall mmCompCRPlayer::SetPosition(class mmTextNode *,int,float) | ?SetPosition@mmCompCRPlayer@@UAEXPAVmmTextNode@@HM@Z
    0x4B7740 | public: virtual void __thiscall mmCompCRPlayer::SetGeometry(float,float,float,float) | ?SetGeometry@mmCompCRPlayer@@UAEXMMMM@Z
    0x4B7770 | public: virtual void __thiscall mmCompCRPlayer::Cull(void) | ?Cull@mmCompCRPlayer@@UAEXXZ
    0x4B7810 | public: virtual void * __thiscall mmCompCRPlayer::`scalar deleting destructor'(unsigned int) | ??_GmmCompCRPlayer@@UAEPAXI@Z
    0x4B7810 | public: virtual void * __thiscall mmCompCRPlayer::`vector deleting destructor'(unsigned int) | ??_EmmCompCRPlayer@@UAEPAXI@Z
    0x61E8F8 | const mmCompCRPlayer::`vftable' | ??_7mmCompCRPlayer@@6B@
*/

#include "compbase.h"

class mmCompCRPlayer final : public mmCompBase
{
public:
    // ??0mmCompCRPlayer@@QAE@XZ
    ARTS_IMPORT mmCompCRPlayer();

    // ??_EmmCompCRPlayer@@UAEPAXI@Z
    // ??_GmmCompCRPlayer@@UAEPAXI@Z
    // ??1mmCompCRPlayer@@UAE@XZ
    ARTS_IMPORT ~mmCompCRPlayer() override;

    // ?Cull@mmCompCRPlayer@@UAEXXZ
    ARTS_IMPORT void Cull() override;

    // ?Init@mmCompCRPlayer@@QAEXPADH0HH@Z
    ARTS_IMPORT void Init(char* arg1, i32 arg2, char* arg3, i32 arg4, i32 arg5);

    // ?InitTitle@mmCompCRPlayer@@QAEXMMMMPAULocString@@000H@Z | unused
    ARTS_EXPORT void InitTitle(f32 arg1, f32 arg2, f32 arg3, f32 arg4, LocString* arg5, LocString* arg6,
        LocString* arg7, LocString* arg8, i32 arg9);

    // ?LoadBitmap@mmCompCRPlayer@@QAEXPAD@Z | unused
    ARTS_IMPORT void LoadBitmap(char* arg1);

    // ?Reset@mmCompCRPlayer@@UAEXXZ
    ARTS_IMPORT void Reset() override;

    // ?SetGeometry@mmCompCRPlayer@@UAEXMMMM@Z
    ARTS_IMPORT void SetGeometry(f32 arg1, f32 arg2, f32 arg3, f32 arg4) override;

    // ?SetPoints@mmCompCRPlayer@@QAEXH@Z
    ARTS_IMPORT void SetPoints(i32 arg1);

    // ?SetPosition@mmCompCRPlayer@@UAEXPAVmmTextNode@@HM@Z
    ARTS_IMPORT void SetPosition(mmTextNode* arg1, i32 arg2, f32 arg3) override;

    // ?SetSubwidgetGeometry@mmCompCRPlayer@@QAEXXZ
    ARTS_IMPORT void SetSubwidgetGeometry();

    // ?Update@mmCompCRPlayer@@UAEXXZ
    ARTS_IMPORT void Update() override;

    u8 gap48[0x50];
};

check_size(mmCompCRPlayer, 0x98);
