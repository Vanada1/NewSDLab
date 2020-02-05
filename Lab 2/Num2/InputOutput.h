#pragma once
#include <iostream>
#include "List.h"

//TODO: Ответственности(Done)
//Input and Output
int ReadInt();
void OutputList(List*);
void OutputError();
void OutputDone();
void OutputTime(long double, std::string);
void OutputListBack(List*);