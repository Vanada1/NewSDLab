#include <iostream>
#include"InputOutput.h"

void ShowBinaryTree(BinaryTreeNode* node, int level)
{
	if (node)
	{
		ShowBinaryTree(node->Right, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "	";
		}
		cout << node->Data << endl;
		ShowBinaryTree(node->Left, level + 1);
	}
}

void ShowList(List* main)
{
	if (main == nullptr)
	{
		cout << "Not found\n";
	}
	else
	{
		Node* showElement = main->Top;
		cout << "Result\n";
		while (showElement != nullptr)
		{
			cout << showElement->Data << '\t';
			showElement = showElement->Next;
		}
		cout << endl;
	}
}

void ShowTreap(TreapNode* node, int level)
{
	if (node)
	{
		ShowTreap(node->Right, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "	";
		}
		cout << '(' << node->Key << "; " << node->Priority << ')' << endl;
		ShowTreap(node->Left, level + 1);
	}
}
