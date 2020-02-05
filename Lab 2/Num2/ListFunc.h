#pragma once
#include "List.h"
#include <ctime>

long double AddElement(List*, int);
bool DeleteElement(List*, int, long double&);
void DeleteList(List*);
bool InsertInList(List*, int, int, long double&);
//TODO: Naming(Done)
void InsertionSort(List*);
bool LineSearch(List*, int, int&);
long double FuncCounting(clock_t, clock_t);