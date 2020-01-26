#include "BinaryTree.h"

void BinaryTree::CreateTree(int quantity)
{
	srand(time(NULL));
	for (int i = 0; i < quantity; i++)
	{
		AddElement(rand() % 100);
	}
}

bool BinaryTree::AddElement(int number)
{
	BinaryTreeNode* node = new BinaryTreeNode();
	node->Data = number;
	if (Root == nullptr)
	{
		Root = node;
		return true;
	}
	BinaryTreeNode* current = Root;
	while (current != nullptr)
	{
		if (current->Data == node->Data)
		{
			delete node;
			return false;
		}
		if (current->Data > node->Data)
		{ 
			if (current->Left == nullptr)
			{
				current->Left = node;
				return true;
			}
			else
			{
				current = current->Left;
			}
		}
		else
		{
			if (current->Right == nullptr)
			{
				current->Right = node;
				return true;
			}
			else 
			{ 
				current = current->Right; 
			}
		}
	}
	delete node;
	return false;
}

BinaryTreeNode* BinaryTree::RemoveElement(BinaryTreeNode* node, int number)
{
	if (node == nullptr)
	{
		return node;
	}
	if (number < node->Data)
	{
		node->Left = RemoveElement(node->Left, number);
	}
	else if (number > node->Data)
	{
		node->Right = RemoveElement(node->Right, number);
	}
	else if (node->Left != nullptr && node->Right != nullptr)
	{
		node->Data = SearchMin(node->Right)->Data;
		node->Right = RemoveElement(node->Right, node->Data);		
	}
	else
	{
		if (node->Left != nullptr)
		{
			BinaryTreeNode* deleteElement = node;
			node = node->Left;
			delete deleteElement;
		}
		else if (node->Right != nullptr)
		{
			BinaryTreeNode* deleteElement = node;
			node = node->Right;
			delete deleteElement;
		}
		else
		{
			node = nullptr;
		}
	}
	return node;
}

BinaryTreeNode* BinaryTree::SearchMax(BinaryTreeNode* node)
{
	if (node->Right == nullptr)
	{
		return node;
	}
	return SearchMax(node->Right);
}

BinaryTreeNode* BinaryTree::SearchMin(BinaryTreeNode* node)
{
	if (node->Left == nullptr)
	{
		return node;
	}
	return SearchMin(node->Left);
}

void BinaryTree::DeleteTree(BinaryTreeNode*& node)
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

List* BinaryTree::SearchElement(int number)
{
	BinaryTreeNode* current = Root;
	List* temp = new List();
	while (current != nullptr)
	{
		temp->Add(current->Data);
		if (current->Data == number)
		{
			return temp;
		}
		else if (current->Data > number)
		{
			current = current->Left;
		}
		else
		{
			current = current->Right;
		}
	}
	temp->Clear();
	delete temp;
	return nullptr;
}