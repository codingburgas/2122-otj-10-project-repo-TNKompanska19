#pragma once
#include "pch.h"

namespace pm::consoleApp
{
	void computerFigure(int x, int y);
	void label(int x, int y);
	void button(int x, int y);
	void textInButton(int x, int y, std::string text);
	void border(int x, int y, int n);
	void mainMenu();
}