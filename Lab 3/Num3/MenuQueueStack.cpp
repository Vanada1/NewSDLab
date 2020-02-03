#include <iostream>
#include"InputOutput.h"
#include"MenuQueueStack.h"
#include"QueueTwoStack.h"

using namespace std;

void MenuQueueStack()
{
	//TODO: Naming
	QueueTwoStack* stack = new QueueTwoStack();
	bool IsNotDelete = false;
	bool ending = true;
	//TODO: Почему здесь?
	int control = 0;
	int number = 0;

	while (ending)
	{
		system("pause");
		system("cls");
		if (!IsNotDelete)
		{
			stack->CreateQueue();
			IsNotDelete = true;
		}
		ShowStackQueue(stack->Main);
		TextOutput("QueueStak_menu.txt");
		control = Write();
		switch (control)
		{
			//TODO: RSDN
		case 1:
			cout << "Enter the element\n";
			number = Write();
			stack->Enqueue(number);
			break;
		case 2:
			number = stack->Dequeue();
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
			stack->Delete();
			IsNotDelete = false;
			break;
		case 9:
			ending = false;
			break;
		default:
			cout << "Wrong\n";
			break;
		}
	}
	//TODO: Вынести в метод?
	stack->Main->ClearStack();
	stack->Peripheral->ClearStack();
	delete stack;
}