#pragma once

#include "R-BTreeNode.h"

struct RBTree
{
	RBTreeNode* Root;
	RBTreeNode* Nil;
	bool Insert(int);
	//TODO: Почему не инкапсулированы повороты
	bool DeleteElem(RBTreeNode*);
	bool SearchElem(RBTreeNode*&, int);
	void RotateLeft(RBTreeNode*);
	void RotateRight(RBTreeNode*);
	void InsertFixup(RBTreeNode*);
	void DeleteFixup(RBTreeNode*);
	void ClearTree(RBTreeNode*);

	RBTree()
	{
		Root = nullptr;
		Nil = new RBTreeNode();
	}
};