#pragma once

struct RingBuf
{
	int* Array;
	int Tail;
	int Front;
	int Capacity;
	int Size;
};