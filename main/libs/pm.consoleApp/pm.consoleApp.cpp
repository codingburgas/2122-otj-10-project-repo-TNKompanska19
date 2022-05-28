#include "pch.h"
#include "mainMenu.h"

#include "..\pm.tools\extraFunctions.h"
namespace pm::consoleApp
{
	void computerFigure(int x, int y)
	{
		pm::tools::consoleCoordinates(x, y);
		cout << "     ____________________________\n";
		pm::tools::consoleCoordinates(x, y + 1);
		cout << "    !\\_________________________/!\\\n";
		pm::tools::consoleCoordinates(x, y + 2);
		cout << "    !!                         !! \\\n";
		pm::tools::consoleCoordinates(x, y + 3);
		cout << "    !!                         !!  \\\n";
		pm::tools::consoleCoordinates(x, y + 4);
		cout << "    !!                         !!  !\n";
		pm::tools::consoleCoordinates(x, y + 5);
		cout << "    !!                         !!  !\n";
		pm::tools::consoleCoordinates(x, y + 6);
		cout << "    !!                         !!  !\n";
		pm::tools::consoleCoordinates(x, y + 7);
		cout << "    !!                         !!  !\n";
		pm::tools::consoleCoordinates(x, y + 8);
		cout << "    !!                         !!  !\n";
		pm::tools::consoleCoordinates(x, y + 9);
		cout << "    !!                         !!  /\n";
		pm::tools::consoleCoordinates(x, y + 10);
		cout << "    !!_________________________!! /\n";
		pm::tools::consoleCoordinates(x, y + 11);
		cout << "    !/_________________________\\!/\n";
		pm::tools::consoleCoordinates(x, y + 12);
		cout << "       __\\_________________/__/!_\n";
		pm::tools::consoleCoordinates(x, y + 13);
		cout << "      !_______________________!/\n";
		pm::tools::consoleCoordinates(x, y + 14);
		cout << "    ________________________\n";
		pm::tools::consoleCoordinates(x, y + 15);
		cout << "   /oooo  oooo  oooo  oooo /!\n";
		pm::tools::consoleCoordinates(x, y + 16);
		cout << "  /ooooooooooooooooooooooo/ /\n";
		pm::tools::consoleCoordinates(x, y + 17);
		cout << " /ooooooooooooooooooooooo/ /\n";
		pm::tools::consoleCoordinates(x, y + 18);
		cout << "/C=_____________________/_/\n";
	}

	void label(int x, int y)
	{
		pm::tools::consoleCoordinates(x, y);
		cout << "  _____           _                                 ";
		pm::tools::consoleCoordinates(x, y+1);
		cout << " |  __ \\         | |                                ";
		pm::tools::consoleCoordinates(x, y+2);
		cout << " | |__) | __ ___ | |_ ___  __ _ _ __ ___   ___ _ __ ";
		pm::tools::consoleCoordinates(x, y+3);
		cout << " |  ___/ '__/ _ \\| __/ _ \\/ _` | '_ ` _ \\ / _ \\ '__|";
		pm::tools::consoleCoordinates(x, y+4);
		cout << " | |   | | | (_) | ||  __/ (_| | | | | | |  __/ |  ";
		pm::tools::consoleCoordinates(x, y+5);
		cout << " |_|   |_|  \\___/ \\__\\___|\\__,_|_| |_| |_|\\___|_|";
	}

	void button(int x, int y)
	{
		pm::tools::consoleCoordinates(x, y);
		cout << "  ___________________";
		pm::tools::consoleCoordinates(x, y+1);
		cout << " /                   \\";
		pm::tools::consoleCoordinates(x, y+2);
		cout << "|                     | ";
		pm::tools::consoleCoordinates(x, y+3);
		cout << " \\___________________/";
	}

	void textInButton(int x, int y, string text)
	{
		pm::tools::consoleCoordinates(x, y);
		cout << text;
	}
	void border(int x, int y, int n)
	{
		for (int i = 0; i < n; i++)
		{
			pm::tools::consoleCoordinates(x, y);
			cout << "(*)";
			y++;
		}
	}

	void teamFigure(int x, int y)
	{
		pm::tools::consoleCoordinates(x, y);
		cout << "                @@@@    @@@@@@@    @@@@";
		pm::tools::consoleCoordinates(x, y+1);
		cout << "               @@@@@@  @@@@@@@@@  @@@@@@";
		pm::tools::consoleCoordinates(x, y+2);
		cout << "               @@@@@@#  @@@@@@@  @@@@@@@";
		pm::tools::consoleCoordinates(x, y+3);
		cout << "                 %@                 @#";
		pm::tools::consoleCoordinates(x, y+4);
		cout << "             @@@@@@@@ @@@@@@@@@@@ @@@@@@@@";
		pm::tools::consoleCoordinates(x, y+5);
		cout << "             @@@@@@@.@@@@@@@@@@@@@ @@@@@@@";
		pm::tools::consoleCoordinates(x, y+6);
		cout << "            @@ @@@@@@@@@@@@@@@@@@@@@@@@@ @@";
		pm::tools::consoleCoordinates(x, y+7);
		cout << "           @@  @@@@ @@ @@@@@@@@@ @@ @@@@  @@";
		pm::tools::consoleCoordinates(x, y+8);
		cout << "           @@  @&@ @@  @@@@@@@@@  @@ @@@  @@";
		pm::tools::consoleCoordinates(x, y+9);
		cout << "          @@   @@@@@@@ @@@@@@@@@ @@@@@@@   @@";
		pm::tools::consoleCoordinates(x, y+10);
		cout << "               @@   @@ @@@@@@@@@ @@   @@";
		pm::tools::consoleCoordinates(x, y+11);
		cout << "               @@  @@@ @@@@ @@@@ @@@  @@";
		pm::tools::consoleCoordinates(x, y+12);
		cout << "               @@  @@@ @@@@ @@@@ @@@  @@";
		pm::tools::consoleCoordinates(x, y+13);
		cout << "               @@  @@@ @@@@ @@@@ @@@  @@";
		pm::tools::consoleCoordinates(x, y+14);
		cout << "               @@  @@@ @@@@ @@@@ @@@  @@";
		pm::tools::consoleCoordinates(x, y+15);
		cout << "               @&   @  @@@@ @@@@  @   @&";
		pm::tools::consoleCoordinates(x, y+16);
		cout << "                       @@@@ @@@@";
	}
	void mainMenu()
	{
		teamFigure(0, 33);
		border(4, 0, 60);
		label(13, 0);
		button(43, 9);
		button(43, 14);
		button(43, 19);
		button(43, 24);
		textInButton(51, 11, "Log in");
		textInButton(48, 16, "Registration");
		textInButton(47, 21, "Change password");
		textInButton(52, 26, "Exit");
		computerFigure(68, 30);
	}
}


