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
    mmui:graphics

    0x499710 | void __cdecl AutoDetect(int,int) | ?AutoDetect@@YAXHH@Z
    0x499970 | public: __thiscall GraphicsOptions::GraphicsOptions(int) | ??0GraphicsOptions@@QAE@H@Z
    0x49A2F0 | public: virtual __thiscall GraphicsOptions::~GraphicsOptions(void) | ??1GraphicsOptions@@UAE@XZ
    0x49A350 | public: void __thiscall GraphicsOptions::SetResolution(void) | ?SetResolution@GraphicsOptions@@QAEXXZ
    0x49A370 | public: void __thiscall GraphicsOptions::SetLightQuality(void) | ?SetLightQuality@GraphicsOptions@@QAEXXZ
    0x49A390 | public: void __thiscall GraphicsOptions::SetRenderer(void) | ?SetRenderer@GraphicsOptions@@QAEXXZ
    0x49A5A0 | public: virtual void __thiscall GraphicsOptions::PreSetup(void) | ?PreSetup@GraphicsOptions@@UAEXXZ
    0x49A5C0 | public: virtual void __thiscall GraphicsOptions::ResetDefaultAction(void) | ?ResetDefaultAction@GraphicsOptions@@UAEXXZ
    0x49A610 | public: virtual void __thiscall GraphicsOptions::CancelAction(void) | ?CancelAction@GraphicsOptions@@UAEXXZ
    0x49A640 | public: virtual void __thiscall GraphicsOptions::DoneAction(void) | ?DoneAction@GraphicsOptions@@UAEXXZ
    0x49A6A0 | public: virtual void * __thiscall GraphicsOptions::`vector deleting destructor'(unsigned int) | ??_EGraphicsOptions@@UAEPAXI@Z
    0x49A6A0 | public: virtual void * __thiscall GraphicsOptions::`scalar deleting destructor'(unsigned int) | ??_GGraphicsOptions@@UAEPAXI@Z
    0x49A6D0 | public: virtual void __thiscall OptionsBase::StoreCurrentSetup(void) | ?StoreCurrentSetup@OptionsBase@@UAEXXZ
    0x49A6E0 | public: virtual int __thiscall OptionsBase::IsAnOptionMenu(void) | ?IsAnOptionMenu@OptionsBase@@UAEHXZ
    0x49A6F0 | public: void __thiscall string::Init(int) | ?Init@string@@QAEXH@Z
    0x49A730 | public: __thiscall string::string(class string const &) | ??0string@@QAE@ABV0@@Z
    0x61D370 | const GraphicsOptions::`vftable' | ??_7GraphicsOptions@@6B@
    0x7057EC | int data1 | ?data1@@3HA
    0x7057F0 | int data2 | ?data2@@3HA
    0x7057F4 | int data3 | ?data3@@3HA
    0x7057F8 | int data4 | ?data4@@3HA
    0x7057FC | int data5 | ?data5@@3HA
    0x705800 | int data6 | ?data6@@3HA
    0x705820 | int RenderToSystemMemory | ?RenderToSystemMemory@@3HA
    0x705824 | int TextureLevel | ?TextureLevel@@3HA
*/

#include "optionsbase.h"

// 0x499710 | ?AutoDetect@@YAXHH@Z
void AutoDetect(i32 arg1, i32 arg2);

// 0x705820 | ?RenderToSystemMemory@@3HA
inline extern_var(0x305820_Offset, i32, RenderToSystemMemory);

// 0x705824 | ?TextureLevel@@3HA
inline extern_var(0x305824_Offset, i32, TextureLevel);

// 0x7057EC | ?data1@@3HA
inline extern_var(0x3057EC_Offset, i32, data1);

// 0x7057F0 | ?data2@@3HA
inline extern_var(0x3057F0_Offset, i32, data2);

// 0x7057F4 | ?data3@@3HA
inline extern_var(0x3057F4_Offset, i32, data3);

// 0x7057F8 | ?data4@@3HA
inline extern_var(0x3057F8_Offset, i32, data4);

// 0x7057FC | ?data5@@3HA
inline extern_var(0x3057FC_Offset, i32, data5);

// 0x705800 | ?data6@@3HA
inline extern_var(0x305800_Offset, i32, data6);

class GraphicsOptions : public OptionsBase
{
    // const GraphicsOptions::`vftable' @ 0x61D370

public:
    // 0x499970 | ??0GraphicsOptions@@QAE@H@Z
    GraphicsOptions(i32 arg1);

    // 0x49A6A0 | ??_GGraphicsOptions@@UAEPAXI@Z
    // 0x49A2F0 | ??1GraphicsOptions@@UAE@XZ
    ~GraphicsOptions() override;

    // 0x49A610 | ?CancelAction@GraphicsOptions@@UAEXXZ
    void CancelAction() override;

    // 0x49A640 | ?DoneAction@GraphicsOptions@@UAEXXZ
    void DoneAction() override;

    // 0x49A5A0 | ?PreSetup@GraphicsOptions@@UAEXXZ
    void PreSetup() override;

    // 0x49A5C0 | ?ResetDefaultAction@GraphicsOptions@@UAEXXZ
    void ResetDefaultAction() override;

    // 0x49A370 | ?SetLightQuality@GraphicsOptions@@QAEXXZ
    void SetLightQuality();

    // 0x49A390 | ?SetRenderer@GraphicsOptions@@QAEXXZ
    void SetRenderer();

    // 0x49A350 | ?SetResolution@GraphicsOptions@@QAEXXZ
    void SetResolution();
};

check_size(GraphicsOptions, 0x6EE8);
