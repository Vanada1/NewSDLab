#include"Dictionary.h"
#include "InputOutput.h"
#include "TempArray.h"
#include "MenuDictionary.h"
#include "WorkWuthFiles.h"
#include <iostream>
#include <ctime>

using namespace std;

int MenuDictionary()
{
	srand(time(nullptr));
	Dictionary* dictionary = new Dictionary;
	PairKeyValue* temp;
	//TODO: RSDN(Done)
	//TODO: Почему здесь?(Done)
	bool isEnd = false;
	cout << "Enter the size for table ";
	cout << endl;
	dictionary->CreateDictionary(ReadInt());
	cout << "Done\n";
	while (!isEnd)
	{
		system("pause");
		system("cls");
		PrintDictionary(dictionary);
		TextOutput("menuDic.txt");
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
				if (dictionary->Insert(name, book))
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
				if (dictionary->Remove(name))
				{
					OutputDone();
				}
				else
				{
					OutputError();
				}
				break;
			}
			case 3:
			{
				cout << "Enter Author name to find all his books ";
				string name;
				cin >> name;
				cout << endl;
				temp = dictionary->Find(name);
				for (int i = 0; i < dictionary->InnerHashTable->CountElements; i++)
				{
					cout << temp[i].Value << "\t";
				}
				dictionary->InnerHashTable->CountElements = 0;
				delete[] temp;
				cout << endl;
				break;
			}
			case 4:
			{
				system("cls");
				PrintHashTable(dictionary->InnerHashTable);
				break;
			}
			case 5:
			{
				cout << "Enter the number ";
				int number = ReadInt();
				cout << endl;
				for (int i = 0; i < number; i++)
				{
					//TODO: RSDN(DOne)
					dictionary->Insert(to_string(rand() % 100),
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
	dictionary->DeleteDictionary();
	delete dictionary;
	return 0;
}
