#include <iostream>
#include"InputOutput.h"
#include"MenuQueueStack.h"
#include"QueueTwoStack.h"

using namespace std;

void MenuQueueStack()
{
	QueueTwoStack* queue = new QueueTwoStack();
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
			queue->CreateQueue();
			IsNotDelete = true;
		}
		ShowStackQueue(queue->Main);
		TextOutput("QueueStak_menu.txt");
		control = Write();
		switch (control)
		{
			//TODO: RSDN
		case 1:
			cout << "Enter the element\n";
			number = Write();
			queue->Enqueue(number);
			break;
		case 2:
			number = queue->Dequeue();
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
			queue->Delete();
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
	queue->ClearQueue();
	delete queue;
}