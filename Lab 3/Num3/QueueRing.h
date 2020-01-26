#pragma once
#include "RingBuffer.h"
struct QueueRing
{
	RingBuffer* Buffer = new RingBuffer();
	void CreateQueue();
	void Enqueue(int);
	int Dequeue();
	void Delete();
	void Resize();
};