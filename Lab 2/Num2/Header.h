#pragma once
#include <iostream>

struct Node
{
	int Data;
	Node* Next;
	Node* Prev;
};

struct List
{
	int Size;
	Node* Haed;
	Node* Tail;
};

void push(List, int);