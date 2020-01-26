#pragma once

#include"TempArray.h"
#include "Item.h"

struct Hash
{
public:
	Item** HashTable;
	int CountElements = 0;

	bool Insert(std::string, std::string);
	bool Remove(std::string);
	TempArray* Search(std::string);
	bool CreateHashTable(int);
	int Count(int);
	void DeleteHashTable();
	int GetTableSize();
	bool SetTableSize(int);
	int Hashing(std::string);
private:
	int _number = 19;
	int _tableSize = 0;
	int _countOfElement = 0;

	bool DecisionCollision(std::string, std::string);
	bool Rehashing();
};
