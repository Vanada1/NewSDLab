#include "ListFunc.h"
#include "InputOutput.h"
#include <iostream>
using namespace std;

//TODO:rsdn
long double AddElement(List* lst, int quantity)
{
	long double elapsed_secs = 0;
	clock_t begin = clock();
	for (int i = 0; i < quantity; i++)
	{
		InsertInList(lst, rand() % 100, lst->Size - 1, elapsed_secs);
	}
	clock_t end = clock();
	//TODO:rsdn
	elapsed_secs = FuncCounting(begin, end);
	return elapsed_secs;
}
//TODO:rsdn
bool DeleteElement(List* lst, int index, long double& elapsed_secs)
{
	clock_t begin = clock();
	if (index < 0)
	{
		return false;
	}
	else if (index >= lst->Size)
	{
		return false;
	}
	Node* temp = lst->Head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->Next;
	}
	if (temp->Next!=nullptr && temp->Perv!=nullptr)
	{
		temp->Perv->Next = temp->Next;
		temp->Next->Perv = temp->Perv;
	}
	else if ((temp->Next != nullptr) && (temp->Perv == nullptr))
	{
		temp->Next->Perv = temp->Perv;
		lst->Head = temp->Next;
	}

	else if ((temp->Next == nullptr) && (temp->Perv != nullptr))
	{
		temp->Perv->Next = temp->Next;
		lst->Tail = temp->Perv;
	}
	else if ((temp->Next == nullptr) && (temp->Perv == nullptr))
	{
		lst->Head = nullptr;
		lst->Tail = nullptr;
	}
	delete temp;
	lst->Size--;

	clock_t end = clock();
	elapsed_secs = FuncCounting(begin, end);
	return true;
}

bool InsertInList(List* lst, int number,int index, long double& elapsed_secs)
{
	clock_t begin = clock();
	if (index < 0)
	{
		return false;
	}
	else if (index > lst->Size)
	{
		return false;
	}
	
	Node* inserted = new Node;
	inserted->Data = number;
	if (lst->Head == nullptr)
	{
		lst->Head = inserted;
		lst->Size = 0;
		lst->Head->Next = nullptr;
		lst->Head->Perv = nullptr;
		lst->Tail = lst->Head;
	}
	else if (index == 0)
	{
		Node* temp = lst->Head->Perv;
		temp = new Node;
		temp->Data = number;
		temp->Next = lst->Head;
		lst->Head->Perv = temp;
		lst->Head = temp;
		lst->Head->Perv = nullptr;
	}
	else if (index == lst->Size)
	{
		lst->Tail->Next = inserted;
		inserted->Perv = lst->Tail;
		lst->Tail = inserted;
		lst->Tail->Next = nullptr;
	}
	else 
	{
		Node* current = lst->Head;
		for (int i = 0; i < index; i++)
		{
			current = current->Next;
		}
		current->Perv->Next = inserted;
		inserted->Perv = current->Perv;
		current->Perv = inserted;
		inserted->Next = current;
	}
	lst->Size++;
	clock_t end = clock();
	elapsed_secs = FuncCounting(begin, end);
	return true;
}

void Sort(List* lst)
{
	Node* minNode;
	Node* supNode;
	for (int j = 0; j < lst->Size; j++)
	{
		minNode = lst->Head;
		supNode = lst->Head->Next;
		for (int i = 1; i < lst->Size - j; i++)
		{
			if (minNode->Data > supNode->Data)
			{
				minNode = supNode;
			}
			supNode = supNode->Next;
		}
		lst->Tail->Next = minNode;
		if (minNode == lst->Head)
		{
			lst->Head->Next->Perv = nullptr;
			lst->Head = lst->Head->Next;
			lst->Tail->Next = minNode;
			minNode->Next = nullptr;
			minNode->Perv = lst->Tail;
			lst->Tail = minNode;
		}
		else if ((minNode != lst->Head) && (minNode != lst->Tail))
		{
			minNode->Perv->Next = minNode->Next;
			minNode->Next->Perv = minNode->Perv;
			minNode->Perv = lst->Tail;
			minNode->Next = nullptr;
			lst->Tail->Next = minNode;
			lst->Tail = minNode;
		}
	}
}

bool LineSearch(List* lst, int number, int& index)
{
	Node* temp = lst->Head;
	int counter = 0;
	for (int i = 0; temp != nullptr; i++)
	{
		if (temp->Data == number)
		{
			index = i;
			return true;
		}
		temp = temp->Next;
	}
	return false;
}

void DeleteList (List* lst)
{
	Node* deleteElem = lst->Head;
	while (deleteElem)
	{
		Node* temp = deleteElem->Next;
		delete deleteElem;
		deleteElem = temp;
	}
}

long double FuncCounting(clock_t begin, clock_t end)
{
	return long double((end - begin) / CLOCKS_PER_SEC);
}