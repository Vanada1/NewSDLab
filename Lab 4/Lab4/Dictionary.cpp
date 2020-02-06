#include "Dictionary.h"

bool Dictionary::CreateDictionary(int number)
{
	return InnerHashTable->CreateHashTable(number);
}

void Dictionary::DeleteDictionary()
{
	InnerHashTable->DeleteHashTable();
	delete InnerHashTable;
}

PairKeyValue* Dictionary::Find(std::string key)
{
	return InnerHashTable->Search(key);
}

bool Dictionary::Insert(std::string key, std::string value)
{
	int index = InnerHashTable->HashFunc(key);
	Item* current = InnerHashTable->HashTable[index];
	while (current != nullptr)
	{
		if (current->Key == key)
		{
			return false;
		}
		current = current->Next;
	}
	return InnerHashTable->Insert(key, value);
}

bool Dictionary::Remove(std::string key)
{
	return InnerHashTable->Remove(key);
}

