#include <iostream>
#include"InputOutput.h"

using namespace std;

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

void OutputError()
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