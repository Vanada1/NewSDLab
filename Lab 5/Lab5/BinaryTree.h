#pragma once
#include <iostream>
#include <ctime>
#include "BinaryTreeNode.h"
#include"List.h"

struct BinaryTree
{
	BinaryTreeNode* Root = nullptr;
	void CreateTree(int);
	bool AddElement(int);
	BinaryTreeNode* RemoveElement(BinaryTreeNode*, int);
	BinaryTreeNode* SearchMin(BinaryTreeNode*);
	BinaryTreeNode* SearchMax(BinaryTreeNode*);
	List* SearchElement(int);
	void DeleteTree(BinaryTreeNode*&);
};
