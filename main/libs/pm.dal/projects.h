#pragma once
#include "pch.h"

namespace pm::dal
{
	namespace projects
	{
		void insertProjectsDB(std::string title, std::string description, std::string username);
		void showUserProjects(std::string username);
		void showUserCreatedProjects(std::string username);
		void updateProjects(std::string title, std::string newTitle, std::string description, std::string username);
		void deleteProjects(std::string title, std::string username);
		void viewProject(std::string name);
		void showProjects();
	}
}