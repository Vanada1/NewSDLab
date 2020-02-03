#include <iostream>
#include <ctime>
#include "R-BTree.h"
#include "R-BTreeMenu.h"
#include "InputOutput.h"
#include "ConsoleColor.h"

using namespace std;

void RBTreeMenu()
{
	//TODO: nullptr
	srand(time(NULL));
	bool ending = true;
	//TODO: Почему здесь?
	int control = 0;
	int number = 0;
	//TODO: RSDN
	RBTree* Tree = new RBTree();
	RBTreeNode* searchedElem = nullptr;
	cout << "How many elements to create ";
	number = WriteInt();
	for (int i = 0; i < number; i++)
	{
		Tree->Insert(rand() % 100);
	}

	while (ending)
	{
		system("cls");
		PrintTree(Tree->Root, 0, Tree->Nil);
		SetColor(Cyan, Black);
		cout << "\nCyan = Black\n";
		SetColor(Red, Black);
		cout << "\nRed = Red\n\n";
		SetColor(White, Black);
		TextOutput("RedBlackTreeMenu.txt");
		control = WriteInt();
		switch (control)
		{
			//TODO: RSDN
		case 1:
			cout << "Enter the number\n";
			number = WriteInt();
			if (Tree->Insert(number))
			{
				Done();
			}
			else
			{
				Error();
			}
			break;
		case 2:
			cout << "Enter the number\n";
			number = WriteInt();
			if (Tree->SearchElem(searchedElem, number))
			{
				Tree->DeleteElem(searchedElem);
			}
			else
			{
				None();
			}
			break;
		case 3:
			cout << "Enter the number\n";
			number = WriteInt();
			if (Tree->SearchElem(searchedElem, number))
			{
				cout << "The number is found \n";
			}
			else
			{
				None();
			}
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
	if (!Tree->Root)
	{
		Tree->ClearTree(Tree->Root);
	}
	delete Tree->Nil;
	delete Tree;
}