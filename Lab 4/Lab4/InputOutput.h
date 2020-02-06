#pragma once

#include"HashTable.h"
#include"Dictionary.h"
#include "../../CommonFuction/ReadInt.h"

void OutputError();
void PrintHashTable(HashTable*);
void PrintDictionary(Dictionary*);
void ShowResult(std::string);
void OutputNone();
void RehashingDone();
void OutputDone();