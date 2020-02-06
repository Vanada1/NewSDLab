#pragma once

#include<string>
#include"BinaryTreeNode.h"
#include"TreapNode.h"
#include"List.h"
#include "../../CommonFuction/ReadInt.h"

using namespace std;

void ShowBinaryTree(BinaryTreeNode*, int);
void ShowTreap(TreapNode*, int);
void ShowList(List*);
void OutputError();
void OutputNone();
void OutputDone();