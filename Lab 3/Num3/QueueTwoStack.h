#pragma once

#include"Stack.h"


struct QueueTwoStack
{
	Stack* Main;
	Stack* Peripheral;
	void CreateQueue();
	void Enqueue(int);
	int Dequeue();
	void Delete();
	//For array flipping
	void InvertedStack(Stack*&, Stack*&);

};