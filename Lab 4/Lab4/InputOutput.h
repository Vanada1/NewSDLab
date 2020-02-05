#pragma once

#include"HashTable.h"
#include"Dictionary.h"

void OutputError();
int  ReadInt();
void PrintHashTable(HashTable*);
void PrintDictionary(Dictionary*);
void ShowResult(std::string);
void OutputNone();
void RehashingDone();
void OutputDone();