#pragma once

#include "HashTable.h"
#include "PairKeyValue.h"
#include <string>

struct Dictionary
{
	HashTable* InnerHashTable = new HashTable;

	bool Insert(std::string, std::string);
	PairKeyValue* Find(std::string);
	bool Remove(std::string);
	bool CreateDictionary(int);
	void DeleteDictionary();
};