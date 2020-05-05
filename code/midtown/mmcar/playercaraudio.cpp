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

define_dummy_symbol(mmcar_playercaraudio);

#include "playercaraudio.h"

mmPlayerCarAudio::mmPlayerCarAudio()
{
    unimplemented();
}

mmPlayerCarAudio::mmPlayerCarAudio(class mmCarSim* arg1)
{
    unimplemented(arg1);
}

mmPlayerCarAudio::~mmPlayerCarAudio()
{
    unimplemented(arg1);
}

void mmPlayerCarAudio::EchoOff()
{
    return stub<thiscall_t<void, mmPlayerCarAudio*>>(0x82140_Offset, this);
}

void mmPlayerCarAudio::EchoOn(f32 arg1)
{
    return stub<thiscall_t<void, mmPlayerCarAudio*, f32>>(0x82020_Offset, this, arg1);
}

void mmPlayerCarAudio::FluctuateFastSiren()
{
    return stub<thiscall_t<void, mmPlayerCarAudio*>>(0x82730_Offset, this);
}

void mmPlayerCarAudio::FluctuateSlowSiren()
{
    return stub<thiscall_t<void, mmPlayerCarAudio*>>(0x82530_Offset, this);
}

class MetaClass* mmPlayerCarAudio::GetClass()
{
    return stub<thiscall_t<class MetaClass*, mmPlayerCarAudio*>>(0x83260_Offset, this);
}

void mmPlayerCarAudio::Init(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmPlayerCarAudio*, class mmCarSim*>>(0x81BA0_Offset, this, arg1);
}

void mmPlayerCarAudio::LoadSucessful()
{
    return stub<thiscall_t<void, mmPlayerCarAudio*>>(0x82C20_Offset, this);
}

void mmPlayerCarAudio::PlayHorn()
{
    return stub<thiscall_t<void, mmPlayerCarAudio*>>(0x82A90_Offset, this);
}

void mmPlayerCarAudio::PlayReverseBeep()
{
    return stub<thiscall_t<void, mmPlayerCarAudio*>>(0x821F0_Offset, this);
}

void mmPlayerCarAudio::Reset()
{
    return stub<thiscall_t<void, mmPlayerCarAudio*>>(0x82A50_Offset, this);
}

void mmPlayerCarAudio::SetUpDefault(class mmCarSim* arg1)
{
    return stub<thiscall_t<void, mmPlayerCarAudio*, class mmCarSim*>>(0x82AD0_Offset, this, arg1);
}

void mmPlayerCarAudio::StartSiren()
{
    return stub<thiscall_t<void, mmPlayerCarAudio*>>(0x82460_Offset, this);
}

void mmPlayerCarAudio::StopSiren()
{
    return stub<thiscall_t<void, mmPlayerCarAudio*>>(0x824F0_Offset, this);
}

void mmPlayerCarAudio::Update(i32 arg1, f32 arg2, f32 arg3, i16 arg4)
{
    return stub<thiscall_t<void, mmPlayerCarAudio*, i32, f32, f32, i16>>(0x82250_Offset, this, arg1, arg2, arg3, arg4);
}

void mmPlayerCarAudio::DeclareFields()
{
    return stub<cdecl_t<void>>(0x83080_Offset);
}
