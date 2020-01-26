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
	if ((Buffer->Ring.Tail + 1) % Buffer->Ring.Compasity == Buffer->Ring.Front)
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