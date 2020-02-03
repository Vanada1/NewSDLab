#include <iostream>
#include "ListFunc.h"
#include "InputOutput.h"
#include <ctime>

using namespace std;

int main()
{
	srand(time(nullptr));

	bool ending = true;
	//TODO:rsdn
	List* lst = new List();
	//TODO: RSDN
	int quantity = 0;
	int control = 0;
	int number = 0;
	int index = 0;
	long double elapsed_secs = 0;

	cout << "Enter the number of elements" << endl;
	quantity = Write();
	cout << endl;

	clock_t begin = clock();
	for (int i = 0; i < quantity; i++)
	{
		InsertInList(lst, rand() % 100, lst->Size, elapsed_secs);
	}
	clock_t end = clock();
	elapsed_secs = FuncCounting(begin, end);
	OutputTime(elapsed_secs, "create of list ");

	while (ending)
	{
		system("pause");
		system("cls");
		OutputList(lst);
		cout << "What do you want to do with the array?\n";
		TextOutput();
		control = Write();

		switch (control)
		{
			//TODO:rsdn
		case 1:
			cout << "Enter index\n";
			index = Write();
			if (DeleteElement(lst, index, elapsed_secs))
			{
				Done();
				OutputTime(elapsed_secs, "delete element ");
			}
			else
			{
				Error();
			}
			break;
		case 2:
			cout << "Enter the number\n";
			number = Write();
			if(InsertInList(lst, number, 0, elapsed_secs))
			{
				Done();
				OutputTime(elapsed_secs, "add element ");
			}
			else
			{
				Error();
			}
			break;
		case 3:
			cout << "Enter the number\n";
			number = Write();
			if (InsertInList(lst, number, lst->Size, elapsed_secs))
			{
				Done();
				OutputTime(elapsed_secs, "add element ");
			}
			else
			{
				Error();
			}
			break;
		case 4:
			cout << "Enter the number\n";
			number = Write();
			cout << "Enter index\n";
			index = Write();
			if (InsertInList(lst, number, index + 1, elapsed_secs))
			{
				Done();
				OutputTime(elapsed_secs, "add element ");
			}
			else
			{
				Error();
			}
			break;
		case 5:
			cout << "Enter the number\n";
			number = Write();
			cout << "Enter index\n";
			index = Write();
			if (InsertInList(lst, number, index, elapsed_secs))
			{
				Done();
				OutputTime(elapsed_secs, "add element ");
			}
			else
			{
				Error();
			}
			break;
		case 6:
			Sort(lst);
			break;
		case 7:
			cout << "What number do you want to find?\n";
			number = Write();
			index = NULL;
			if (LineSearch(lst, number, index))\
			{
				cout << "The numder " << number << " in " << index << " cell\n";
			}
			else
			{
				cout << "Not found\n";
			}
			break;
		case 8:
			OutputListBack(lst);
			break;
		case 9:
			ending = false;
			break;
		case 10:
			cout << "Insert quantity \n";
			cin >> quantity;
			OutputTime(AddElement(lst, quantity), "add elements ");
		default:
			break;
		}
	}
	DeleteList(lst);
	cout << endl << "Work is done" << endl;
	cout << endl;
	system("pause");
}