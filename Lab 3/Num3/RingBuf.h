#pragma once

struct RingBuf
{
	int* Array;
	int Tail;
	int Front;
	//TODO: Naming (Done)
	int Capacity;
	int Size;
};