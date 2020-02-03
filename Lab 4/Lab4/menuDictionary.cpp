#include"Dictionary.h"
#include "InputOutput.h"
#include "TempArray.h"
#include "MenuDictionary.h"
#include <iostream>
#include <ctime>

using namespace std;

int MenuDictionary()
{
	srand(time(nullptr));
	Dictionary* dictionary = new Dictionary;
	SupportArray* temp;
	//TODO: RSDN
	string name, book;
	//TODO: ������ �����?
	int control = 0;
	int number;
	bool ending = true;
	int size;
	cout << "Enter the size for table ";
	cout << endl;
	dictionary->CreateDictionary(WriteInt());
	cout << "Done\n";
	while (ending)
	{
		system("pause");
		system("cls");
		PrintDictionary(dictionary);
		TextOutput("menuDic.txt");
		control = WriteInt();
		switch (control)
		{
			//TODO: RSDN
		case 1:
			cout << "Enter Author name ";
			cin >> name;
			cout << endl;

			cout << "Enter Book name ";
			cin >> book;
			cout << endl;
			if (dictionary->Insert(name, book))
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
			cin >> name;
			cout << endl;
			if (dictionary->Remove(name))
			{
				Done();
			}
			else
			{
				Error();
			}
			break;
		case 3:
			cout << "Enter Author name to find all his books ";
			cin >> name;
			cout << endl;
			temp = dictionary->Find(name);
			for (int i = 0; i < dictionary->Diction->CountElements; i++)
			{
				cout << temp[i].Value << "\t";
			}
			dictionary->Diction->CountElements = 0;
			delete[] temp;
			cout << endl;
			break;
		case 4:
			system("cls");
			PrintHashTable(dictionary->Diction);
			break;
		case 5:
			cout << "Enter the number ";
			number = WriteInt();
			cout << endl;
			for (int i = 0; i < number; i++)
			{
				//TODO: RSDN
				dictionary->Insert(to_string(rand() % 100), to_string(rand() % 100));
			}
			break;
		case 9:
			ending = false;
			break;
		default:
			break;
		}
	}
	dictionary->DeleteDictionary();
	delete dictionary;
	return 0;
}
