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

define_dummy_symbol(mmdyna_bndtmpl2);

#include "bndtmpl2.h"

bool EdgeInList(i32 arg1, i32 arg2, i32 arg3, i32* arg4, i32* arg5)
{
    return stub<cdecl_t<bool, i32, i32, i32, i32*, i32*>>(0x117620_Offset, arg1, arg2, arg3, arg4, arg5);
}
