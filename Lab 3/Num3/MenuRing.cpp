#include <iostream>
#include"InputOutput.h"
#include "MenuRing.h"
#include"RingBuffer.h"

using namespace std;

void MenuRing()
{
	//TODO: Нужна динамика, а не статика
	RingBuffer struc;
	struc.CreateBuffer();
	bool ending = true;
	//TODO: Почему здесь?
	int control = 0;
	int number = 0;

	while (ending)
	{
		system("pause");
		system("cls");
		ShowRingBuf(struc.Ring);
		TextOutput("QueueRingBuff_menu.txt");
		control = Write();
		switch (control)
		{
			//TODO: RSDN
		case 1:
			cout << "Enter the element\n";
			number = Write();
			struc.AddElement(number);
			cout << "Added\n";
			break;
		case 2:
			number = struc.GetElement();
			OutputNumberRing(number);
			break;
		case 3: 
			struc.DeleteRingBuf();
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
	struc.DeleteRingBuf();
}