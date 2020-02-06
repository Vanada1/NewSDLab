#include "Treap.h"

void Treap::CreateTree(int quantity)
{
	srand(time(nullptr));
	for (int i = 0; i < quantity; i++)
	{
		AddOptimized(rand() % 100, rand() % 100);
	}
}

int Treap::SearchElement(int key)
{
	TreapNode* current = Root;
	while (current != nullptr)
	{
		if (current->Key == key)
		{
			return current->Priority;
		}
		if (current->Key > key)
		{
			current = current->Left;
		}
		else
		{
			current = current->Right;
		}
	}
	return -1;
}

void Treap::DeleteTree(TreapNode*& node)
{
	if (node->Left)
	{
		DeleteTree(node->Left);
	}
	if (node->Right)
	{
		DeleteTree(node->Right);
	}
	delete node;
}

void Treap::Split(TreapNode* node, int key, TreapNode*& left, TreapNode*&
	right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (node->Key <= key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}
	else if (node->Key >= key)
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}
}

TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}
	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	right->Left = Merge(left, right->Left);
	return right;
}

TreapNode* Treap::AddUnoptimized(int key, int priority)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(Root, key, left, right);
	TreapNode* inserted = new TreapNode();
	inserted->Key = key;
	inserted->Priority = priority;
	return Merge(Merge(left, inserted), right);
	
}

bool Treap::AddOptimized(int key, int priroity)
{
	TreapNode* current = Root;
	while (current != nullptr && current->Priority > priroity)
	{
		if (current->Key > key)
		{
			if (current->Left == nullptr) break;

			current = current->Left;
		}
		else
		{
			if (current->Right == nullptr) break;

			current = current->Right;
		}
	}
	TreapNode* inserted = new TreapNode();
	inserted->Key = key;
	inserted->Priority = priroity;
	if (Root == nullptr || Root->Priority < inserted->Priority)
	{
		Split(current, key, inserted->Left, inserted->Right);
		Root = inserted;
	}
	else if (current->Key > inserted->Key)
	{
		Split(current->Left, key, inserted->Left, inserted->Right);
		current->Left = inserted;
	}
	else
	{
		Split(current->Right, key, inserted->Left, inserted->Right);
		current->Right = inserted;
	}
	return true;
}

TreapNode* Treap::RemoveUnoptimized(int key)
{
	//TODO: RSDN
	TreapNode* left, *deleteElem, *right;
	Split(Root, key - 1, left, right);
	Split(right, key, deleteElem, right);
	delete deleteElem;
	return Merge(left, right);
}

bool Treap::RemoveOptimized(int key)
{
	if (Root == nullptr)
	{
		return false;
	}
	TreapNode* current = Root;
	while (current != nullptr && current->Key != key)
	{
		if (current->Key > key)
		{
			if (current->Left == nullptr || 
				current->Left->Key == key) break;

			current = current->Left;
		}
		else
		{
			if (current->Right == nullptr ||
				current->Right->Key == key) break;

			current = current->Right;
		}
	}
	TreapNode* deleteElem;
	if (current == Root && current->Key == key)
	{
		deleteElem = current;
		Root = Merge(deleteElem->Left, deleteElem->Right);
	}
	else if (current->Key > key)
	{
		if (current->Left == nullptr)
		{
			return false;
		}
		deleteElem = current->Left;
		current->Left = Merge(deleteElem->Left, deleteElem->Right);
	}
	else
	{
		if (current->Right == nullptr)
		{
			return false;
		}
		deleteElem = current->Right;
		current->Right = Merge(deleteElem->Left, deleteElem->Right);
	}
	delete deleteElem;
}