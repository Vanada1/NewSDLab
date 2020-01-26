#pragma once

#include<string>
#include"R-BTree.h"
#include "ALVTree.h"


using namespace std;

int  WriteInt();
void TextOutput(string);
void Error();
void None();
void Done();

void  PrintTree(RBTreeNode*, int, RBTreeNode*);
void ALVTreeShow(ALVTreeNode*, int);
void SetColor(int text, int background);