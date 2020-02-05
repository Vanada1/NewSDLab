#include "RingBuffer.h"
#include"InputOutput.h"

bool IsNothing(int front, int tail)
{
	return (front == -1 && tail == -1);
}

void RingBuffer::Resize()
{
	if (IsNotDelete && Size != 0)
	{
		int* temp = new int[Size];
		for (int i = 0; i < Size; i++)
		{
			temp[i] = Array[(Front + i) % Capacity];
		}
		delete[] Array;
		Capacity += BUFFER;
		Array = new int[Capacity];
		for (int i = 0; i < Size; i++)
		{
			Array[i] = temp[i];
			Tail = i;
		}
		Front = 0;
		delete[] temp;
	}
	else
	{
		Error();
	}
}

//TODO: input param(Done)
void RingBuffer::CreateBuffer(int buffer)
{
	Capacity = buffer;
	Array = new int[Capacity];
	//TODO: �������(Done)
	IsNotDelete = true;
}

void RingBuffer::AddElement(int number)
{
	if (!IsNotDelete)
	{
		CreateBuffer(BUFFER);
	}
	//TODO: �����(Done)
	if (CalculationFunction(Tail,Capacity) == Front)
	{
		OutputNumberRing(GetElement());
	}
	if (Front == -1)
	{
		Front = 0;
	}
	//TODO: �����(Done)
	Tail = CalculationFunction(Tail, Capacity);
	Array[Tail] = number;
	Size++;
}

int RingBuffer::GetElement()
{
	if (IsNothing(Front, Tail))
	{
		Error();
		return -1;
	}
	int temp = Array[Front];
	if (Front == Tail)
	{
		Front = -1;
		Tail = -1;
	}
	else
	{
		//TODO: �����
		Front = (Front + 1) % Capacity;
	}
	Size--;
	return temp;
}

void RingBuffer::DeleteRingBuf()
{
	if (IsNotDelete)
	{
		delete[] Array;
		Front = -1;
		Tail = -1;
		IsNotDelete = false;
	}
}

int RingBuffer::CalculationFunction(int tail, int capacity)
{
	return (tail + 1) % capacity;
}