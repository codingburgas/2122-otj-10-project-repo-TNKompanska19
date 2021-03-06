#pragma once
#include "pch.h"

namespace pm::types
{
	struct USER
	{
		size_t id;
		std::string firstName;
		std::string lastName;
		std::string email;
		uint8_t age;
		std::string passwordHash;
	};
}