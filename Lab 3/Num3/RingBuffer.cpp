#include "RingBuffer.h"
#include"InputOutput.h"

#define BUFFER 5

bool IsNothing(int front, int tail)
{
	if (front == -1 && tail == -1) return true;
	else return false;
}

void RingBuffer::Resize()
{
	if (IsNotDelete && Ring.Size != 0)
	{
		int* temp = new int[Ring.Size];
		for (int i = 0; i < Ring.Size; i++)
		{
			temp[i] = Ring.Array[(Ring.Front + i) % Ring.Capacity];
		}
		delete[] Ring.Array;
		Ring.Capacity += BUFFER;
		Ring.Array = new int[Ring.Capacity];
		for (int i = 0; i < Ring.Size; i++)
		{
			Ring.Array[i] = temp[i];
			Ring.Tail = i;
		}
		Ring.Front = 0;
		delete[] temp;
	}
	else
	{
		Error();
	}
}

void RingBuffer::CreateBuffer()
{
	Ring.Capacity = BUFFER;
	Ring.Array = new int[Ring.Capacity];
	Ring.Front = -1;
	Ring.Tail = -1;
	Ring.Size = 0;
	IsNotDelete = true;
}

void RingBuffer::AddElement(int number)
{
	if (!IsNotDelete)
	{
		CreateBuffer();
	}
	if ((Ring.Tail + 1) % Ring.Capacity == Ring.Front)
	{
		OutputNumberRing(GetElement());
	}
	if (Ring.Front == -1)
	{
		Ring.Front = 0;
	}
	Ring.Tail = (Ring.Tail + 1) % Ring.Capacity;
	Ring.Array[Ring.Tail] = number;
	Ring.Size++;
}

int RingBuffer::GetElement()
{
	if (IsNothing(Ring.Front, Ring.Tail))
	{
		Error();
		return -1;
	}
	int temp = Ring.Array[Ring.Front];
	if (Ring.Front == Ring.Tail)
	{
		Ring.Front = -1;
		Ring.Tail = -1;
	}
	else
	{
		Ring.Front = (Ring.Front + 1) % Ring.Capacity;
	}
	Ring.Size--;
	return temp;
}

void RingBuffer::DeleteRingBuf()
{
	if (IsNotDelete)
	{
		delete[] Ring.Array;
		Ring.Front = -1;
		Ring.Tail = -1;
		IsNotDelete = false;
	}
}