#include <iostream>
#include "InputOutput.h"
#include "MenuDictionary.h"
#include "MenuHashTable.h"
#include "WorkWuthFiles.h"

using namespace std;

int main()
{
	//TODO: Почему здесь?(Done)
	bool isEnd = false;
	while (!isEnd)
	{
		system("pause");
		system("cls");
		TextOutput("main.txt");
		switch (ReadInt())
		{
			//TODO: RSDN(Done)
			case 1:
			{
				MenuDictionary();
				break;
			}
			case 2:
			{
				MenuHashTable();
				break;
			}
			case 9:
			{
				isEnd = true;
				break;
			}
		}
	}
}
