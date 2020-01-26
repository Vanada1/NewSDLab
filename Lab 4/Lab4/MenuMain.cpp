#include <iostream>
#include "InputOutput.h"
#include "menuDictionary.h"
#include "menuHash.h"

using namespace std;

int main()
{
	int control = 0;
	bool ending = true;
	while (ending)
	{
		system("pause");
		system("cls");
		TextOutput("main.txt");
		control = WriteInt();
		switch (control)
		{
		case 1:
			MenuDictionary();
			break;

		case 2:
			MenuHash();
			break;
		case 9:
			ending = false;
			break;
		}
	}
}
