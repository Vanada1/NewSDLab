#include <iostream>
#include"InputOutput.h"
#include "MenuQueueRing.h"
#include"QueueRing.h"
#include "WorkWithFiles.h"

using namespace std;

void MenuQueueRing()
{
	QueueRing struc;
	struc.CreateQueue();
	//TODO: naming(Done)
	bool isEnd = false;

	while (!isEnd)
	{
		system("pause");
		system("cls");
		ShowRingBuf(struc.Buffer->Array, struc.Buffer->Front,
			struc.Buffer->Tail, struc.Buffer->Capacity);
		TextOutput("QueueRingBuff_menu.txt");
		 
		switch (ReadInt())
		{
			//TODO: {}(Done)
			case 1:
			{
				cout << "Enter the element\n";
				int number = ReadInt();
				struc.Enqueue(number);
				cout << "Added\n";
				break;
			}
			case 2:
			{
				int number = struc.Dequeue();
				OutputNumberRing(number);
				break;
			}
			case 3:
			{
				struc.Delete();
				cout << "Ring deleted\n";
				break;
			}
			case 4:
			{
				struc.Resize();
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
	struc.Delete();
}