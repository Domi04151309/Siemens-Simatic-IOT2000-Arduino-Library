/*
 *IOT2000 - Library for the Siemens Simatic IOT2000
 *
 *Copyright 2018 Dominik Reichl
 *
 *Developed by Dominik Reichl
 *
 *This library is free software; you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation; either version 2 of the License, or
 *(at your option) any later version.
 *
 *This library is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this library; if not, write to the Free Software
 *Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *As a special exception, you may use this file as part of a free software
 *library without restriction.  Specifically, if other files instantiate
 *templates or use macros or inline functions from this file, or you compile
 *this file and link it with other files to produce an executable, this
 *file does not by itself cause the resulting executable to be covered by
 *the GNU General Public License.  This exception does not however
 *invalidate any other reasons why the executable file might be covered by
 *the GNU General Public License.
 */
 
#ifndef IOT2000_h
#define IOT2000_h

#define USER_LED 13

#define DI0 12
#define DI1 11
#define DI2 10
#define DI3 9
#define DI4 4
#define DQ0 8
#define DQ1 7
#define U0 A0
#define I0 A1
#define U1 A2
#define I1 A3

#include <EthernetClientIOT.h>
#include <getRequest.h>

extern void userLEDSketchRunning();
extern void activateUserButton();
extern bool readUserButton();

#endif