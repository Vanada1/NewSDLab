#include <iostream>
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

void  PrintTree(RBTreeNode* node, int level, RBTreeNode* nil)
{
	if (node && node != nil)
	{
		PrintTree(node->Right, level + 1, nil);
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
		PrintTree(node->Left, level + 1, nil);
	}
}

void ALVTreeShow(ALVTreeNode* node, int level)
{
	if (node)
	{
		ALVTreeShow(node->Right, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << node->Data << endl;
		ALVTreeShow(node->Left, level + 1);
	}
}