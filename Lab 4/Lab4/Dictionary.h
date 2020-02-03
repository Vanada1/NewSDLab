#pragma once

#include "HashTable.h"
#include "TempArray.h"
#include <string>

struct Dictionary
{
	HashTable* Diction = new HashTable;

	bool Insert(std::string, std::string);
	SupportArray* Find(std::string);
	bool Remove(std::string);
	bool CreateDictionary(int);
	void DeleteDictionary();
};