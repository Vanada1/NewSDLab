#include <iostream>
#include"InputOutput.h"

using namespace std;

//TODO: Naming(Done)
int ReadInt()
{
	int isNotInt;
	//TODO: Naming(Done)
	int number;
	do
	{
		isNotInt = 0;
		cin >> number;
		if (cin.fail())
		{
			cout << "Wrong\n";
			isNotInt = 1;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (isNotInt == 1);
	return number;
}

void ShowStackQueue(Stack* main)
{
	if (main == nullptr)
	{
		cout << "Stack is not created\n";
	}
	else
	{
		Node* showElement = main->Top;
		cout << "Stack\n";
		while (showElement != nullptr)
		{
			cout << showElement->Data << '\t';
			showElement = showElement->Next;
		}
		cout << endl;
	}
}

void ShowRingBuf(int* array, int front, int tail, int capacity)
{
	if (IsNothing(front, tail))
	{
		cout << "No buffer\n";
	}
	else
	{
		int temp = front;
		cout << "Ring\n";
		if (front > tail)
		{
			for (int i = temp; i < capacity; i++)
			{
				cout << array[i] << "\t";
			}
			temp = 0;
		}
		for (int i = temp; i <= tail; i++)
		{
			cout << array[i] << "\t";
		}
		cout << endl;
	}
}

void Error()
{
	cout << "Error\n";
}
//TODO: Naming(Done)
void ShowFreeSpace(int compasity, int size)
{
	cout << "Free place " << compasity - size << endl;
}

void OccupiedSpace(int size)
{
	cout << "Occupied place " << size << endl;
}

void OutputNumberRing (int number)
{
	if (number == -1)
	{
		cout << "Nothing return\n";
	}
	else
	{
		cout << "Number " << number << " out of line\n";
	}
}