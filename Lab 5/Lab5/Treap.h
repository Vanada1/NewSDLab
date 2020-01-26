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
	// unoptimized algorithm
	TreapNode* AddElementUA(int, int);
	// optimized algorithm
	bool AddElementOA(int, int);
	// unoptimized algorithm
	TreapNode* RemoveElementUA(int);
	// optimized algorithm
	bool RemoveElementOA(int);

};