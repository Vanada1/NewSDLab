#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h> 
#include"InputOutput.h"
#include "R-BTreeNode.h"
#include "NodeColor.h"
#include "ConsoleColor.h"

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

//void SetColor(int text, NodeColor background)
//{
//	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
//}

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

void  PrintTree(RBTreeNode* node, int level, RBTreeNode* Nil)
{
	if (node && node != Nil)
	{
		PrintTree(node->Right, level + 1, Nil);
		for (int i = 0; i < level; i++) cout << "   ";
		if (node->Color == RED)
		{
			SetColor(Red, 0);
		}
		else
		{
			SetColor(Cyan, 0);
		}
		cout << node->Data << endl;
		PrintTree(node->Left, level + 1, Nil);
	}
}

void ALVTreeShow(ALVTreeNode* node, int level)
{
	if (node)
	{
		ALVTreeShow(node->Right, level + 1);
		for (int i = 0; i < level; i++) cout << "\t";
		for (int i = 0; i < level; i++) cout << "   ";
		cout << node->Data << endl;
		ALVTreeShow(node->Left, level + 1);
	}
}