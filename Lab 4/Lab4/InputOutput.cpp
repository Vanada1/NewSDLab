#include <iostream>
#include <fstream>
#include <string>
#include"InputOutput.h"

using namespace std;
//TODO: Дубль
string WriteString()
{
	bool error;
	string str;
	do
	{
		error = false;
		cin >> str;
		if (cin.fail() || str == "")
		{
			cout << "Wrong\n";
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error);
	return str;
}
//TODO: Дубль
int  WriteInt()
{
	bool error;
	int number;
	do
	{
		error = false;
		cin >> number;
		if (cin.fail() || number < 1)
		{
			cout << "Wrong\n";
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error);
	return number;
}

void Error()
{
	cout << "Error\n";
}

void None()
{
	cout << "None\n";
}

void RehashingDone()
{
	cout << "Rehashing done\n";
}

void TextOutput(string str)
{
	string line;

	ifstream fil(str);
	if (fil.is_open())
	{
		while (getline(fil, line))
		{
			cout << line << endl;
		}
	}
	else
	{
		cout << "Error: cannot open the file";
	}
	fil.close();
}

void PrintHashTable(Hash* hashTable)
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
	for (int i = 0; i < dictionary->Diction->GetTableSize(); i++)
	{
		Item* current = dictionary->Diction->HashTable[i];
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
		cout << "count of items = " << dictionary->Diction->Count(i) << endl;
	}
}

void ShowResult(string value)
{
	cout << value << endl;
}

void Done()
{
	cout << "Done\n";
}
