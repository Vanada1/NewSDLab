#pragma once

#include<string>
#include"R-BTree.h"
#include "ALVTree.h"
#include "../../CommonFuction/ReadInt.h"


using namespace std;

//TODO: naming(Done)
void OutputError();
void OutputNone();
void OutputDone();

void  PrintTree(RBTreeNode*, int, RBTreeNode*);
void ALVTreeShow(ALVTreeNode*, int);
void SetColor(int text, int background);