#include <iostream>
#include "InputOutput.h"
#include "menuDictionary.h"
#include "menuHash.h"

using namespace std;

int main()
{
	//TODO: Почему здесь?
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
			//TODO: RSDN
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
