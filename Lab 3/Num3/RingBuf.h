#pragma once

struct RingBuf
{
	int* Array;
	int Tail;
	int Front;
	int Compasity;
	int Size;
};