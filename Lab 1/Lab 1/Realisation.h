#pragma once
#include "DynamicArray.h"

void CreatArray(DynamicArray&);
void Resize(DynamicArray&);
void DeletElement(DynamicArray&, int);
void AddElement(DynamicArray&, int, int);
//TODO: Naming
void Sort(DynamicArray&);
bool LineSearch(DynamicArray&, int, int&);
bool BinarySearch(DynamicArray&, int, int&);
bool CheckSort(DynamicArray&);
//Input and Output
void TextOutput();
int Write();
void OutputArray(DynamicArray&);