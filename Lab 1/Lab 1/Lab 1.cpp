#include <iostream>
#include "Realisation.h"
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	int index = 0;
	int number = 0;
	int control = 0;
	bool ending = true;
	DynamicArray arr;
	CreatArray(arr);

	while (ending)
	{
		system("pause");
		system("cls");
		OutputArray(arr);
		cout << "What do you want to do with the array?\n";
		TextOutput();
		control = Write();
		switch (control)
		{
		case 1:
			cout << "Which element you want to delete\t";
			index = Write();
			DeletElement(arr, index);
			break;

		case 2:
			cout << "Enter the number\n";
			number = Write();
			AddElement(arr, number, 0);
			break;

		case 3:
			cout << "Enter the number\n";
			number = Write();
			AddElement(arr, number, arr.lenght);
			break;

		case 4:
			cout << "Enter the index\n";
			index = Write();
			cout << "Enter the number\n";
			number = Write();
			AddElement(arr, number, index + 1);
			break;
		case 5:
			Sort(arr);
			break;
		case 6:
			cout << "What number are you looking for?\n";
			number = Write();
			if (LineSearch(arr, number, index))
			{
				cout << "Number " << number << " in " << index << endl;
			}
			else
			{
				cout << "There is no such number in this array\n";
			}
			break;

		case 7:
			if (CheckSort(arr))
			{
				cout << "What number are you looking for?\n";
				number = Write();
				if (BinarySearch(arr, number, index))
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
	}
	delete[] arr.array;
	cout << endl << "Work is done" << endl;
	cout << endl;
	system("pause");
	return 0;
}