#pragma once
#include "pch.h"

namespace pm::dal
{
	namespace tasks
	{
		// Function for adding tasks
		void insertTasks(std::string title, std::string description, std::string projectName);
		// Function for viewing task in project
		void viewTasksInProject(std::string name);
	}
}