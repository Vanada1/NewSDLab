#include <iostream>
#include"InputOutput.h"

using namespace std;

void OutputError()
{
	cout << "Error\n";
}

void OutputNone()
{
	cout << "None\n";
}

void RehashingDone()
{
	cout << "Rehashing done\n";
}

void PrintHashTable(HashTable* hashTable)
{
	for (int i = 0; i < hashTable->GetTableSize(); i++)
	{
		cout << "index = " << i << '\t';
		Item* current = hashTable->HashTable[i];
		while (current != nullptr)
		{
			cout << "Author name " << current->Key << '\t';
			cout << "Book " << current->Value << '\t';
			current = current->Next;
		}
		cout << "count of items = " << hashTable->Count(i) << endl;
	}
}

void PrintDictionary(Dictionary* dictionary)
{
	for (int i = 0; i < dictionary->InnerHashTable->GetTableSize(); i++)
	{
		Item* current = dictionary->InnerHashTable->HashTable[i];
		if (current->Key == "")
		{
			continue;
		}
		cout << "index = " << i << '\t';
		while (current != nullptr)
		{
			cout << "Author name " << current->Key << '\t';
			cout << "Book  " << current->Value << '\t';
			current = current->Next;
		}
		cout << "count of items = " << dictionary->InnerHashTable->Count(i) << endl;
	}
}

void ShowResult(string value)
{
	cout << value << endl;
}

void OutputDone()
{
	cout << "Done\n";
}
