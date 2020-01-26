#include "Stack.h"
#include "InputOutput.h"

void Stack::Push(int number)
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

int Stack::Pop()
{
	if (Top == nullptr)
	{
		return -1;
	}
	int tempNumber = Top->Data;
	Node* deleteElement = Top;
	Top = Top->Next;
	delete deleteElement;
	return tempNumber;
}

void Stack::ClearStack()
{
	while (Top != nullptr)
	{
		Node* element = Top->Next;
		delete Top;
		Top = element;
	}
	delete Top;
}