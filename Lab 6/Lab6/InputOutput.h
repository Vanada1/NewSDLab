#pragma once

#include<string>
#include"R-BTree.h"
#include "ALVTree.h"
#include "../../CommonFuction/ReadInt.h"
#include "../../CommonFuction/OutputAction.h"


using namespace std;

//TODO: naming(Done)
void  PrintTree(RBTreeNode*, int, RBTreeNode*);
void ALVTreeShow(ALVTreeNode*, int);
void SetColor(int text, int background);