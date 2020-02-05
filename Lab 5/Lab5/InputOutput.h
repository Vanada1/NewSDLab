#pragma once

#include<string>
#include"BinaryTreeNode.h"
#include"TreapNode.h"
#include"List.h"

using namespace std;

int  ReadInt();
void ShowBinaryTree(BinaryTreeNode*, int);
void ShowTreap(TreapNode*, int);
void ShowList(List*);
void OutputError();
void OutputNone();
void OutputDone();