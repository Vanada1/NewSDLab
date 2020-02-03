#include <iostream>
#include <fstream>
#include"InputOutput.h"


int  WriteInt()
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

void Error()
{
	cout << "Error\n";
}

void None()
{
	cout << "None\n";
}

void TextOutput(string str)
{
	string line;

	ifstream fil(str);
	if (fil.is_open())
	{
		while (getline(fil, line))
		{
			cout << line << endl;
		}
	}
	else
	{
		cout << "Error: cannot open the file";
	}
	fil.close();
}

void Done()
{
	cout << "Done\n";
}

void ShowBinaryTree(BinaryTreeNode* node, int level)
{
	if (node)
	{
		ShowBinaryTree(node->Right, level + 1);
		//TODO: RSDN
		for (int i = 0; i < level; i++) cout << "	";
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
		//TODO: RSDN
		for (int i = 0; i < level; i++) cout << "	";
		cout << '(' << node->Key << "; " << node->Priority << ')' << endl;
		ShowTreap(node->Left, level + 1);
	}
}
