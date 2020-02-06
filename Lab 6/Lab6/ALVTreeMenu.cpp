#include "ALVTreeMenu.h"
#include "WorkWithFiles.h"

void ALVTreeMenu()
{
	bool isEnd = false;
	ALVTree* tree = new ALVTree();
	cout << "Enter the count of elemetns\t";
	int number = ReadInt();
	srand(time(nullptr));
	for (int i = 0; i < number; i++)
	{
		tree->Root = tree->AddElement(tree->Root, rand() % 100);
	}
	cout << endl;

	while (!isEnd)
	{
		system("pause");
		system("cls");
		ALVTreeShow(tree->Root, 0);
		cout << endl;
		TextOutput("ALVTreeMenu.txt");
		switch (ReadInt())
		{
			case 1:
			{
				cout << "Enter the number\n";
				number = ReadInt();
				tree->Root = tree->AddElement(tree->Root, number);
				break;
			}
			case 2:
			{
				cout << "Enter the number\n";
				number = ReadInt();
				tree->Root = tree->RemoveElement(tree->Root, number);
				break;
			}
			case 3:
			{
				cout << "Enter the number\n";
				number = ReadInt();
				cout << endl;
				if (tree->SearchElement(number))
				{
					OutputDone();
				}
				else
				{
					OutputNone();
				}
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
	if (tree->Root != nullptr)
	{
		tree->DeleteTree(tree->Root);
	}
	delete tree;
}