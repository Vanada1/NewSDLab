#include <iostream>
#include"InputOutput.h"
#include "MenuQueueRing.h"
#include"QueueRing.h"

using namespace std;

void MenuQueueRing()
{
	QueueRing struc;
	struc.CreateQueue();
	//TODO: naming
	bool ending = true;

	while (ending)
	{
		system("pause");
		system("cls");
		ShowRingBuf(struc.Buffer->Ring);
		TextOutput("QueueRingBuff_menu.txt");
		 
		switch (Write())
		{
			//TODO: {}
			case 1:
			{
				cout << "Enter the element\n";
				int number = Write();
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
				struc.Delete();
				cout << "Ring deleted\n";
				break;
			case 4:
				struc.Resize();
				break;
			case 9:
				ending = false;
				break;
			default:
				cout << "Wrong\n";
				break;
		}
	}
	struc.Delete();
}