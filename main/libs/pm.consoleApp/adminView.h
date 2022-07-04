#pragma once
#include "pch.h"

namespace pm::consoleApp
{
	namespace adminView
	{
		// Function for showing admin options
		void adminOptions(std::string username);
		// Function for showing options when admin is in user panel
		void userPanelOptions(std::string username);
		// Function for showing options when admin is in team panel
		void teamPanelOptions(std::string username);
		// Function for showing options when admin is in project panel
		void projectPanelOptions(std::string username);
	}
}