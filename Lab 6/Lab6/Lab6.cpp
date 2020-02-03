#include <iostream>
#include "R-BTreeMenu.h"
#include "ALVTreeMenu.h"
#include "InputOutput.h"
#include "ConsoleColor.h"

using namespace std;

int main()
{
	bool ending = true;
	//TODO: Почему здесь?
	int control = 0;

	while (ending)
	{
		SetColor(White, Black);
		system("cls");
		TextOutput("mainMenu.txt");
		control = WriteInt();
		switch (control)
		{
			//TODO: RSDN
		case 1:
			RBTreeMenu();
			break;
		case 2:
			ALVTreeMenu();
			break;
		case 9:
			ending = false;
			break;
		default:
			cout << "Strange comand\n";
			break;
		}
	}
}