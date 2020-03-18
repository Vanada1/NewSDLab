#include "ListFunc.h"
#include "InputOutput.h"
#include <iostream>
using namespace std;

//TODO:rsdn(Done)
long double AddElement(List* list, int quantity)
{
	//TODO: дублируются расчеты времени, правильнее вынести их в рирективы препроцессора
	long double elapsedSecs = 0;
#if SWITCH == 1
	clock_t begin = clock();
#endif
	for (int i = 0; i < quantity; i++)
	{
		InsertInList(list, rand() % 100, list->Size - 1, elapsedSecs);
	}
#if SWITCH == 1
	clock_t end = clock();
	//TODO:rsdn(DOne)
	elapsedSecs = FuncCounting(begin, end);
#endif
	return elapsedSecs;
}
//TODO:rsdn
bool DeleteElement(List* lst, int index, long double& elapsed_secs)
{
#if SWITCH == 1
	clock_t begin = clock();
#endif
	if (index < 0 || index >= lst->Size)
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
#if SWITCH == 1
	clock_t end = clock();
	elapsed_secs = FuncCounting(begin, end);
#endif
	return true;
}

bool InsertInList(List* lst, int number,int index, long double& elapsed_secs)
{
#if SWITCH == 1
	clock_t begin = clock();
#endif
	if (index < 0 || index > lst->Size)
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
#if SWITCH == 1
	clock_t end = clock();
	elapsed_secs = FuncCounting(begin, end);
#endif
	return true;
}

void InsertionSort(List* lst)
{
	for (int j = 0; j < lst->Size; j++)
	{
		//TODO: внести(Done)
		Node* minNode;
		Node* supNode;
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