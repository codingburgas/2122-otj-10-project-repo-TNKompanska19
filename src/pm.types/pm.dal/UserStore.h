#pragma once
#include "pch.h"
#include "..\pm.types\User.h"
using namespace std;

namespace pm::dal
{
	struct UserStore
	{
		// display users
		vector <pm::type::User> getAll();
		// create user
		void create(pm::type::User user);
		// deletes user by id
		void remove(size_t id);
		// change something about given user
		void update(pm::type::User user);
		// display user by given id
		pm::type::User getById(size_t id);
		// display user by given email
		pm::type::User getByEmail(std::string email);
	};
}