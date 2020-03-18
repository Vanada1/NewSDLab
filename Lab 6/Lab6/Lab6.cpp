#include <iostream>
#include "R-BTreeMenu.h"
#include "ALVTreeMenu.h"
#include "InputOutput.h"
#include "ConsoleColor.h"
#include "../../CommonFuction/WorkWithFiles.h"

using namespace std;

int main()
{
	bool isEnd = false;

	while (!isEnd)
	{
		SetColor(White, Black);
		system("cls");
		TextOutput("mainMenu.txt");
		switch (ReadInt())
		{
			case 1:
			{
				RBTreeMenu();
				break;
			}
			case 2:
			{
				ALVTreeMenu();
				break;
			}
			case 9:
			{
				isEnd = true;
				break;
			}
			default:
			{
				cout << "Strange comand\n";
				break;
			}
		}
	}
}