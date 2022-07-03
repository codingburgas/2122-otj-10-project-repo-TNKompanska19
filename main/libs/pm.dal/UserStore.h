#pragma once
#include "pch.h"
namespace pm::dal
{
	void insertUsersDB(std::string username, std::string firstName, std::string lastName, std::string pass);
	void insertProjectsDB(std::string title, std::string description, std::string username);
	void insertTasks(std::string title, std::string description, std::string projectName, std::string username);
	void insertTeams(std::string title);
	void insertUsersInTeam(int users, std::string teamName);
	void insertUsersInProject(std::string username, std::string projectName);
	int getIdByUsername(std::string username);
	void checkUser(std::string username, std::string password);
	bool checkAdmin(std::string username);
	void showUserProjects(std::string username);
	void showUserCreatedProjects(std::string username);
	void updateProjects(std::string title, std::string newTitle, std::string description, std::string username);
	void deleteProjects(std::string title, std::string username);
}