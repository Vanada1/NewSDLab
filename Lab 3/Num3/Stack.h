#pragma once

#include"Node.h"

struct Stack
{
	Node* Top;
	void Push(int);
	int Pop();
	void ClearStack();
};