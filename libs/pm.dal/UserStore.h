#pragma once
#include "pch.h"

namespace pm::dal
{
	struct User
	{
		size_t id;
		string firstName;
		string lastName;
		string email;
		unsigned short age;
		string passwordHash;
		time_t createdOn;
	};

	struct UserStore
	{
		static int lastId;

		void createUser(User& user);

		std::vector<User> getAllUsers();

		void removeUser(size_t& id);

		void updateUser(pm::type::User& user);

		pm::type::User getUserById(size_t& id);

		pm::type::User getUserByEmail(std::string& email);
	};

	int pm::dal::UserStore::lastId = 0;
}