#pragma once
#include <iostream>
#include <ctime>
#include "ALVTreeNode.h"
//#include"List.h"

struct ALVTree
{
public:
	ALVTreeNode* Root = nullptr;
	ALVTreeNode* AddElement(ALVTreeNode*, int);
	ALVTreeNode* RemoveElement(ALVTreeNode*, int);
	bool SearchElement(int);
	void DeleteTree(ALVTreeNode*&);
private:
	ALVTreeNode* RotateLeft(ALVTreeNode*);
	ALVTreeNode* RotateRight(ALVTreeNode*);
	ALVTreeNode* Balace(ALVTreeNode* node);
	ALVTreeNode* SearchMin(ALVTreeNode*);
	ALVTreeNode* RemoveMin(ALVTreeNode*);

	//TODO: naming(Done)
	unsigned int CountHeight(ALVTreeNode*);
	//TODO: naming(Done)
	int CountBalaceFactor(ALVTreeNode*);
	void Fixheight(ALVTreeNode*);
};
