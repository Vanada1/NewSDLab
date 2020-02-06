#include "InputOutput.h"
#include <iomanip>

using namespace std;

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

void OutputError()
{
	cout << "Error\n";
}

void OutputDone()
{
	cout << "Done\n";
}

void OutputTime(long double time, string word)
{
	cout << "Time of processing for " << word << setprecision(12)
		<< time << endl;
}