#pragma once

#include"PairKeyValue.h"
#include "Item.h"

struct HashTable
{
public:
	Item** HashTable;
	int CountElements = 0;

	bool Insert(std::string, std::string);
	bool Remove(std::string);
	PairKeyValue* Search(std::string);
	bool CreateHashTable(int);
	int Count(int);
	void DeleteHashTable();
	int GetTableSize();
	bool SetTableSize(int);
	int HashFunc(std::string);
private:
	float _fillFactor = 0.8;
	int _arrayIncrease = 2;
	int _number = 19;
	int _tableSize = 0;
	int _countOfElement = 0;

	bool DecisionCollision(std::string, std::string);
	bool Rehashing();
};
