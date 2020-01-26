#pragma once

#include<string>
#include"Hash.h"
#include"Dictionary.h"

void Error();
std::string WriteString();
int  WriteInt();
void TextOutput(std::string);
void PrintHashTable(Hash*);
void PrintDictionary(Dictionary*);
void ShowResult(std::string);
void None();
void RehashingDone();
void Done();