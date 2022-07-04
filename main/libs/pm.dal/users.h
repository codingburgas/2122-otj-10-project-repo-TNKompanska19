#pragma once
#include "pch.h"

namespace pm::dal
{
	namespace users
	{
		auto getIdByUsername(std::string username);
		void checkUser(std::string username, std::string password);
		bool checkAdmin(std::string username);
		void showUsers();
		void makeAnAdmin(std::string username);
		void insertUsersDB(std::string username, std::string firstName, std::string lastName, std::string pass);
		void insertUsersInTeam(int users, std::string teamName);
		void insertUsersInProject(std::string username, std::string projectName);
		void deleteUsers(std::string username);
		void updateUsers(std::string username, std::string firstName, std::string lastName, std::string newUsername);
	}
}