#include "InputOutput.h"
#include <iomanip>

using namespace std;

// функция "умного" ввода
int ReadInt()
{
	int isNotInt;
	//TODO: naming(Done)
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

void OutputList(List* lst)
{
	Node* temp = lst->Head;
	while (temp != nullptr)
	{
		cout << temp->Data << '\t';
		temp = temp->Next;
	}
	cout << endl;
	cout << "Size of list: " << lst->Size << endl;
}

void OutputListBack(List* lst)
{
	Node* temp = lst->Tail;
	while (temp != nullptr)
	{
		cout << temp->Data << '\t';
		temp = temp->Perv;
	}
	cout << endl;
	cout << "Size of list: " << lst->Size << endl;
}

void Error()
{
	cout << "Error\n";
}

void Done()
{
	cout << "Done\n";
}

void OutputTime(long double time, string word)
{
	cout << "Time of processing for " << word << setprecision(12)
		<< time << endl;
}