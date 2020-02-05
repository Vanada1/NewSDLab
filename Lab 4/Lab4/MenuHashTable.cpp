#include "HashTable.h"
#include "InputOutput.h"
#include "TempArray.h"
#include "MenuHashTable.h"
#include "WorkWuthFiles.h"
#include <iostream>
#include <ctime>

using namespace std;

int MenuHashTable()
{
	srand(time(nullptr));
	HashTable* hash = new HashTable;
	SupportArray* temp;
	//TODO: RSDN(Done)
	//TODO: Почему здесь?(Done)
	bool isEnd = false;
	cout << "Enter the size for table ";
	cout << endl;
	hash->CreateHashTable(ReadInt());
	cout << "Done\n";
	while (!isEnd)
	{
		system("pause");
		system("cls");
		PrintHashTable(hash);
		TextOutput("menuHash.txt");
		switch (ReadInt())
		{
			//TODO: RSDN(Done)
		case 1:
		{
			cout << "Enter Author name ";
			string name;
			string book;
			cin >> name;
			cout << endl;

			cout << "Enter Book name ";
			cin >> book;
			cout << endl;
			if (hash->Insert(name, book))
			{
				OutputDone();
			}
			else
			{
				OutputError();
			}
			break;
		}

		case 2:
		{
			cout << "Enter Author name to delete all book ";
			string name;
			cin >> name;
			cout << endl;
			if (hash->Remove(name))
			{
				OutputDone();
			}
			else
			{
				OutputError;
			}
			break;
		}
		case 3:
		{
			cout << "Enter Author name to find all his books ";
			string name;
			cin >> name;
			cout << endl;
			temp = hash->Search(name);
			for (int i = 0; i < hash->CountElements; i++)
			{
				cout << temp[i].Value << "\t";
			}
			hash->CountElements = 0;
			delete[] temp;
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "Enter the number ";
			int number = ReadInt();
			cout << endl;
			for (int i = 0; i < number; i++)
			{
				//TODO: RSDN(Done)
				hash->Insert(to_string(rand() % 100),
					to_string(rand() % 100));
			}
			break;
		}
		case 9:
		{
			isEnd = true;
			break;
		}
		default:
		{
			break;
		}
		}
	}
	hash->DeleteHashTable();
	delete hash;
	return 0;
}
