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

define_dummy_symbol(mminput_joyman);

#include "joyman.h"

i32 __stdcall inputEnumDeviceProc(struct DIDEVICEINSTANCEA* arg1, void* arg2)
{
    return stub<stdcall_t<i32, struct DIDEVICEINSTANCEA*, void*>>(0xE5A60_Offset, arg1, arg2);
}

mmJoyMan::mmJoyMan()
{
    unimplemented();
}

mmJoyMan::~mmJoyMan()
{
    unimplemented();
}

i32 mmJoyMan::ButtonToBit(i32 arg1)
{
    return stub<thiscall_t<i32, mmJoyMan*, i32>>(0xE5C40_Offset, this, arg1);
}

i32 mmJoyMan::FFIsPlaying(i32 arg1)
{
    return stub<thiscall_t<i32, mmJoyMan*, i32>>(0xE5F50_Offset, this, arg1);
}

i32 mmJoyMan::FFPlay(i32 arg1)
{
    return stub<thiscall_t<i32, mmJoyMan*, i32>>(0xE5EF0_Offset, this, arg1);
}

i32 mmJoyMan::FFSetValues(i32 arg1, f32 arg2, f32 arg3)
{
    return stub<thiscall_t<i32, mmJoyMan*, i32, f32, f32>>(0xE5F80_Offset, this, arg1, arg2, arg3);
}

i32 mmJoyMan::FFStop(i32 arg1)
{
    return stub<thiscall_t<i32, mmJoyMan*, i32>>(0xE5F20_Offset, this, arg1);
}

class mmEffectFF* mmJoyMan::GetFFEffect(i32 arg1)
{
    return stub<thiscall_t<class mmEffectFF*, mmJoyMan*, i32>>(0xE5E80_Offset, this, arg1);
}

f32 mmJoyMan::GetJoyAxis(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<f32, mmJoyMan*, i32, i32>>(0xE5CB0_Offset, this, arg1, arg2);
}

i32 mmJoyMan::GetJoyButton(i32 arg1, i32 arg2)
{
    return stub<thiscall_t<i32, mmJoyMan*, i32, i32>>(0xE5CF0_Offset, this, arg1, arg2);
}

i32 mmJoyMan::GetOneButton(i32 arg1)
{
    return stub<thiscall_t<i32, mmJoyMan*, i32>>(0xE5E50_Offset, this, arg1);
}

i32 mmJoyMan::HasCoolie()
{
    return stub<thiscall_t<i32, mmJoyMan*>>(0xE5FE0_Offset, this);
}

i32 mmJoyMan::HasThrottle()
{
    return stub<thiscall_t<i32, mmJoyMan*>>(0xE6000_Offset, this);
}

i32 mmJoyMan::Init(struct HINSTANCE__* arg1, struct HWND__* arg2)
{
    return stub<thiscall_t<i32, mmJoyMan*, struct HINSTANCE__*, struct HWND__*>>(0xE5AE0_Offset, this, arg1, arg2);
}

i32 mmJoyMan::PollJoyAxes()
{
    return stub<thiscall_t<i32, mmJoyMan*>>(0xE5DA0_Offset, this);
}

i32 mmJoyMan::PollJoyButtons()
{
    return stub<thiscall_t<i32, mmJoyMan*>>(0xE5D40_Offset, this);
}

i32 mmJoyMan::QJoystick()
{
    return stub<thiscall_t<i32, mmJoyMan*>>(0xE5C70_Offset, this);
}

void mmJoyMan::SetCapture(i32 arg1)
{
    return stub<thiscall_t<void, mmJoyMan*, i32>>(0xE5DE0_Offset, this, arg1);
}

void mmJoyMan::StopAllFF()
{
    return stub<thiscall_t<void, mmJoyMan*>>(0xE5FC0_Offset, this);
}

i32 mmJoyMan::ToggleEnabled(i32 arg1)
{
    return stub<thiscall_t<i32, mmJoyMan*, i32>>(0xE5EB0_Offset, this, arg1);
}

void mmJoyMan::Update()
{
    return stub<thiscall_t<void, mmJoyMan*>>(0xE5C80_Offset, this);
}
