#include <iostream>
#include "StackMenu.h"
#include "InputOutput.h"

using namespace std;

void StackMenu()
{
	Stack* stack = new Stack();
	//TODO: RSDN
	bool IsNotDelete = false;
	bool ending = true;
	//TODO: Почему здесь?
	int control = 0;
	int number = 0;

	while (ending)
	{
		system("pause");
		system("cls");
		ShowStackQueue(stack);
		TextOutput("Stak_menu.txt");
		control = Write();
		switch (control)
		{
			//TODO: RSDN
		case 1:
			cout << "Enter the element\n";
			number = Write();
			stack->Push(number);
			break;
		case 2:
			number = stack->Pop();
			if (number == -1)
			{
				cout << "Nothing return\n";
			}
			else
			{
				cout << "Number " << number << " out of line\n";
			}
			break;
		case 3:
			stack->ClearStack();
			break;
		case 9:
			ending = false;
			break;
		default:
			cout << "Wrong\n";
			break;
		}
	}
	stack->ClearStack();
	delete stack;
}