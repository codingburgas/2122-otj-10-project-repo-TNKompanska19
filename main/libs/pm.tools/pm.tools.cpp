#include "pch.h"
#include "extraFunctions.h"

namespace pm::tools
{
    void consoleCoordinates(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
}
