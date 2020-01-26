#include "Dictionary.h"

bool Dictionary::CreateDictionary(int number)
{
	return Diction->CreateHashTable(number);
}

void Dictionary::DeleteDictionary()
{
	Diction->DeleteHashTable();
	delete Diction;
}

TempArray* Dictionary::Find(std::string key)
{
	return Diction->Search(key);
}

bool Dictionary::Insert(std::string key, std::string value)
{
	int index = Diction->Hashing(key);
	Item* current = Diction->HashTable[index];
	while (current != nullptr)
	{
		if (current->Key == key)
		{
			return false;
		}
		current = current->Next;
	}
	return Diction->Insert(key, value);
}

bool Dictionary::Remove(std::string key)
{
	return Diction->Remove(key);
}

