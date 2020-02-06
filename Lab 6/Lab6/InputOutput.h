#pragma once

#include<string>
#include"R-BTree.h"
#include "ALVTree.h"


using namespace std;

int  ReadInt();
//TODO: naming
void Error();
void OutputNone();
void OutputDone();

void  PrintTree(RBTreeNode*, int, RBTreeNode*);
void ALVTreeShow(ALVTreeNode*, int);
void SetColor(int text, int background);