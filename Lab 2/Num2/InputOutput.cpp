#include "Function.h"
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// функция "умного" ввода
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

void OutputList(List* lst)
{
	Node* temp = lst->Head;
	while (temp != NULL)
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
	while (temp != NULL)
	{
		cout << temp->Data << '\t';
		temp = temp->Perv;
	}
	cout << endl;
	cout << "Size of list: " << lst->Size << endl;
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

void Error()
{
	cout << "Error: Too strange index\n";
}

void FoundElement(int index, int number)
{
	cout << "The numder " << number << " in " << index << " cell\n";
}

void ResultOfSearch(int counter, int number)
{
	if (counter == 0)
	{
		cout << "The number " << number << " was not found\n";
	}
	else
	{
		cout << "The number " << number << " was found "
			<< counter << " times\n";
	}
}

void OutputTime(long double time, string word)
{
	cout << "Time of processing for " << word << setprecision(12)
		<< time << endl;
}