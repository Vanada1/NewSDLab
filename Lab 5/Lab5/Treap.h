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
	TreapNode* AddUnoptimized(int, int);
	bool AddOptimized(int, int);
	TreapNode* RemoveUnoptimized(int);
	bool RemoveOptimized(int);

};