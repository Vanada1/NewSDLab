#pragma once

#include "Hash.h"
#include "TempArray.h"
#include <string>

struct Dictionary
{
	Hash* Diction = new Hash;

	bool Insert(std::string, std::string);
	TempArray* Find(std::string);
	bool Remove(std::string);
	bool CreateDictionary(int);
	void DeleteDictionary();
};