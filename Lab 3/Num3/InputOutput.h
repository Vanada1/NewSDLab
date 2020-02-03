#pragma once

#include<string>
#include"RingBuf.h"
#include"Stack.h"

void ShowRingBuf(RingBuf&);
void FreeSpace(int, int);
void OccupiedSpace(int);
void Error();
int Write();
void TextOutput(std::string);
void OutputNumberRing(int number);
void ShowStackQueue(Stack*);
bool IsNothing(int, int);