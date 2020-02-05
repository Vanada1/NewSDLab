#include <iostream>
#include"InputOutput.h"


int  ReadInt()
{
	bool error;
	int number;
	do
	{
		error = false;
		cin >> number;
		if (cin.fail())
		{
			cout << "Wrong\n";
			error = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error);
	return number;
}

void OutputError()
{
	cout << "Error\n";
}

void OutputNone()
{
	cout << "None\n";
}

void OutputDone()
{
	cout << "Done\n";
}

void ShowBinaryTree(BinaryTreeNode* node, int level)
{
	if (node)
	{
		ShowBinaryTree(node->Right, level + 1);
		//TODO: RSDN(Done)
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
		//TODO: RSDN(Done)
		for (int i = 0; i < level; i++)
		{
			cout << "	";
		}
		cout << '(' << node->Key << "; " << node->Priority << ')' << endl;
		ShowTreap(node->Left, level + 1);
	}
}
