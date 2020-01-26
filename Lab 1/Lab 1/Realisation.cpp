#include <iostream>
#include "Realisation.h"
#include<list>
#include<cmath>
#include <fstream>
#include <string>

using namespace std;

int const CAP = 4;

void AddElement(DynamicArray& arr, int number, int index)
{
	if (arr.lenght + 1 > arr.capacity)
	{
		Resize(arr);
	}

	arr.lenght++;

	if (index >= arr.lenght)
	{
		cout << "error" << endl;
		arr.lenght--;
		return;
	}

	for (int i = index; i < arr.lenght; i++)
	{
		int temp;
		temp = arr.array[i];
		arr.array[i] = number;
		number = temp;
	}
}

void CreatArray(DynamicArray& arr)
{
	arr.capacity = CAP;
	arr.lenght = 0;
	arr.array = new int[arr.capacity];

	for (int i = 0; i < arr.capacity;) {
		arr.array[i] = rand() % 100;
		arr.lenght++;
		i++;
	}
}

void Resize(DynamicArray& arr)
{
	int* temp = new int[arr.capacity];
	for (int i = 0; i < arr.lenght;)
	{
		temp[i] = arr.array[i];
		i++;
	}
	delete[] arr.array;
	arr.capacity += CAP;
	arr.array = new int[arr.capacity];
	for (int i = 0; i < arr.lenght;)
	{
		arr.array[i] = temp[i];
		i++;
	}
	delete[] temp;
}

void DeletElement(DynamicArray& arr, int index)
{
	if (index >= arr.lenght)
	{
		cout << "error" << endl;

		return;
	}
	for (int i = index; i < arr.lenght; i++)
	{
		arr.array[i] = arr.array[i + 1];
	}
	arr.lenght--;
}

void Sort(DynamicArray& arr)
{
	int counter = 0;
	for (int i = 1; i < arr.lenght; i++) {
		for (int j = i; j > 0 && arr.array[j - 1] > arr.array[j]; j--)
		{
			counter++;
			int tmp = arr.array[j - 1];
			arr.array[j - 1] = arr.array[j];
			arr.array[j] = tmp;
		}
	}
	cout << counter << endl;
}

bool LineSearch(DynamicArray& arr, int requiredKey, int& index)
{
	for (int i = 0; i < arr.lenght; i++)
	{
		if (arr.array[i] == requiredKey)
		{
			index = i;
			return true;
		}
	}
	return false;
}

bool BinarySearch(DynamicArray& arr, int number, int& index)
{
	int midd = 0;
	int right = arr.lenght;
	int left = 0;
	while (true)
	{
		midd = (left + right) / 2;
		if (number < arr.array[midd])
		{
			right = midd - 1;
		}
		else if (number > arr.array[midd])
		{
			left = midd + 1;
		}
		else
		{
			index = midd;
			return true;
		}
		if (left > right)
		{
			return false;
		}
	}
}

bool CheckSort(DynamicArray& arr)
{
	for (int i = 0; i < arr.lenght - 1; i++)
	{
		if (arr.array[i] > arr.array[i + 1])
		{
			return false;
		}
	}
	return true;
}

//Input and Output

int Write()
{
	bool error;
	int num;
	do
	{
		error = false;
		cin >> num;
		if (cin.fail())
		{
			cout << "Wrong" << endl;
			error = true;
			cin.clear();
			cin.ignore(80, '\n');

		}
	} while (error);
	return num;
}

void OutputArray(DynamicArray& arr)
{
	for (int i = 0; i < arr.lenght; i++)
	{
		cout << arr.array[i] << "\t";

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