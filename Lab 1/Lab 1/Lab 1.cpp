#include <iostream>
#include <ctime>
#include "InputOutput.h"
#include "Realisation.h"

using namespace std;

int main()
{
	srand(time(nullptr));

	//int index = 0;
	int number = 0;
	int control = 0;
	//TODO: naming
	bool ending = true;
	//TODO:rsdn
	DynamicArray Arr;
	CreatArray(Arr);

	while (ending)
	{
		system("cls");
		OutputArray(Arr);
		cout << "What do you want to do with the array?\n";
		TextOutput();
		control = Write();
		switch (control)
		{
			//TODO:скобочки
			case 1:
			{
				cout << "Which element you want to delete\t";
				int index = Write();
				//TODO: дубль
				if (RemoveElement(Arr, index))
				{
					cout << "Done\n";
				}
				else
				{
					cout << "Error\n";
				}
				break;
			}
			case 2:
				cout << "Enter the number\n";
				number = Write();
				if (AddElement(Arr, number, 0))
				{
					cout << "Done\n";
				}
				else
				{
					cout << "Error\n";
				}
				break;

			case 3:
				cout << "Enter the number\n";
				number = Write();
				if (AddElement(Arr, number, Arr.Lenght))
				{
					cout << "Done\n";
				}
				else
				{
					cout << "Error\n";
				}
				break;

			case 4:
			{
				cout << "Enter the index\n";
				int index = Write();
				cout << "Enter the number\n";
				number = Write();
				if (AddElement(Arr, number, index + 1))
				{
					cout << "Done\n";
				}
				else
				{
					cout << "Error\n";
				}
				break;
			}
			case 5:
				SortArray(Arr);
				break;
			case 6:
			{
				cout << "What number are you looking for?\n";
				number = Write();
				int index = 0;
				if (LineSearch(Arr, number, index))
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
				if (CheckSort(Arr))
				{
					cout << "What number are you looking for?\n";
					number = Write();
					int index = 0;
					if (BinarySearch(Arr, number, index))
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

			case 9:
				ending = false;
				break;

			default:
				cout << "Strange command\n";
				break;
		}
		system("pause");
	}
	delete[] Arr.Array;
	cout << endl << "Work is done" << endl;
	cout << endl;
	system("pause");
	return 0;
}