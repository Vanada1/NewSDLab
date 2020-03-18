#include <iostream>
#include "Realisation.h"

using namespace std;

bool AddElement(DynamicArray& arr, int number, int index)
{
	if (arr.Lenght + 1 > arr.Capacity)
	{
		Resize(&arr);
	}

	arr.Lenght++;

	if (index >= arr.Lenght)
	{
		arr.Lenght--;
		return false;
	}

	for (int i = index; i < arr.Lenght; i++)
	{
		int temp = arr.Array[i];
		arr.Array[i] = number;
		number = temp;
	}
	return true;
}

//TODO: return value
void CreatArray(DynamicArray& arr)
{
	arr.Capacity = CAPACITY;
	arr.Lenght = 0;
	arr.Array = new int[arr.Capacity];
	for (int i = 0; i < arr.Capacity; i++)
	{
		arr.Array[i] = rand() % 100;
		arr.Lenght++;
	}
}

void Resize(DynamicArray* arr)
{
	arr->Capacity += CAPACITY;
	int* temp = new int[arr->Capacity];
	for (int i = 0; i < arr->Lenght; i++)
	{
		temp[i] = arr->Array[i];
	}
	delete[] arr->Array;
	arr->Array = temp;
}

bool RemoveElement(DynamicArray& arr, int index)
{
	if (index >= arr.Lenght)
	{
		return false;
	}
	for (int i = index; i < arr.Lenght; i++)
	{
		arr.Array[i] = arr.Array[i + 1];
	}
	arr.Lenght--;
	return true;
}

void QuickSortArray(DynamicArray& arr)
{
	int counter = 0;
	for (int i = 1; i < arr.Lenght; i++) 
	{
		for (int j = i; j > 0 && arr.Array[j - 1] > arr.Array[j]; j--)
		{
			counter++;
			int tmp = arr.Array[j - 1];
			arr.Array[j - 1] = arr.Array[j];
			arr.Array[j] = tmp;
		}
	}
}

bool LineSearch(DynamicArray& arr, int requiredKey, int& index)
{
	for (int i = 0; i < arr.Lenght; i++)
	{
		if (arr.Array[i] == requiredKey)
		{
			index = i;
			return true;
		}
	}
	return false;
}

bool BinarySearch(DynamicArray& arr, int number, int& index)
{
	//TODO: naming(Done)
	int middle = 0;
	int right = arr.Lenght;
	int left = 0;
	while (true)
	{
		middle = (left + right) / 2;
		if (number < arr.Array[middle])
		{
			right = middle - 1;
		}
		else if (number > arr.Array[middle])
		{
			left = middle + 1;
		}
		else
		{
			index = middle;
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
	for (int i = 0; i < arr.Lenght - 1; i++)
	{
		if (arr.Array[i] > arr.Array[i + 1])
		{
			return false;
		}
	}
	return true;
}