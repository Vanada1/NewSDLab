#include <iostream>
#include "BinaryMenu.h"
#include "TreapMenu.h"
#include "InputOutput.h"
#include "WorkWithFiles.h"

using namespace std;

int main()
{
	bool isEnd = false;

	while (!isEnd)
	{
		system("cls");
		TextOutput("mainMenu.txt");
		switch (ReadInt())
		{
			//TODO: RSDN(Done)
			case 1:
			{
				BinaryTreeMenu();
				break;
			}
			case 2:
			{
				TreapMenu();
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
		system("pause");
	}
}