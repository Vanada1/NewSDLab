#include <iostream>
#include"InputOutput.h"
#include"MenuQueueStack.h"
#include"QueueTwoStack.h"

using namespace std;

void MenuQueueStack()
{
	//TODO: Naming(Done)
	QueueTwoStack* queue = new QueueTwoStack();
	bool IsNotDelete = false;
	bool isEnd = false;
	//TODO: Почему здесь?(DOne)

	while (!isEnd)
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
		switch (ReadInt())
		{
			//TODO: RSDN(Done)
			case 1:
			{
				cout << "Enter the element\n";
				int number = ReadInt();
				queue->Enqueue(number);
				break;
			}
			case 2:
			{
				int number; 
				if (queue->Dequeue(number))
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
				queue->Delete();
				IsNotDelete = false;
				break;
			}
			case 9:
			{
				isEnd = true;
				break;
			}
			default:
			{
				cout << "Wrong\n";
				break;
			}
		}
	}
	//TODO: вынести в метод (Done)
	queue->ClearQueue();
	delete queue;
}