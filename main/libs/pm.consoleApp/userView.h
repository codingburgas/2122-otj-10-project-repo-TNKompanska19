#pragma once
#include "pch.h"

namespace pm::consoleApp
{
	namespace userView
	{
		// Function for showing user options
		void userOptions(std::string username);
		// Function for showing options when user is in created projects panel
		void createdProjectsOptions(std::string username);
	}
}