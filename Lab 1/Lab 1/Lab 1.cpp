#include <iostream>
#include <ctime>
#include "InputOutput.h"
#include "../../CommonFuction/WorkWithFiles.h"
#include "Realisation.h"

using namespace std;

int main()
{
	srand(time(nullptr));

	//TODO: naming(Done)
	bool isEnd = true;
	//TODO:rsdn(Done)
	DynamicArray array;
	CreatArray(array);

	while (isEnd)
	{
		system("cls");
		OutputArray(array);
		cout << "What do you want to do with the array?\n";
		TextOutput("menu.txt");
		switch (ReadInt())
		{
			//TODO:скобочки(Done)
			case 1:
			{
				cout << "Which element you want to delete\t";
				int index = ReadInt();
				//TODO: дубль(Done)
				ShowResult(RemoveElement(array, index));
				break;
			}
			case 2:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				ShowResult (AddElement(array, number, 0));
				break;
			}
			case 3:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				ShowResult (AddElement(array, number, array.Lenght));
				break;
			}
			case 4:
			{
				cout << "Enter the index\n";
				int index = ReadInt();
				cout << "Enter the number\n";
				int number = ReadInt();
				ShowResult(AddElement(array, number, index + 1));
				break;
			}
			case 5:
			{
				QuickSortArray(array);
				break;
			}
			case 6:
			{
				cout << "What number are you looking for?\n";
				int number = ReadInt();
				int index = 0;
				if (LineSearch(array, number, index))
				{
					cout << "Number " << number << " in " << index << endl;
				}
				else
				{
					cout << "There is no such number in this array\n";
				}
				break;
			}
			case 7:
			{
				if (CheckSort(array))
				{
					cout << "What number are you looking for?\n";
					int number = ReadInt();
					int index = 0;
					if (BinarySearch(array, number, index))
					{
						cout << "Number " << number << " in " << index << endl;
					}
					else
					{
						cout << "There is no such number in this array\n";
					}
				}
				else
				{
					cout << "Array is not sorted\n";
				}
				break;
			}

			case 9:
			{
				isEnd = false;
				break;
			}
			default:
			{
				cout << "Strange command\n";
				break;
			}
		}
		system("pause");
	}
	delete[] array.Array;
	cout << endl << "Work is done" << endl;
	cout << endl;
	system("pause");
	return 0;
}