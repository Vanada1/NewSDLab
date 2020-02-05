#include "InputOutput.h"
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// функция "умного" ввода
int Write()
{
	int error;
	//TODO: naming
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

void TextOutput()
{
	string line;
	//TODO: Ответственности
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