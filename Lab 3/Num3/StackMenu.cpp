#include <iostream>
#include "StackMenu.h"
#include "InputOutput.h"
#include"WorkWithFiles.h"

using namespace std;

void StackMenu()
{
	Stack* stack = new Stack();
	bool isNotDelete = false;
	bool ending = true;
	//TODO: Почему здесь?(Done)

	while (ending)
	{
		system("pause");
		system("cls");
		ShowStackQueue(stack);
		TextOutput("Stak_menu.txt");
		switch (ReadInt())
		{
			//TODO: {}(Done)
			case 1:
			{
				cout << "Enter the element\n";
				int number = ReadInt();
				stack->Push(number);
				break; 
			}

			case 2:
			{
				int number = stack->Pop();
				if (number == -1)
				{
					cout << "Nothing return\n";
				}
				else
				{
					cout << "Number " << number << " out of line\n";
				}
				break;
			}
			case 3:
			{
				stack->ClearStack();
				break;
			}
			case 9:
			{
				ending = false;
				break;
			}
			default:
			{
				cout << "Wrong\n";
				break;
			}
		}
	}
	stack->ClearStack();
	delete stack;
}