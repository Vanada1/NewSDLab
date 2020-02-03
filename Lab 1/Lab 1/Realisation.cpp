#include <iostream>
#include "Realisation.h"

using namespace std;
//TODO:rsdn
int const CAP = 4;

bool AddElement(DynamicArray* arr, int number, int index)
{
	if (arr->Lenght + 1 > arr->Capacity)
	{
		Resize(arr);
	}

	arr->Lenght++;

	if (index >= arr->Lenght)
	{
		arr->Lenght--;
		return false;
	}

	for (int i = index; i < arr->Lenght; i++)
	{
		//TODO:rsdn
		int temp;
		temp = arr->Array[i];
		arr->Array[i] = number;
		number = temp;
	}
	return true;
}

//TODO: return value
void CreatArray(DynamicArray* arr)
{
	arr->Capacity = CAP;
	arr->Lenght = 0;
	arr->Array = new int[arr->Capacity];
	//TODO:rsdn
	for (int i = 0; i < arr->Capacity;) {
		arr->Array[i] = rand() % 100;
		arr->Lenght++;
		i++;
	}
}

void Resize(DynamicArray* arr)
{
	int* temp = new int[arr->Capacity];
	for (int i = 0; i < arr->Lenght;)
	{
		temp[i] = arr->Array[i];
		i++;
	}
	delete[] arr->Array;
	arr->Capacity += CAP;
	arr->Array = temp;
	delete[] temp;
}

bool RemoveElement(DynamicArray* arr, int index)
{
	if (index >= arr->Lenght)
	{
		return false;
	}
	for (int i = index; i < arr->Lenght; i++)
	{
		arr->Array[i] = arr->Array[i + 1];
	}
	arr->Lenght--;
	return true;
}

void SortArray(DynamicArray* arr)
{
	int counter = 0;
	//TODO:rsdn
	for (int i = 1; i < arr->Lenght; i++) {
		for (int j = i; j > 0 && arr->Array[j - 1] > arr->Array[j]; j--)
		{
			counter++;
			int tmp = arr->Array[j - 1];
			arr->Array[j - 1] = arr->Array[j];
			arr->Array[j] = tmp;
		}
	}
}

bool LineSearch(DynamicArray* arr, int requiredKey, int& index)
{
	for (int i = 0; i < arr->Lenght; i++)
	{
		if (arr->Array[i] == requiredKey)
		{
			index = i;
			return true;
		}
	}
	return false;
}

bool BinarySearch(DynamicArray* arr, int number, int& index)
{
	int midd = 0;
	int right = arr->Lenght;
	int left = 0;
	while (true)
	{
		midd = (left + right) / 2;
		if (number < arr->Array[midd])
		{
			right = midd - 1;
		}
		else if (number > arr->Array[midd])
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

bool CheckSort(DynamicArray* arr)
{
	for (int i = 0; i < arr->Lenght - 1; i++)
	{
		if (arr->Array[i] > arr->Array[i + 1])
		{
			return false;
		}
	}
	return true;
}