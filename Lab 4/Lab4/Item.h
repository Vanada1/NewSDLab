#pragma once

#include <string>
struct Item
{
	std::string Key;
	std::string Value;
	Item* Next;
};