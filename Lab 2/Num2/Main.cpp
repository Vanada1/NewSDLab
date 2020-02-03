#include <iostream>
#include "Function.h"
#include <ctime>

using namespace std;

int main()
{
	//TODO: nullptr
	srand(time(NULL));

	bool ending = true;
	//TODO:rsdn
	List* lst = new List();
	//TODO: RSDN
	int quantity = 0;
	int control = 0;
	int number = 0;
	int index = 0;

	cout << "Enter the number of elements" << endl;
	quantity = Write();
	cout << endl;

	//clock_t begin = clock();
	for (int i = 0; i < quantity; i++)
	{
		InsertInList(lst, rand() % 100, lst->Size);
	}
	//clock_t end = clock();
	//long double elapsed_secs = long double(end - begin) / CLOCKS_PER_SEC;
	//OutputTime(elapsed_secs, "create of list ");

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
			DeleteElement(lst, index);
			break;
		case 2:
			cout << "Enter the number\n";
			number = Write();
			InsertInList(lst, number, 0);
			break;
		case 3:
			cout << "Enter the number\n";
			number = Write();
			InsertInList(lst, number, lst->Size);
			break;
		case 4:
			cout << "Enter the number\n";
			number = Write();
			cout << "Enter index\n";
			index = Write();
			InsertInList(lst, number, index + 1);
			break;
		case 5:
			cout << "Enter the number\n";
			number = Write();
			cout << "Enter index\n";
			index = Write();
			InsertInList(lst, number, index);
			break;
		case 6:
			Sort(lst);
			break;
		case 7:
			cout << "What number do you want to find?\n";
			number = Write();
			LineSearch(lst, number);
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
			AddElement(lst, quantity);
		default:
			break;
		}
	}
	DeleteList(lst);
	cout << endl << "Work is done" << endl;
	cout << endl;
	system("pause");
}