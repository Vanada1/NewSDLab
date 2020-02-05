#pragma once
#include "DynamicArray.h"

//TODO:rsdn(Done)
int const CAPACITY = 4;
void CreatArray(DynamicArray&);
void Resize(DynamicArray*);
bool RemoveElement(DynamicArray&, int);
bool AddElement(DynamicArray&, int, int);
//TODO: Naming(Done)
void QuickSortArray(DynamicArray&);
bool LineSearch(DynamicArray&, int, int&);
bool BinarySearch(DynamicArray&, int, int&);
bool CheckSort(DynamicArray&);