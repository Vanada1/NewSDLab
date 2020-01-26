#include "List.h"

void List::Add(int number)
{
	Node* temp = new Node();
	temp->Data = number;
	if (Top == nullptr)
	{
		Top = temp;
	}
	else
	{
		temp->Next = Top;
		Top = temp;
	}
}

void List::Clear()
{
	while (Top != nullptr)
	{
		Node* element = Top->Next;
		delete Top;
		Top = element;
	}
	delete Top;
}