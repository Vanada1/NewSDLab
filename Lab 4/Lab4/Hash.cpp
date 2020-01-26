#include "Hash.h"
#include "TempArray.h"


int Hash::Hashing(std::string key)
{
	long unsigned int hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash += (int)key[i] * pow(_number, i);
	}
	hash %= _tableSize;
	return hash;
}

bool Hash::SetTableSize(int number)
{
	_tableSize = number;
	
	if (_tableSize == _number)
	{
		return false;
	}
	return true;
}

bool Hash::CreateHashTable(int number)
{
	//Number = WriteInt();
	if (_tableSize != 0)
	{
		_tableSize *= 2;
	}
	else 
	{ 
		if (!SetTableSize(number))
		{
			return false;
		}
	}
	HashTable = new Item*[_tableSize];
	for (int i = 0; i < _tableSize; i++)
	{
		HashTable[i] = new Item;
		HashTable[i]->Key = "";
		HashTable[i]->Value = "";
		HashTable[i]->Next = nullptr;
	}
	return true;
}

bool Hash::Insert(std::string key, std::string value)
{
	int index = Hashing(key);

	if (HashTable[index]->Key == "")
	{
		HashTable[index]->Key = key;
		HashTable[index]->Value = value;
	}
	else if (HashTable[index]->Key == key && HashTable[index]->Value == value)
	{
		return false;
	}
	else
	{
		if (!DecisionCollision(key, value))
		{
			return false;
		}
	}
	_countOfElement++;
	if ((double)_countOfElement / _tableSize > 0.8)
	{
		if (Rehashing())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool Hash::DecisionCollision(std::string key, std::string value)
{
	int index = Hashing(key);
	Item* current = HashTable[index];
	Item* newElement = new Item;
	newElement->Key = key;
	newElement->Value = value;
	newElement->Next = nullptr;
	while (current->Next != nullptr)
	{
		if (current->Next->Key == newElement->Key &&
			current->Next->Value == newElement->Value)
		{
			delete newElement;
			return false;
		}
		current = current->Next;
	}
	current->Next = newElement;
	return true;
}

TempArray* Hash::Search(std::string key)
{
	int index = Hashing(key);
	int i = 0;
	TempArray* arr = new TempArray[Count(index)];
	Item* current = HashTable[index];
	while (current != nullptr)
	{
		if (current->Key == key)
		{
			arr[i].Key = current->Key;
			arr[i].Value = current->Value;
			CountElements++;
			i++;
		}
		current = current->Next;
	}
	return arr;
}

bool Hash::Remove(std::string key)
{
	int  index = Hashing(key);
	Item* current = HashTable[index];
	if (Count(index) == 1 && HashTable[index]->Key == key)
	{
		HashTable[index]->Key = "";
		HashTable[index]->Value = "";
		HashTable[index]->Next = nullptr;
		return true;
	}
	if (current->Key == key)
	{
		HashTable[index] = current->Next;
		delete current;
		Remove(key);
		return true;
	}
	Item* currentPerv = HashTable[index];
	while (current != nullptr && HashTable[index]->Key != "")
	{
		if (current->Key == key)
		{
			Item* deleteElement = current;
			currentPerv->Next = deleteElement->Next;
			delete deleteElement;
			current = currentPerv;
			_countOfElement--;
		}
		else
		{
			if (current->Next != nullptr && current->Next->Key != key)
			{
				currentPerv = currentPerv->Next;
			}
		}
		current = current->Next;
	}
	
	return true;
}

int Hash::Count(int index)
{
	if (HashTable[index]->Key == "")
	{
		return 0;
	}

	Item* current = HashTable[index];
	int number = 0;

	while (current != nullptr)
	{
		number++;
		current = current->Next;
	}
	return number;
}

void Hash::DeleteHashTable()
{
	for (int i = 0; i < _tableSize; i++)
	{
		while(HashTable[i] != nullptr)
		{
			Item* deleteItem = HashTable[i];
			HashTable[i] = HashTable[i]->Next;
			delete deleteItem;
		}
		delete HashTable[i];
	}
	_countOfElement = 0;
	delete HashTable;
}

bool Hash::Rehashing()
{
	int temp = _countOfElement;
	int place = 0;
	TempArray* tempArray = new TempArray[temp];
	for (int i = 0; i < _tableSize; i++)
	{
		Item* current = HashTable[i];
		while (current != nullptr)
		{
			if (current->Key == "")
			{
				current = current->Next;
				continue;
			}
			if (place >= _countOfElement)
			{
				return false;
			}
			tempArray[place].Key = current->Key;
			tempArray[place].Value = current->Value;
			place++;
			current = current->Next;
		}
	}
	DeleteHashTable();
	CreateHashTable(0);
	for (int i = 0; i < temp; i++)
	{
		Insert(tempArray[i].Key, tempArray[i].Value);
	}
	delete[] tempArray;
	return true;
	
}

int Hash::GetTableSize()
{
	return _tableSize;
}
