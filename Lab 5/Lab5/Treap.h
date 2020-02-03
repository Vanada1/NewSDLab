#pragma once
#include <iostream>
#include <ctime>
#include"InputOutput.h"
#include "TreapNode.h"

struct Treap
{
	TreapNode* Root;
	void CreateTree(int);
	int SearchElement(int);
	void DeleteTree(TreapNode*&);
	void Split(TreapNode*, int, TreapNode*&, TreapNode*&);
	TreapNode* Merge(TreapNode*, TreapNode*);
	//TODO: Naming
	// unoptimized algorithm
	TreapNode* AddElementUA(int, int);
	//TODO: Naming
	// optimized algorithm
	bool AddElementOA(int, int);
	//TODO: Naming
	// unoptimized algorithm
	TreapNode* RemoveElementUA(int);
	//TODO: Naming
	// optimized algorithm
	bool RemoveElementOA(int);

};