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
#include <exception>
#include <windows.h>
#include <fstream>

#include "..\nanodbc\nanodbc.h"
#include "..\pm.consoleApp\mainMenu.h"
#include "..\pm.consoleApp\userView.h"
#include "..\pm.consoleApp\adminView.h"
#include "..\pm.tools\extraFunctions.h"

using namespace std;


#endif //PCH_H
