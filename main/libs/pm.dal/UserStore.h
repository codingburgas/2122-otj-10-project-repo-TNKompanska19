#pragma once
#include "pch.h"
namespace pm::dal
{
	void sth();
	void insertUsersDB(std::string username, std::string firstName, std::string lastName, std::string pass);
	void insertProjectsDB(std::string title, std::string description);
	void insertTasks(std::string title, std::string description, std::string projectName, std::string username);
	void insertTeams(std::string title);
	void insertUsersInTeam(int users, std::string teamName);
	void insertUsersInProject(std::string username, std::string projectName);
	int getIdByUsername(std::string username);
	void checkUser(std::string username, std::string password);
	bool checkAdmin(std::string username);
}