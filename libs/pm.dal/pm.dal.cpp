#include "pch.h"
#include "UserStore.h"
static std::vector<pm::type::User> users;

namespace pm::dal
{
	struct UserStore
	{
		void createUser(User& user)
		{
			auto foundUser = std::ranges::find_if(users, [&user](const pm::type::User& user1) -> bool
				{
					return user.email == user1.email;
				});

			if (foundUser != users.end())
			{
				throw std::range_error("User with email: " + user.email + " already exist!");
			}

			user.id = pm::dal::UserStore::lastId;
			time(&user.createdOn);

			users.emplace_back(user);

			pm::dal::UserStore::lastId;
		}

		std::vector<User> getAllUsers()
		{
			return std::vector<User>(users);
		}

		void removeUser(size_t& id)
		{
			auto removedEl = std::remove_if(users.begin(), users.end(), [&id](const pm::type::User& user) -> bool
				{
					return user.id == id;
				});

			if (removedEl == users.end()) throw std::range_error("User with id: " + std::to_string(id) + " does not exist!");

			users.erase(removedEl, removedEl + 1);
		}

		void updateUser(pm::type::User& user)
		{
			pm::type::User foundUser = getUserById(user.id);

			    std::ranges::replace_if(users.begin(), users.end(), [&foundUser](const pm::type::User& current) -> bool
				{
					return current.id == foundUser.id;
				}, user);
		}

		pm::type::User getUserById(size_t& id)
		{
			auto foundUser = std::find_if(users.begin(), users.end(), [&id](const pm::type::User& user)-> bool
				{
					return user.id == id;
				});

			if (foundUser == users.end()) throw std::range_error("User with id: " + std::to_string(id) + " does not exist");

			return *foundUser;
		}

		pm::type::User getUserByEmail(std::string& email)
		{
			auto foundUser = std::find_if(users.begin(), users.end(), [&email](const pm::type::User& user)-> bool
				{
					return user.email == email;
				});

			if (foundUser == users.end()) throw std::range_error("User with email: " + email + " does not exist");

			return *foundUser;
		}
	};
	
}



