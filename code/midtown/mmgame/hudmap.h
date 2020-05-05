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
    mmgame:hudmap

    0x4280C0 | public: __thiscall mmHudMap::mmHudMap(void) | ??0mmHudMap@@QAE@XZ
    0x4281B0 | public: void __thiscall mmHudMap::Init(class asCamera *,class Matrix34 *,class mmHUD *,class mmGame *,char *) | ?Init@mmHudMap@@QAEXPAVasCamera@@PAVMatrix34@@PAVmmHUD@@PAVmmGame@@PAD@Z
    0x428750 | public: virtual void __thiscall mmHudMap::Reset(void) | ?Reset@mmHudMap@@UAEXXZ
    0x428790 | public: void __thiscall mmHudMap::RegisterOpponents(struct OppIconInfo *,int) | ?RegisterOpponents@mmHudMap@@QAEXPAUOppIconInfo@@H@Z
    0x4287B0 | public: void __thiscall mmHudMap::RegisterCopsnRobbers(class Vector3 * *) | ?RegisterCopsnRobbers@mmHudMap@@QAEXPAPAVVector3@@@Z
    0x4287E0 | public: void __thiscall mmHudMap::RegisterMisc(class Vector3 * *,int) | ?RegisterMisc@mmHudMap@@QAEXPAPAVVector3@@H@Z
    0x428810 | public: void __thiscall mmHudMap::Activate(void) | ?Activate@mmHudMap@@QAEXXZ
    0x428840 | public: void __thiscall mmHudMap::Deactivate(void) | ?Deactivate@mmHudMap@@QAEXXZ
    0x428870 | public: void __thiscall mmHudMap::SetMode(int) | ?SetMode@mmHudMap@@QAEXH@Z
    0x428B90 | public: void __thiscall mmHudMap::Cycle(void) | ?Cycle@mmHudMap@@QAEXXZ
    0x428BC0 | public: void __thiscall mmHudMap::ToggleFullScreen(void) | ?ToggleFullScreen@mmHudMap@@QAEXXZ
    0x428BF0 | private: class agiBitmap * __thiscall mmHudMap::GetCurrentMap(void) | ?GetCurrentMap@mmHudMap@@AAEPAVagiBitmap@@XZ
    0x428C00 | public: void __thiscall mmHudMap::ToggleMapRes(void) | ?ToggleMapRes@mmHudMap@@QAEXXZ
    0x428C60 | public: virtual void __thiscall mmHudMap::Update(void) | ?Update@mmHudMap@@UAEXXZ
    0x428E50 | public: virtual void __thiscall mmHudMap::Cull(void) | ?Cull@mmHudMap@@UAEXXZ
    0x428FE0 | private: void __thiscall mmHudMap::DrawCentered(class agiBitmap *,struct Point) | ?DrawCentered@mmHudMap@@AAEXPAVagiBitmap@@UPoint@@@Z
    0x429050 | private: void __thiscall mmHudMap::DrawClipped(class agiBitmap *,struct Point,float,float,float,float) | ?DrawClipped@mmHudMap@@AAEXPAVagiBitmap@@UPoint@@MMMM@Z
    0x4291F0 | private: void __thiscall mmHudMap::DrawOrientedBitmap(class Matrix34 *,class agiBitmap *) | ?DrawOrientedBitmap@mmHudMap@@AAEXPAVMatrix34@@PAVagiBitmap@@@Z
    0x4293D0 | public: void __thiscall mmHudMap::ResChanged(void) | ?ResChanged@mmHudMap@@QAEXXZ
    0x429410 | private: void __thiscall mmHudMap::DrawOriented(class Matrix34 *,unsigned int) | ?DrawOriented@mmHudMap@@AAEXPAVMatrix34@@I@Z
    0x4295F0 | private: void __thiscall mmHudMap::DrawOpponents(void) | ?DrawOpponents@mmHudMap@@AAEXXZ
    0x4296B0 | private: void __thiscall mmHudMap::DrawCops(void) | ?DrawCops@mmHudMap@@AAEXXZ
    0x429720 | private: void __thiscall mmHudMap::DrawWaypoints(void) | ?DrawWaypoints@mmHudMap@@AAEXXZ
    0x429860 | private: void __thiscall mmHudMap::DrawCopsnRobbers(void) | ?DrawCopsnRobbers@mmHudMap@@AAEXXZ
    0x429930 | public: void __thiscall mmHudMap::DrawMisc(void) | ?DrawMisc@mmHudMap@@QAEXXZ
    0x4299A0 | private: void __thiscall mmHudMap::FlushVerts(void) | ?FlushVerts@mmHudMap@@AAEXXZ
    0x429B20 | private: struct Point __thiscall mmHudMap::WorldToBitmap(class Vector3 *) | ?WorldToBitmap@mmHudMap@@AAE?AUPoint@@PAVVector3@@@Z
    0x429BC0 | private: int __thiscall mmHudMap::BitmapToScreen(struct Point *,struct Point) | ?BitmapToScreen@mmHudMap@@AAEHPAUPoint@@U2@@Z
    0x429C60 | public: virtual void __thiscall mmHudMap::AddWidgets(class Bank *) | ?AddWidgets@mmHudMap@@UAEXPAVBank@@@Z
    0x429DC0 | public: static void __cdecl mmHudMap::DeclareFields(void) | ?DeclareFields@mmHudMap@@SAXXZ
    0x429F30 | public: virtual class MetaClass * __thiscall mmHudMap::GetClass(void) | ?GetClass@mmHudMap@@UAEPAVMetaClass@@XZ
    0x429F70 | public: virtual void * __thiscall mmHudMap::`vector deleting destructor'(unsigned int) | ??_EmmHudMap@@UAEPAXI@Z
    0x429FD0 | public: virtual __thiscall mmHudMap::~mmHudMap(void) | ??1mmHudMap@@UAE@XZ
    0x429FE0 | [thunk]: __thiscall `vcall'{20,{flat}}' }' | ??_9@$BBE@AE
    0x61AE70 | const mmHudMap::`vftable' | ??_7mmHudMap@@6B@
    0x6A7350 | class MetaClass mmHudMapMetaClass | ?mmHudMapMetaClass@@3VMetaClass@@A
    0x6A7378 | union agiVtx * Tris | ?Tris@@3PATagiVtx@@A
*/

#include "arts7/node.h"

class mmHudMap : public asNode
{
    // const mmHudMap::`vftable' @ 0x61AE70

public:
    // 0x4280C0 | ??0mmHudMap@@QAE@XZ
    mmHudMap();

    // 0x429F70 | ??_EmmHudMap@@UAEPAXI@Z
    // 0x429FD0 | ??1mmHudMap@@UAE@XZ
    ~mmHudMap() override;

    // 0x428810 | ?Activate@mmHudMap@@QAEXXZ
    void Activate();

    // 0x429C60 | ?AddWidgets@mmHudMap@@UAEXPAVBank@@@Z
    void AddWidgets(class Bank* arg1) override;

    // 0x428E50 | ?Cull@mmHudMap@@UAEXXZ
    void Cull() override;

    // 0x428B90 | ?Cycle@mmHudMap@@QAEXXZ
    void Cycle();

    // 0x428840 | ?Deactivate@mmHudMap@@QAEXXZ
    void Deactivate();

    // 0x429930 | ?DrawMisc@mmHudMap@@QAEXXZ
    void DrawMisc();

    // 0x429F30 | ?GetClass@mmHudMap@@UAEPAVMetaClass@@XZ
    class MetaClass* GetClass() override;

    // 0x4281B0 | ?Init@mmHudMap@@QAEXPAVasCamera@@PAVMatrix34@@PAVmmHUD@@PAVmmGame@@PAD@Z
    void Init(class asCamera* arg1, class Matrix34* arg2, class mmHUD* arg3, class mmGame* arg4, char* arg5);

    // 0x4287B0 | ?RegisterCopsnRobbers@mmHudMap@@QAEXPAPAVVector3@@@Z
    void RegisterCopsnRobbers(class Vector3** arg1);

    // 0x4287E0 | ?RegisterMisc@mmHudMap@@QAEXPAPAVVector3@@H@Z
    void RegisterMisc(class Vector3** arg1, i32 arg2);

    // 0x428790 | ?RegisterOpponents@mmHudMap@@QAEXPAUOppIconInfo@@H@Z
    void RegisterOpponents(struct OppIconInfo* arg1, i32 arg2);

    // 0x4293D0 | ?ResChanged@mmHudMap@@QAEXXZ
    void ResChanged();

    // 0x428750 | ?Reset@mmHudMap@@UAEXXZ
    void Reset() override;

    // 0x428870 | ?SetMode@mmHudMap@@QAEXH@Z
    void SetMode(i32 arg1);

    // 0x428BC0 | ?ToggleFullScreen@mmHudMap@@QAEXXZ
    void ToggleFullScreen();

    // 0x428C00 | ?ToggleMapRes@mmHudMap@@QAEXXZ
    void ToggleMapRes();

    // 0x428C60 | ?Update@mmHudMap@@UAEXXZ
    void Update() override;

    // 0x429DC0 | ?DeclareFields@mmHudMap@@SAXXZ
    static void DeclareFields();

private:
    // 0x429BC0 | ?BitmapToScreen@mmHudMap@@AAEHPAUPoint@@U2@@Z
    i32 BitmapToScreen(struct Point* arg1, struct Point arg2);

    // 0x428FE0 | ?DrawCentered@mmHudMap@@AAEXPAVagiBitmap@@UPoint@@@Z
    void DrawCentered(class agiBitmap* arg1, struct Point arg2);

    // 0x429050 | ?DrawClipped@mmHudMap@@AAEXPAVagiBitmap@@UPoint@@MMMM@Z
    void DrawClipped(class agiBitmap* arg1, struct Point arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

    // 0x4296B0 | ?DrawCops@mmHudMap@@AAEXXZ
    void DrawCops();

    // 0x429860 | ?DrawCopsnRobbers@mmHudMap@@AAEXXZ
    void DrawCopsnRobbers();

    // 0x4295F0 | ?DrawOpponents@mmHudMap@@AAEXXZ
    void DrawOpponents();

    // 0x429410 | ?DrawOriented@mmHudMap@@AAEXPAVMatrix34@@I@Z
    void DrawOriented(class Matrix34* arg1, u32 arg2);

    // 0x4291F0 | ?DrawOrientedBitmap@mmHudMap@@AAEXPAVMatrix34@@PAVagiBitmap@@@Z
    void DrawOrientedBitmap(class Matrix34* arg1, class agiBitmap* arg2);

    // 0x429720 | ?DrawWaypoints@mmHudMap@@AAEXXZ
    void DrawWaypoints();

    // 0x4299A0 | ?FlushVerts@mmHudMap@@AAEXXZ
    void FlushVerts();

    // 0x428BF0 | ?GetCurrentMap@mmHudMap@@AAEPAVagiBitmap@@XZ
    class agiBitmap* GetCurrentMap();

    // 0x429B20 | ?WorldToBitmap@mmHudMap@@AAE?AUPoint@@PAVVector3@@@Z
    struct Point WorldToBitmap(class Vector3* arg1);
};

check_size(mmHudMap, 0x2C8);

// 0x429FE0 | ??_9@$BBE@AE (Skipped: void)

// 0x6A7378 | ?Tris@@3PATagiVtx@@A
inline extern_var(0x2A7378_Offset, union agiVtx*, Tris);

// 0x6A7350 | ?mmHudMapMetaClass@@3VMetaClass@@A
inline extern_var(0x2A7350_Offset, class MetaClass, mmHudMapMetaClass);
