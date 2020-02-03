#include <iostream>
#include <fstream>
#include <string>
#include"InputOutput.h"

using namespace std;

int Write()
{
	int error;
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
		cout << "Ring\n";
		if (ring.Front <= ring.Tail)
		{
			//TODO: Дубль
			for (int i = ring.Front; i <= ring.Tail; i++)
			{
				cout << ring.Array[i] << "\t";
			}
		}
		else
		{
			//TODO: Дубль
			for (int i = ring.Front; i < ring.Compasity; i++)
			{
				cout << ring.Array[i] << "\t";
			}
			for (int i = 0; i <= ring.Tail; i++)
			{
				cout << ring.Array[i] << "\t";
			}
		}
		cout << endl;
		FreePlace(ring.Compasity, ring.Size);
		OccupiedPlace(ring.Size);
	}
}

void Error()
{
	cout << "Error\n";
}

//TODO: Naming
void FreePlace(int compasity, int size)
{
	cout << "Free place " << compasity - size << endl;
}

void OccupiedPlace(int size)
{
	cout << "Occupied place " << size << endl;
}

void TextOutput(string str)
{
	string line;

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