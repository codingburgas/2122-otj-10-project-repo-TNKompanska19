#pragma once
#include "pch.h"
namespace pm::dal
{
	void sth();
	void insertUsersDB(string username, string firstName, string lastName, string pass);
	void insertProjectsDB(string title, string description);
	void insertTasks(string title, string description, string projectName, string username);
	void insertTeams(string title);
	void insertUsersInTeam(int users, string teamName);
	void insertUsersInProject(string username, string projectName);
	int getIdByUsername(string username);
	void checkUser(string username, string password);
	bool checkAdmin(string username);
}