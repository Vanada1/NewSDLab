#pragma once

#include<string>
#include "RingBuffer.h"
#include"Stack.h"

void ShowRingBuf(int* array, int front, int tail, int capacity);
void ShowFreeSpace(int, int);
void OccupiedSpace(int);
void Error();
int ReadInt();
void OutputNumberRing(int number);
void ShowStackQueue(Stack*);
bool IsNothing(int, int);