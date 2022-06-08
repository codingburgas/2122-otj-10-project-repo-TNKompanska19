#pragma once
#include "pch.h"

namespace pm::consoleApp
{
	void computerFigure(int x, int y);
	void label(int x, int y);
	void button(int x, int y, int colour);
	void textInButton(int x, int y, std::string text, int colour);
	void border(int x, int y, int n);
	bool mainMenu();
}