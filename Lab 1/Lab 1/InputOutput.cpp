#include <iostream>
#include "InputOutput.h"

using namespace std;

//TODO: Naming(Done)
int ReadInt()
{
	bool isNotInt;
	//TODO: Naming(Done)
	int number;
	do
	{
		isNotInt = false;
		cin >> number;
		if (cin.fail())
		{
			cout << "Wrong" << endl;
			isNotInt = true;
			cin.clear();
			cin.ignore(80, '\n');

		}
	} while (isNotInt);
	return number;
}

void OutputArray(DynamicArray& arr)
{
	for (int i = 0; i < arr.Lenght; i++)
	{
		cout << arr.Array[i] << "\t";
	}
	cout << endl;
}

void ShowResult(bool isDone)
{
	if(isDone)
	{
		cout << "Done\n";
	}
	else
	{
		cout << "Error\n";
	}
}