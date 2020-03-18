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
	Buffer->CreateBuffer(BUFFER);
}

void QueueRing::Enqueue(int number)
{
	//TODO: дубль(Done)
	if (Buffer->CalculationFunction(Buffer->Tail,
		Buffer->Capacity) == Buffer->Front)
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