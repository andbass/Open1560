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
    mmwidget:tdwidget

    0x4BDF90 | public: __thiscall TextDropWidget::TextDropWidget(void) | ??0TextDropWidget@@QAE@XZ
    0x4BE040 | public: virtual __thiscall TextDropWidget::~TextDropWidget(void) | ??1TextDropWidget@@UAE@XZ
    0x4BE0B0 | public: void __thiscall TextDropWidget::Init(class asCamera *,void *,float,float,float,float,float,class string,int) | ?Init@TextDropWidget@@QAEXPAVasCamera@@PAXMMMMMVstring@@H@Z
    0x4BE1A0 | public: int __thiscall TextDropWidget::GetCount(void) | ?GetCount@TextDropWidget@@QAEHXZ
    0x4BE1B0 | public: void __thiscall TextDropWidget::SetString(class string) | ?SetString@TextDropWidget@@QAEXVstring@@@Z
    0x4BE270 | public: int __thiscall TextDropWidget::SetValue(int) | ?SetValue@TextDropWidget@@QAEHH@Z
    0x4BE310 | public: int __thiscall TextDropWidget::SetHighlight(int) | ?SetHighlight@TextDropWidget@@QAEHH@Z
    0x4BE380 | public: int __thiscall TextDropWidget::Inc(void) | ?Inc@TextDropWidget@@QAEHXZ
    0x4BE390 | public: int __thiscall TextDropWidget::Dec(void) | ?Dec@TextDropWidget@@QAEHXZ
    0x4BE3A0 | public: int __thiscall TextDropWidget::IncDrop(void) | ?IncDrop@TextDropWidget@@QAEHXZ
    0x4BE3D0 | public: int __thiscall TextDropWidget::DecDrop(void) | ?DecDrop@TextDropWidget@@QAEHXZ
    0x4BE400 | public: int __thiscall TextDropWidget::Capture(float,float) | ?Capture@TextDropWidget@@QAEHMM@Z
    0x4BE440 | public: void __thiscall TextDropWidget::Switch(int,class Vector4 &) | ?Switch@TextDropWidget@@QAEXHAAVVector4@@@Z
    0x4BE460 | public: virtual void __thiscall TextDropWidget::Update(void) | ?Update@TextDropWidget@@UAEXXZ
    0x4BE470 | public: int __thiscall TextDropWidget::IsActive(void) | ?IsActive@TextDropWidget@@QAEHXZ
    0x4BE480 | public: void __thiscall TextDropWidget::SetActive(int) | ?SetActive@TextDropWidget@@QAEXH@Z
    0x4BE490 | public: void __thiscall TextDropWidget::SetDisabledMask(long) | ?SetDisabledMask@TextDropWidget@@QAEXJ@Z
    0x4BE4B0 | public: long __thiscall TextDropWidget::GetDisabledMask(void) | ?GetDisabledMask@TextDropWidget@@QAEJXZ
    0x4BE4C0 | public: static void __cdecl TextDropWidget::DeclareFields(void) | ?DeclareFields@TextDropWidget@@SAXXZ
    0x4BE630 | public: virtual class MetaClass * __thiscall TextDropWidget::GetClass(void) | ?GetClass@TextDropWidget@@UAEPAVMetaClass@@XZ
    0x4BE640 | public: virtual void * __thiscall TextDropWidget::`vector deleting destructor'(unsigned int) | ??_ETextDropWidget@@UAEPAXI@Z
    0x61F0F8 | const TextDropWidget::`vftable' | ??_7TextDropWidget@@6B@
    0x705C78 | class MetaClass TextDropWidgetMetaClass | ?TextDropWidgetMetaClass@@3VMetaClass@@A
*/

#include "arts7/node.h"

class asCamera;

class TextDropWidget final : public asNode
{
public:
    // ??0TextDropWidget@@QAE@XZ
    ARTS_IMPORT TextDropWidget();

    // ??_ETextDropWidget@@UAEPAXI@Z
    // ??1TextDropWidget@@UAE@XZ
    ARTS_IMPORT ~TextDropWidget() override;

    // ?Capture@TextDropWidget@@QAEHMM@Z
    ARTS_IMPORT i32 Capture(f32 arg1, f32 arg2);

    // ?Dec@TextDropWidget@@QAEHXZ | unused
    ARTS_IMPORT i32 Dec();

    // ?DecDrop@TextDropWidget@@QAEHXZ
    ARTS_IMPORT i32 DecDrop();

    // ?GetClass@TextDropWidget@@UAEPAVMetaClass@@XZ
    ARTS_IMPORT MetaClass* GetClass() override;

    // ?GetCount@TextDropWidget@@QAEHXZ | unused
    ARTS_IMPORT i32 GetCount();

    // ?GetDisabledMask@TextDropWidget@@QAEJXZ
    ARTS_IMPORT ilong GetDisabledMask();

    // ?Inc@TextDropWidget@@QAEHXZ | unused
    ARTS_IMPORT i32 Inc();

    // ?IncDrop@TextDropWidget@@QAEHXZ
    ARTS_IMPORT i32 IncDrop();

    // ?Init@TextDropWidget@@QAEXPAVasCamera@@PAXMMMMMVstring@@H@Z
    ARTS_IMPORT void Init(
        asCamera* arg1, void* arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, string arg8, i32 arg9);

    // ?IsActive@TextDropWidget@@QAEHXZ
    ARTS_IMPORT i32 IsActive();

    // ?SetActive@TextDropWidget@@QAEXH@Z
    ARTS_IMPORT void SetActive(i32 arg1);

    // ?SetDisabledMask@TextDropWidget@@QAEXJ@Z
    ARTS_IMPORT void SetDisabledMask(ilong arg1);

    // ?SetHighlight@TextDropWidget@@QAEHH@Z
    ARTS_IMPORT i32 SetHighlight(i32 arg1);

    // ?SetString@TextDropWidget@@QAEXVstring@@@Z
    ARTS_IMPORT void SetString(string arg1);

    // ?SetValue@TextDropWidget@@QAEHH@Z
    ARTS_IMPORT i32 SetValue(i32 arg1);

    // ?Switch@TextDropWidget@@QAEXHAAVVector4@@@Z
    ARTS_IMPORT void Switch(i32 arg1, Vector4& arg2);

    // ?Update@TextDropWidget@@UAEXXZ
    ARTS_IMPORT void Update() override;

    // ?DeclareFields@TextDropWidget@@SAXXZ
    ARTS_IMPORT static void DeclareFields();

    u8 gap20[0x18];
};

check_size(TextDropWidget, 0x38);
