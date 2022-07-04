#pragma once
#include "pch.h"

namespace pm::dal
{
	namespace teams
	{
		// Function for getting team id
		int getIdByTeamName(std::string teamName);
		// Function for viewing team in project
		void viewTeamsInProject(std::string name);
		// Function for showing in which team user is 
		void showUserTeams(std::string username);
		// Function for showing all teams
		void showTeams();
		// Function for editing teams
		void updateTeams(std::string title, std::string newTitle);
		// Function for adding teams
		void insertTeams(std::string title, std::string projectName);
		// Function for deleting teams
		void deleteTeams(std::string title);
	}
}