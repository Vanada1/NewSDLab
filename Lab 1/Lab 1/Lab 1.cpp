#include <iostream>
#include <ctime>
#include "InputOutput.h"
#include "Realisation.h"

using namespace std;

int main()
{
	srand(time(nullptr));

	int index = 0;
	int number = 0;
	int control = 0;
	bool ending = true;
	//TODO:rsdn
	DynamicArray* arr = new DynamicArray;
	CreatArray(arr);

	while (ending)
	{
		system("cls");
		OutputArray(arr);
		cout << "What do you want to do with the array?\n";
		TextOutput();
		control = Write();
		switch (control)
		{
			//TODO:rsdn
		case 1:
			cout << "Which element you want to delete\t";
			index = Write();
			if (RemoveElement(arr, index))
			{
				cout << "Done\n";
			}
			else
			{
				cout << "Error\n";
			}
			break;

		case 2:
			cout << "Enter the number\n";
			number = Write();
			if (AddElement(arr, number, 0))
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
			if (AddElement(arr, number, arr->Lenght))
			{
				cout << "Done\n";
			}
			else
			{
			cout << "Error\n";
			}
			break;

		case 4:
			cout << "Enter the index\n";
			index = Write();
			cout << "Enter the number\n";
			number = Write();
			if (AddElement(arr, number, index + 1))
			{
				cout << "Done\n";
			}
			else
			{
				cout << "Error\n";
			}
			break;
		case 5:
			SortArray(arr);
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
		system("pause");
	}
	delete[] arr->Array;
	delete arr;
	cout << endl << "Work is done" << endl;
	cout << endl;
	system("pause");
	return 0;
}