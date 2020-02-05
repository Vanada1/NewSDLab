#include <iostream>
#include <fstream>
#include <string>
#include"InputOutput.h"

using namespace std;

//TODO: Naming
int Write()
{
	int error;
	//TODO: Naming
	int num;
	do
	{
		error = 0;
		cin >> num;
		if (cin.fail())
		{
			cout << "Wrong\n";
			error = 1;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);
	return num;
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

void ShowRingBuf(RingBuf& ring)
{
	if (IsNothing(ring.Front, ring.Tail))
	{
		cout << "No buffer\n";
	}
	else
	{
		int temp = ring.Front;
		cout << "Ring\n";
		if (ring.Front > ring.Tail)
		{
			for (int i = temp; i < ring.Capacity; i++)
			{
				cout << ring.Array[i] << "\t";
			}
			temp = 0;
		}
		for (int i = temp; i <= ring.Tail; i++)
		{
			cout << ring.Array[i] << "\t";
		}
		cout << endl;
		FreeSpace(ring.Capacity, ring.Size);
		OccupiedSpace(ring.Size);
	}
}

void Error()
{
	cout << "Error\n";
}
//TODO: Naming
void FreeSpace(int compasity, int size)
{
	cout << "Free place " << compasity - size << endl;
}

void OccupiedSpace(int size)
{
	cout << "Occupied place " << size << endl;
}

void TextOutput(string str)
{
	string line;
	//TODO: naming
	ifstream fil(str);
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