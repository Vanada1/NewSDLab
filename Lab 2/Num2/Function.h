#pragma once
#include <iostream>

struct Node
{
	int Data;
	Node* Next;
	Node* Perv;
};

struct List
{
	int Size;
	Node* Head;
	Node* Tail;
};

void AddElement(List*, int);
void DeleteElement(List*, int);
void DeleteList(List*);
void InsertInList(List*, int, int);
void Sort(List*);
void LineSearch(List*, int);
//Input and Output
int Write();
void TextOutput();
void OutputList (List*);
void Error();
void FoundElement(int, int);
void ResultOfSearch(int, int);
void OutputTime(long double, std::string);
void OutputListBack(List*);