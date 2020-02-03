#include <iostream>
#include <fstream>
#include <string>
#include "InputOutput.h"

using namespace std;

int Write()
{
	bool isNotInt;
	int num;
	do
	{
		isNotInt = false;
		cin >> num;
		if (cin.fail())
		{
			cout << "Wrong" << endl;
			isNotInt = true;
			cin.clear();
			cin.ignore(80, '\n');

		}
	} while (isNotInt);
	return num;
}

void OutputArray(DynamicArray* arr)
{
	for (int i = 0; i < arr->Lenght; i++)
	{
		cout << arr->Array[i] << "\t";

	}
	cout << endl;
}

void TextOutput()
{
	string line;

	ifstream fil("menu.txt");
	if (fil.is_open())
	{
		while (getline(fil, line))
		{
			cout << line << endl;
		}
	}
	else
	{
		cout << "Error: cannot open the file";
	}
	fil.close();
}