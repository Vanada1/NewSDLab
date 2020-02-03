#pragma once

struct RingBuf
{
	int* Array;
	int Tail;
	int Front;
	//TODO: Naming
	int Compasity;
	int Size;
};