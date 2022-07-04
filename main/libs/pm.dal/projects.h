#pragma once
#include "pch.h"

namespace pm::dal
{
	namespace projects
	{
		// Function for getting project id by username
		int getProjectIdByUsername(std::string username);
		// Function for getting project id
		int getIdByProjectName(std::string title);
		// Function for adding projects
		void insertProjectsDB(std::string title, std::string description, std::string username);
		// Function for viewing in which projects user is in
		void showUserProjects(std::string username);
		// Function for viewing user created projects
		void showUserCreatedProjects(std::string username);
		// Function for editing projects
		void updateProjects(std::string title, std::string newTitle, std::string description, std::string username);
		// Function for deleting projects
		void deleteProjects(std::string title, std::string username);
		// Function for viewing projects info
		void viewProject(std::string name);
		// Function for viewing all projects
		void showProjects();
	}
}