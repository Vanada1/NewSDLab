#pragma once

#include"TempArray.h"
#include "Item.h"

struct HashTable
{
public:
	Item** HashTable;
	int CountElements = 0;

	bool Insert(std::string, std::string);
	bool Remove(std::string);
	SupportArray* Search(std::string);
	bool CreateHashTable(int);
	int Count(int);
	void DeleteHashTable();
	int GetTableSize();
	bool SetTableSize(int);
	int HashFunc(std::string);
private:
	int _number = 19;
	int _tableSize = 0;
	int _countOfElement = 0;

	bool DecisionCollision(std::string, std::string);
	bool Rehashing();
};
