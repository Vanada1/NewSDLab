#include <iostream>
#include <ctime>
#include "R-BTree.h"
#include "R-BTreeMenu.h"
#include "InputOutput.h"
#include "ConsoleColor.h"
#include "WorkWithFiles.h"

using namespace std;

void RBTreeMenu()
{
	srand(time(nullptr));
	bool isEnd = false;
	RBTree* tree = new RBTree();
	RBTreeNode* searchedElem = nullptr;
	cout << "How many elements to create ";
	int number = ReadInt();
	for (int i = 0; i < number; i++)
	{
		tree->Insert(rand() % 100);
	}

	while (!isEnd)
	{
		system("cls");
		PrintTree(tree->Root, 0, tree->Nil);
		SetColor(Cyan, Black);
		cout << "\nCyan = Black\n";
		SetColor(Red, Black);
		cout << "\nRed = Red\n\n";
		SetColor(White, Black);
		TextOutput("RedBlackTreeMenu.txt");
		switch (ReadInt())
		{
			case 1:
			{
				cout << "Enter the number\n";
				number = ReadInt();
				if (tree->Insert(number))
				{
					OutputDone();
				}
				else
				{
					Error();
				}
				break;
			}
			case 2:
			{
				cout << "Enter the number\n";
				number = ReadInt();
				if (tree->SearchElem(searchedElem, number))
				{
					tree->DeleteElem(searchedElem);
				}
				else
				{
					OutputNone();
				}
				break;
			}
			case 3:
			{
				cout << "Enter the number\n";
				number = ReadInt();
				if (tree->SearchElem(searchedElem, number))
				{
					cout << "The number is found \n";
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
		system("pause");
	}
	if (!tree->Root)
	{
		tree->ClearTree(tree->Root);
	}
	delete tree->Nil;
	delete tree;
}