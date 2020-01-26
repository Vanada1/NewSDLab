#include <iostream>
#include "MenuQueueRing.h"
#include "MenuQueueStack.h"
#include "StackMenu.h"
#include "RingMenu.h"
#include"InputOutput.h"

using namespace std;

void main()
{
	bool ending = true;
	int choise = 0;

	while (ending)
	{
		system("cls");
		TextOutput("menu_support.txt");
		choise = Write();
		switch (choise)
		{
		case 1:
			MenuQueueStack();
			break;
		case 2:
			MenuQueueRing();
			break;
		case 3:
			StackMenu();
			break;
		case 4:
			MenuRing();
			break;
		case 9:
			ending = false;
			break;
		default:
			cout << "Unknown command\n";
			break;
		}
	}
	cout << "Work is done\n\n";
}
