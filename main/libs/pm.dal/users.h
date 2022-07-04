#pragma once
#include "pch.h"

namespace pm::dal
{
	namespace users
	{
		// Function for getting user id
		auto getIdByUsername(std::string username);
		// Function for checking if the user exists
		void checkUser(std::string username, std::string password);
		// Function for checking if the user is admin
		bool checkAdmin(std::string username);
		// Function for showing all users
		void showUsers();
		// Function for making user an admin
		void makeAnAdmin(std::string username);
		// Function for adding users
		void insertUsersDB(std::string username, std::string firstName, std::string lastName, std::string pass);
		// Function for adding users in team
		void insertUsersInTeam(int users, std::string teamName);
		// Function for adding users in project
		void insertUsersInProject(int users, std::string projectName);
		// Function for deleting users
		void deleteUsers(std::string username);
		// Function for editing users
		void updateUsers(std::string username, std::string firstName, std::string lastName, std::string newUsername);
		// Function for changing password
		void updatePassword(std::string username, std::string password);
	}
}