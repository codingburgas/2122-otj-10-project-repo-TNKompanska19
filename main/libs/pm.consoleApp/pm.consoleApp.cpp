#include "pch.h"
#include "mainMenu.h"


namespace pm::consoleApp
{
	void computerFigure(int x, int y)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		pm::tools::consoleCoordinates(x, y);
		cout << "  _____           _                                 ";
		pm::tools::consoleCoordinates(x, y+1);
		cout << " |  __ \\         | |                                ";
		pm::tools::consoleCoordinates(x, y+2);
		cout << " | |__) | __ ___ | |_ ___  __ _ _ __ ___   ___ _ __ ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		pm::tools::consoleCoordinates(x, y+3);
		cout << " |  ___/ '__/ _ \\| __/ _ \\/ _` | '_ ` _ \\ / _ \\ '__|";
		pm::tools::consoleCoordinates(x, y+4);
		cout << " | |   | | | (_) | ||  __/ (_| | | | | | |  __/ |  ";
		pm::tools::consoleCoordinates(x, y+5);
		cout << " |_|   |_|  \\___/ \\__\\___|\\__,_|_| |_| |_|\\___|_|";
	}

	void button(int x, int y, int colour)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
		pm::tools::consoleCoordinates(x, y);
		cout << "  ___________________";
		pm::tools::consoleCoordinates(x, y+1);
		cout << " /                   \\";
		pm::tools::consoleCoordinates(x, y+2);
		cout << "|                     | ";
		pm::tools::consoleCoordinates(x, y+3);
		cout << " \\___________________/";
	}

	void textInButton(int x, int y, string text, int colour)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
		pm::tools::consoleCoordinates(x, y);
		cout << text;
	}
	void border(int x, int y, int n)
	{
		
		for (int i = 0; i < n; i++)
		{
			pm::tools::consoleCoordinates(x, y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << "(*)";
			y++;
		}
	}

	void teamFigure(int x, int y)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		pm::tools::consoleCoordinates(x, y);
		cout << "      @@@@    @@@@@@@    @@@@";
		pm::tools::consoleCoordinates(x, y+1);
		cout << "     @@@@@@  @@@@@@@@@  @@@@@@";
		pm::tools::consoleCoordinates(x, y+2);
		cout << "     @@@@@@#  @@@@@@@  @@@@@@@";
		pm::tools::consoleCoordinates(x, y+3);
		cout << "       %@        @#       @#";
		pm::tools::consoleCoordinates(x, y+4);
		cout << "   @@@@@@@@ @@@@@@@@@@@ @@@@@@@@";
		pm::tools::consoleCoordinates(x, y+5);
		cout << "   @@@@@@@.@@@@@@@@@@@@@ @@@@@@@";
		pm::tools::consoleCoordinates(x, y+6);
		cout << "  @@ @@@@@@@@@@@@@@@@@@@@@@@@@ @@";
		pm::tools::consoleCoordinates(x, y+7);
		cout << " @@  @@@@ @@ @@@@@@@@@ @@ @@@@  @@";
		pm::tools::consoleCoordinates(x, y+8);
		cout << " @@  @&@ @@  @@@@@@@@@  @@ @@@  @@";
		pm::tools::consoleCoordinates(x, y+9);
		cout << "@@   @@@@@@@ @@@@@@@@@ @@@@@@@   @@";
		pm::tools::consoleCoordinates(x, y+10);
		cout << "     @@   @@ @@@@@@@@@ @@   @@";
		pm::tools::consoleCoordinates(x, y+11);
		cout << "     @@  @@@ @@@@ @@@@ @@@  @@";
		pm::tools::consoleCoordinates(x, y+12);
		cout << "     @@  @@@ @@@@ @@@@ @@@  @@";
		pm::tools::consoleCoordinates(x, y+13);
		cout << "     @@  @@@ @@@@ @@@@ @@@  @@";
		pm::tools::consoleCoordinates(x, y+14);
		cout << "     @@  @@@ @@@@ @@@@ @@@  @@";
		pm::tools::consoleCoordinates(x, y+15);
		cout << "     @&   @  @@@@ @@@@  @   @&";
		pm::tools::consoleCoordinates(x, y+16);
		cout << "             @@@@ @@@@";
	}

	void registration()
	{
		pm::tools::consoleCoordinates(45, 15);
		cout << "ENTER FIRST NAME:";
		pm::tools::consoleCoordinates(45, 16);
		string firstName;
		cin >> firstName;
		pm::tools::consoleCoordinates(45, 18);
		cout << "ENTER LAST NAME: ";
		pm::tools::consoleCoordinates(45, 19);
		string lastName;
		cin >> lastName;
		pm::tools::consoleCoordinates(45, 21);
		cout << "ENTER USERNAME: ";
		pm::tools::consoleCoordinates(45, 22);
		string username;
		cin >> username;
		pm::tools::consoleCoordinates(45, 24);
		cout << "ENTER PASSWORD: ";
		pm::tools::consoleCoordinates(45, 25);
		string pass;
		cin >> pass;

		pm::dal::insertUsersDB(username, firstName, lastName, pass);
		system("CLS");
		pm::consoleApp::mainMenu();
	}

	void login()
	{
		pm::tools::consoleCoordinates(45, 21);
		cout << "ENTER USERNAME: ";
		pm::tools::consoleCoordinates(45, 22);
		string username;
		cin >> username;
		pm::tools::consoleCoordinates(45, 24);
		cout << "ENTER PASSWORD: ";
		pm::tools::consoleCoordinates(45, 25);
		string pass;
		cin >> pass;

		pm::dal::checkUser(username, pass);
	}

	void userOptions(string username)
	{
		pm::tools::consoleCoordinates(45, 21);
		cout << "1 - MY PROJECTS ";
		pm::tools::consoleCoordinates(45, 23);
		cout << "2 - PROJECTS I'M IN ";
		pm::tools::consoleCoordinates(45, 25);
		cout << "3 - CREATE PROJECT ";
		pm::tools::consoleCoordinates(45, 28);
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("CLS");
			border(0, 0, 51);
			label(30, 1);
			border(107, 0, 51);
			pm::dal::showMyProjects(username);
		}break;
		case 2:
		{
			system("CLS");
			border(0, 0, 51);
			label(30, 1);
			border(107, 0, 51);
			pm::dal::showUserProjects(username);
		}break;
		case 3:
		{
			system("CLS");
			border(0, 0, 51);
			label(30, 1);
			border(107, 0, 51);
			pm::tools::consoleCoordinates(45, 15);
			cout << "ENTER PROJECT NAME:";
			pm::tools::consoleCoordinates(45, 16);
			string name;
			cin.ignore();
			getline(cin, name);
			pm::tools::consoleCoordinates(45, 18);
			cout << "ENTER PROJECT DESCRIPTION:";
			pm::tools::consoleCoordinates(45, 19);
			string description;
			getline(cin, description);
			pm::dal::insertProjectsDB(name, description, username);
			system("CLS");
			border(0, 0, 51);
			label(30, 1);
			border(107, 0, 51);
			userOptions(username);
		}
		}
		
	}
	bool mainMenu()
	{
		int counter = 1;

		border(0, 0, 51);
		teamFigure(10, 33);
		label(30, 1);
		button(43, 11, 8);
		button(43, 16, 7);
		button(43, 21, 7);
		button(43, 26, 7);
		textInButton(51, 13, "Log in", 8);
		textInButton(48, 18, "Registration", 7);
		textInButton(47, 23, "Change password", 7);
		textInButton(52, 28, "Exit", 7);
		computerFigure(68, 30);
		border(107, 0, 51);

		do
		{
			switch (_getch())
			{

			case KEY_UP:
			{
				switch (counter)
				{
				case 1:
				{
					system("CLS");
					border(0, 0, 51);
					teamFigure(10, 33);
					label(30, 1);
					button(43, 11, 8);
					button(43, 16, 7);
					button(43, 21, 7);
					button(43, 26, 7);
					textInButton(51, 13, "Log in", 8);
					textInButton(48, 18, "Registration", 7);
					textInButton(47, 23, "Change password", 7);
					textInButton(52, 28, "Exit", 7);
					computerFigure(68, 30);
					border(107, 0, 51);
					counter = 4;
				}break;
				case 2:
				{
					system("CLS");
					border(0, 0, 51);
					teamFigure(10, 33);
					label(30, 1);
					button(43, 11, 7);
					button(43, 16, 8);
					button(43, 21, 7);
					button(43, 26, 7);
					textInButton(51, 13, "Log in", 7);
					textInButton(48, 18, "Registration", 8);
					textInButton(47, 23, "Change password", 7);
					textInButton(52, 28, "Exit", 7);
					computerFigure(68, 30);
					border(107, 0, 51);
					counter = 1;
				}break;
				case 3:
				{
					system("CLS");
					border(0, 0, 51);
					teamFigure(10, 33);
					label(30, 1);
					button(43, 11, 7);
					button(43, 16, 7);
					button(43, 21, 8);
					button(43, 26, 7);
					textInButton(51, 13, "Log in", 7);
					textInButton(48, 18, "Registration", 7);
					textInButton(47, 23, "Change password", 8);
					textInButton(52, 28, "Exit", 7);
					computerFigure(68, 30);
					border(107, 0, 51);
					counter = 2;
				}break;
				case 4:
				{
					system("CLS");
					border(0, 0, 51);
					teamFigure(10, 33);
					label(30, 1);
					button(43, 11, 7);
					button(43, 16, 7);
					button(43, 21, 7);
					button(43, 26, 8);
					textInButton(51, 13, "Log in", 7);
					textInButton(48, 18, "Registration", 7);
					textInButton(47, 23, "Change password", 7);
					textInButton(52, 28, "Exit", 8);
					computerFigure(68, 30);
					border(107, 0, 51);
					counter = 3;
				}break;
				}
			} break;

			case KEY_DOWN:
			{
				switch (counter)
				{
				case 1:
				{
					system("CLS");
					border(0, 0, 51);
					teamFigure(10, 33);
					label(30, 1);
					button(43, 11, 8);
					button(43, 16, 7);
					button(43, 21, 7);
					button(43, 26, 7);
					textInButton(51, 13, "Log in", 8);
					textInButton(48, 18, "Registration", 7);
					textInButton(47, 23, "Change password", 7);
					textInButton(52, 28, "Exit", 7);
					computerFigure(68, 30);
					border(107, 0, 51);
					counter = 2;
				}break;
				case 2:
				{
					system("CLS");
					border(0, 0, 51);
					teamFigure(10, 33);
					label(30, 1);
					button(43, 11, 7);
					button(43, 16, 8);
					button(43, 21, 7);
					button(43, 26, 7);
					textInButton(51, 13, "Log in", 7);
					textInButton(48, 18, "Registration", 8);
					textInButton(47, 23, "Change password", 7);
					textInButton(52, 28, "Exit", 7);
					computerFigure(68, 30);
					border(107, 0, 51);
					counter = 3;
				}break;
				case 3:
				{
					system("CLS");
					border(0, 0, 51);
					teamFigure(10, 33);
					label(30, 1);
					button(43, 11, 7);
					button(43, 16, 7);
					button(43, 21, 8);
					button(43, 26, 7);
					textInButton(51, 13, "Log in", 7);
					textInButton(48, 18, "Registration", 7);
					textInButton(47, 23, "Change password", 8);
					textInButton(52, 28, "Exit", 7);
					computerFigure(68, 30);
					border(107, 0, 51);
					counter = 4;
				}break;
				case 4:
				{
					system("CLS");
					border(0, 0, 51);
					teamFigure(10, 33);
					label(30, 1);
					button(43, 11, 7);
					button(43, 16, 7);
					button(43, 21, 7);
					button(43, 26, 8);
					textInButton(51, 13, "Log in", 7);
					textInButton(48, 18, "Registration", 7);
					textInButton(47, 23, "Change password", 7);
					textInButton(52, 28, "Exit", 8);
					computerFigure(68, 30);
					border(107, 0, 51);
					counter = 1;
				}break;
				}
			}break;
			case KEY_ENTER:
			{
				switch (counter)
				{
				case 1:
				{
					system("CLS");
					border(0, 0, 51);
					label(30, 1);
					border(107, 0, 51);
					login();
				}break;
				case 2:
				{
					system("CLS");
					border(0, 0, 51);
					label(30, 1);
					border(107, 0, 51);
					login();
				}break;
				case 3:
				{
					system("CLS");
					border(0, 0, 51);
					label(30, 1);
					border(107, 0, 51);
					registration();
					
				}break;
				}
			}
			}
		} while (true);
		return 1;
	}
}



