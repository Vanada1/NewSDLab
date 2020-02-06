#include <iostream>
#include "ListFunc.h"
#include"WorkWithFiles.h"
#include "InputOutput.h"
#include <ctime>
#define SWITCH 0

using namespace std;

int main()
{
	srand(time(nullptr));

	bool isEnd = false;
	//TODO:rsdn(Done)
	List* list = new List();
	//TODO: RSDN(Done)
	cout << "Enter the number of elements" << endl;
	int quantity = ReadInt();
	cout << endl;
	long double elapsed_secs = 0;
#if SWITCH == 1
	clock_t begin = clock();
#endif

	for (int i = 0; i < quantity; i++)
	{
		InsertInList(list, rand() % 100, list->Size, elapsed_secs);
	}

#if SWITCH == 1
	clock_t end = clock();
	elapsed_secs = FuncCounting(begin, end);
	OutputTime(elapsed_secs, "create of list ");
#endif

	while (!isEnd)
	{
		system("pause");
		system("cls");
		OutputList(list);
		cout << "What do you want to do with the array?\n";
		TextOutput();
		switch (ReadInt())
		{
			//TODO:rsdn(Done)
			case 1:
			{
				cout << "Enter index\n";
				int index = ReadInt();
				if (DeleteElement(list, index, elapsed_secs))
				{
					OutputDone();
					#if SWITCH == 1
						OutputTime(elapsed_secs, "delete element ");
					#endif
				}
				else
				{
					OutputError();
				}
				break;
			}
			case 2:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				if (InsertInList(list, number, 0, elapsed_secs))
				{
					OutputDone();
					#if SWITCH == 1
						OutputTime(elapsed_secs, "add element ");
					#endif
				}
				else
				{
					OutputError();
				}
				break;
			}
			case 3:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				if (InsertInList(list, number, list->Size, elapsed_secs))
				{
					OutputDone();
					#if SWITCH == 1
						OutputTime(elapsed_secs, "add element ");
					#endif
				}
				else
				{
					OutputError();
				}
				break;
			}
			case 4:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				cout << "Enter index\n";
				int index = ReadInt();
				if (InsertInList(list, number, index + 1, elapsed_secs))
				{
					OutputDone();
					#if SWITCH == 1
						OutputTime(elapsed_secs, "add element ");
					#endif
				}
				else
				{
					OutputError();
				}
				break;
			}
			case 5:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				cout << "Enter index\n";
				int index = ReadInt();
				if (InsertInList(list, number, index, elapsed_secs))
				{
					OutputDone();
					#if SWITCH == 1
						OutputTime(elapsed_secs, "add element ");
					#endif
				}
				else
				{
					OutputError();
				}
				break;
			}
			case 6:
			{
				InsertionSort(list);
				break;
			}
			case 7:
			{
				cout << "What number do you want to find?\n";
				int number = ReadInt();
				int index = 0;
				if (LineSearch(list, number, index))
				{
					cout << "The numder " << number << " in " << index << " cell\n";
				}
				else
				{
					cout << "Not found\n";
				}
				break;
			}
			case 8:
			{
				OutputListBack(list);
				break; 
			}
			case 9:
			{
				isEnd = true;
				break;
			}
			case 10:
			{
				cout << "Insert quantity \n";
				cin >> quantity;
				OutputTime(AddElement(list, quantity), "add elements ");
			}
			default:
			{
				break;
			}
		}
	}
	DeleteList(list);
	cout << endl << "Work is done" << endl;
	cout << endl;
	system("pause");
}