#include "TreapMenu.h"
#include "Treap.h"
#include "WorkWithFiles.h"

void TreapMenu()
{
	srand(time(nullptr));
	Treap* tree = new Treap();
	bool isEnd = false;
	cout << "Enter the count of elemetns\t";
	tree->CreateTree(ReadInt());
	cout << endl;

	while (!isEnd)
	{
		system("pause");
		system("cls");
		ShowTreap(tree->Root, 0);
		cout << endl;
		TextOutput("TreapMemu.txt");
		switch (ReadInt())
		{
			case 1:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				cout << endl;
				int priority = tree->SearchElement(number);
				if (priority >= 0)
				{
					cout << priority << endl;
				}
				else
				{
					cout << "Not found\n";
				}
				cout << endl;
				break;
			}
			case 2:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				tree->Root = tree->AddUnoptimized(number, rand() % 100);
				break;
			}
			case 3:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				tree->AddOptimized(number, rand() % 100);
				break;
			}
			case 4:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				tree->Root = tree->RemoveUnoptimized(number);
				break;
			}
			case 5:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				tree->RemoveOptimized(number);
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