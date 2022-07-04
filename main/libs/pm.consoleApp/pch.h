// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>


#include "..\pm.tools\extraFunctions.h"
#include "..\pm.dal\UserStore.h"
#include "mainMenu.h"
#include "registrationForm.h"
#include "userView.h"
#include "adminView.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13
#define ESCAPE 27
#define CTRL_KEYPRESS(k) ((k)  & 0x1f) 

using namespace std;
#endif //PCH_H
