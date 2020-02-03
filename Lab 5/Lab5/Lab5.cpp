#include <iostream>
#include "BinaryMenu.h"
#include "TreapMenu.h"
#include "InputOutput.h"

using namespace std;

int main()
{
	bool ending = true;
	//TODO: Почему здесь?
	int control = 0;

	while (ending)
	{
		system("cls");
		TextOutput("mainMenu.txt");
		control = WriteInt();
		switch (control)
		{
			//TODO: RSDN
		case 1:
			BinaryTreeMenu();
			break;
		case 2:
			TreapMenu();
			break;
		case 9:
			ending = false;
			break;
		default:
			cout << "Strange comand\n";
			break;
		}
		system("pause");
	}
}