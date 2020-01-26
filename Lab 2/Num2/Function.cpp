#include "Function.h"
#include <ctime>

using namespace std;

void AddElement(List* lst, int quantity)
{
	clock_t begin = clock();
	for (int i = 0; i < quantity; i++)
	{
		InsertInList(lst, rand() % 100, lst->Size - 1);
	}
	clock_t end = clock();
	long double elapsed_secs = long double(end - begin) / CLOCKS_PER_SEC;
	OutputTime(elapsed_secs, "add elements ");
}

void DeleteElement(List* lst, int index)
{
	//clock_t begin = clock();
	if (index < 0)
	{
		Error();
		return;
	}
	else if (index >= lst->Size)
	{
		Error();
		return;
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

	//clock_t end = clock();
	//long double elapsed_secs = long double(end - begin) / CLOCKS_PER_SEC;
	//OutputTime(elapsed_secs, "delete element ");
}

void InsertInList(List* lst, int number,int index)
{
	//clock_t begin = clock();
	if (index < 0)
	{
		Error();
		return;
	}
	else if (index > lst->Size)
	{
		Error();
		return;
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
	//clock_t end = clock();
	//long double elapsed_secs = long double(end - begin) / CLOCKS_PER_SEC;
	//OutputTime(elapsed_secs, "add elements ");
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

void LineSearch(List* lst, int number)
{
	Node* temp = lst->Head;
	int counter = 0;
	for (int i = 0; temp != nullptr; i++)
	{
		if (temp->Data == number)
		{
			FoundElement(i, number);
			counter++;
		}
		temp = temp->Next;
	}
	ResultOfSearch(counter, number);
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