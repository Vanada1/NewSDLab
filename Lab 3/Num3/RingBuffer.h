#pragma once

#define BUFFER 5

struct RingBuffer
{
	//TODO: соединить с ringbuf(Done)
	int* Array;
	int Tail = -1;
	int Front = -1;
	//TODO: Naming (Done)
	int Capacity;
	int Size = 0;
	bool IsNotDelete;
	void AddElement(int);
	void CreateBuffer(int);
	void Resize();
	int GetElement();
	void DeleteRingBuf();
	int CalculationFunction(int, int);
};
