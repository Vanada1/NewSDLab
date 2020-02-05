#include <iostream>
#include"InputOutput.h"
#include"MenuQueueRing.h"
#include"QueueRing.h"

using namespace std;

int QueueRing::Dequeue()
{
	return Buffer->GetElement();
}

void QueueRing::CreateQueue()
{
	Buffer->CreateBuffer();
}

void QueueRing::Enqueue(int number)
{
	//TODO: дубль
	if ((Buffer->Ring.Tail + 1) % Buffer->Ring.Capacity == Buffer->Ring.Front)
	{
		Resize();
	}
	Buffer->AddElement(number);
}

void QueueRing::Resize()
{
	Buffer->Resize();
}

void QueueRing::Delete()
{
	Buffer->DeleteRingBuf();
}