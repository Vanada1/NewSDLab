#pragma once

#include "RingBuf.h"

struct RingBuffer
{
	//TODO: ��������� � ringbuf
	RingBuf Ring;
	bool IsNotDelete;
	void AddElement(int);
	void CreateBuffer();
	void Resize();
	int GetElement();
	void DeleteRingBuf();

};
