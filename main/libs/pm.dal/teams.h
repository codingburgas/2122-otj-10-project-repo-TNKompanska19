#pragma once
#include "pch.h"

namespace pm::dal
{
	namespace teams
	{
		int getIdByTeamName(std::string teamName);
		void viewTeamsInProject(std::string name);
		void showUserTeams(std::string username);
		void showTeams();
		void updateTeams(std::string title, std::string newTitle);
		void insertTeams(std::string title, std::string projectName);
		void deleteTeams(std::string title);
	}
}