#include "pch.h"
#include <iostream>
#include "..\pm.types\User.h"
#include "UserStore.h"

using namespace std;
void create(pm::type::User user)
{
	size_t id;
	std::string firstName;
	std::string lastName;
	std::string email;
	unsigned short age;

	cin >> firstName;
	cin >> lastName;
	cin >> email;
	cin >> age;

	user.firstName = firstName;
	user.lastName = lastName;
	user.email = email;
	user.age = age;
}

vector<pm::type::User> getAll(pm::type::User user)
{
	vector< pm::type::User> userStore;

	userStore.push_back(user);
	userStore.push_back(user);

	return userStore;
}

void remove(size_t id, vector<pm::type::User> userStore)
{
	/*for (size_t i = 0; i < userStore.size(); i++)
	{
		if (userStore[i].id == id)
		{
			userStore[i].erase(i);
		}
	}*/

}


