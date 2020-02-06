#pragma once

#include "R-BTreeNode.h"

struct RBTree
{
	RBTreeNode* Root;
	RBTreeNode* Nil;
	bool Insert(int);
	bool DeleteElem(RBTreeNode*);
	bool SearchElem(RBTreeNode*&, int);
	void ClearTree(RBTreeNode*);

	RBTree()
	{
		Root = nullptr;
		Nil = new RBTreeNode();
	}
private:
	void RotateLeft(RBTreeNode*);
	void RotateRight(RBTreeNode*);
	void InsertFixup(RBTreeNode*);
	void DeleteFixup(RBTreeNode*);
};