#pragma once

#include<string>
#include "RingBuffer.h"
#include"Stack.h"
#include "../../CommonFuction/ReadInt.h"

void ShowRingBuf(int* array, int front, int tail, int capacity);
void ShowFreeSpace(int, int);
void OccupiedSpace(int);
void OutputError();
void OutputNumberRing(int number);
void ShowStackQueue(Stack*);
bool IsNothing(int, int);