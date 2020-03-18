#pragma once

#include"Stack.h"


struct QueueTwoStack
{
	Stack* Main;
	Stack* Peripheral;
	void ClearQueue();
	void CreateQueue();
	void Enqueue(int);
	bool Dequeue(int&);
	void Delete();
	//For array flipping
	void InvertedStack(Stack*&, Stack*&);

};