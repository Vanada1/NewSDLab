#include "Hash.h"
#include "InputOutput.h"
#include "TempArray.h"
#include "menuHash.h"
#include <iostream>
#include <ctime>

using namespace std;

int MenuHash()
{
	srand(time(NULL));
	Hash* hash = new Hash;
	TempArray* temp;
	string name, book;
	int control = 0;
	int number;
	bool ending = true;
	int size;
	cout << "Enter the size for table ";
	cout << endl;
	hash->CreateHashTable(WriteInt());
	cout << "Done\n";
	while (ending)
	{
		system("pause");
		system("cls");
		PrintHashTable(hash);
		TextOutput("menuHash.txt");
		control = WriteInt();
		switch (control)
		{
		case 1:
			cout << "Enter Author name ";
			name = WriteString();
			cout << endl;

			cout << "Enter Book name ";
			book = WriteString();
			cout << endl;
			if (hash->Insert(name, book))
			{
				Done();
			}
			else
			{
				Error();
			}
			break;

		case 2:
			cout << "Enter Author name to delete all book ";
			name = WriteString();
			cout << endl;
			if (hash->Remove(name))
			{
				Done();
			}
			else
			{
				Error;
			}
			break;
		case 3:
			cout << "Enter Author name to find all his books ";
			name = WriteString();
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
		case 4:
			cout << "Enter the number ";
			number = WriteInt();
			cout << endl;
			for (int i = 0; i < number; i++)
			{
				if (!hash->Insert(to_string(rand() % 100), to_string(rand() % 100)))
				{
					Error;
					i--;
				}
			}
			break;
		case 9:
			ending = false;
			break;
		default:
			break;
		}
	}
	hash->DeleteHashTable();
	delete hash;
	return 0;
}
