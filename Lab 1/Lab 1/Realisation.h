#pragma once
#include "DynamicArray.h"

void CreatArray(DynamicArray*);
void Resize(DynamicArray*);
bool RemoveElement(DynamicArray*, int);
bool AddElement(DynamicArray*, int, int);
void SortArray(DynamicArray*);
bool LineSearch(DynamicArray*, int, int&);
bool BinarySearch(DynamicArray*, int, int&);
bool CheckSort(DynamicArray*);