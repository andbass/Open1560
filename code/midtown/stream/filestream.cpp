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

define_dummy_symbol(stream_filestream);

#include "filestream.h"

FileStream::FileStream(i32 arg1)
{
    unimplemented(arg1);
}

FileStream::FileStream(void* arg1, i32 arg2, class FileSystem* arg3)
{
    unimplemented(arg1, arg2, arg3);
}

FileStream::~FileStream()
{
    unimplemented(arg1);
}

i32 FileStream::Close()
{
    return stub<thiscall_t<i32, FileStream*>>(0x161A20_Offset, this);
}

i32 FileStream::Create(char* arg1)
{
    return stub<thiscall_t<i32, FileStream*, char*>>(0x161840_Offset, this, arg1);
}

u32 FileStream::GetPagerHandle()
{
    return stub<thiscall_t<u32, FileStream*>>(0x161830_Offset, this);
}

i32 FileStream::Open(char* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, FileStream*, char*, i32>>(0x161870_Offset, this, arg1, arg2);
}

i32 FileStream::RawRead(void* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, FileStream*, void*, i32>>(0x161970_Offset, this, arg1, arg2);
}

i32 FileStream::RawSeek(i32 arg1)
{
    return stub<thiscall_t<i32, FileStream*, i32>>(0x1619B0_Offset, this, arg1);
}

i32 FileStream::RawSize()
{
    return stub<thiscall_t<i32, FileStream*>>(0x1619F0_Offset, this);
}

i32 FileStream::RawTell()
{
    return stub<thiscall_t<i32, FileStream*>>(0x1619D0_Offset, this);
}

i32 FileStream::RawWrite(void* arg1, i32 arg2)
{
    return stub<thiscall_t<i32, FileStream*, void*, i32>>(0x161990_Offset, this, arg1, arg2);
}

i32 FileStream::Stderr()
{
    return stub<thiscall_t<i32, FileStream*>>(0x161950_Offset, this);
}

i32 FileStream::Stdin()
{
    return stub<thiscall_t<i32, FileStream*>>(0x161910_Offset, this);
}

i32 FileStream::Stdout()
{
    return stub<thiscall_t<i32, FileStream*>>(0x161930_Offset, this);
}
