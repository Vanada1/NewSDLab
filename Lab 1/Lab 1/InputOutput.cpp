#include <iostream>
#include "InputOutput.h"

using namespace std;

//TODO: Naming(Done)
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