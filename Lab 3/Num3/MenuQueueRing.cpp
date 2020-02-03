#include <iostream>
#include"InputOutput.h"
#include "MenuQueueRing.h"
#include"QueueRing.h"

using namespace std;

void MenuQueueRing()
{
	QueueRing struc;
	struc.CreateQueue();
	bool ending = true;
	//TODO: Почему здесь?
	int control = 0;
	int number = 0;

	while (ending)
	{
		system("pause");
		system("cls");
		ShowRingBuf(struc.Buffer->Ring);
		TextOutput("QueueRingBuff_menu.txt");
		control = Write();
		switch (control)
		{
		case 1:
			cout << "Enter the element\n";
			number = Write();
			struc.Enqueue(number);
			cout << "Added\n";
			break;
		case 2:
			number = struc.Dequeue();
			OutputNumberRing(number);
			break;
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