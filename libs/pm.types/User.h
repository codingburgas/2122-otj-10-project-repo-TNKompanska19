#pragma once
#include "pch.h"

namespace pm::type
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
}