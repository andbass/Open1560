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

define_dummy_symbol(mmphysics_osample);

#include "osample.h"

asOverSample::asOverSample()
{
    unimplemented();
}

asOverSample::~asOverSample()
{
    unimplemented(arg1);
}

void asOverSample::AddWidgets(class Bank* arg1)
{
    return stub<thiscall_t<void, asOverSample*, class Bank*>>(0xDEE30_Offset, this, arg1);
}

class MetaClass* asOverSample::GetClass()
{
    return stub<thiscall_t<class MetaClass*, asOverSample*>>(0xDF060_Offset, this);
}

void asOverSample::RealTime(f32 arg1)
{
    return stub<thiscall_t<void, asOverSample*, f32>>(0xDED50_Offset, this, arg1);
}

void asOverSample::Update()
{
    return stub<thiscall_t<void, asOverSample*>>(0xDED70_Offset, this);
}

void asOverSample::DeclareFields()
{
    return stub<cdecl_t<void>>(0xDEEE0_Offset);
}
