#pragma once
#include "pch.h"

namespace pm::dal
{
	namespace tasks
	{
		void insertTasks(std::string title, std::string description, std::string projectName);
		void viewTasksInProject(std::string name);
	}
}