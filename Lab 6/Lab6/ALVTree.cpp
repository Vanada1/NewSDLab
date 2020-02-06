#include "ALVTree.h"

ALVTreeNode* ALVTree::AddElement(ALVTreeNode* node, int number)
{
	if (!node)
	{
		return new ALVTreeNode(number);
	}
	if (number < node->Data)
	{
		node->Left = AddElement(node->Left, number);
	}
	else if (number > node->Data)
	{
		node->Right = AddElement(node->Right, number);
	}
	else
	{
		return node;
	}
	return Balace(node);
}

ALVTreeNode* ALVTree::RemoveElement(ALVTreeNode* node, int number)
{
	if (!node)
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
	else
	{
		ALVTreeNode* left = node->Left;
		ALVTreeNode* right = node->Right;
		delete node;
		if (!right)
		{
			return left;
		}
		ALVTreeNode* min = SearchMin(right);
		min->Right = RemoveMin(right);
		min->Left = left;
		return Balace(min);
	}
	return Balace(node);
}

bool ALVTree::SearchElement(int number)
{
	ALVTreeNode* current = Root;
	while (current != nullptr)
	{
		if (current->Data == number)
		{
			return true;
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
	return false;
}

void ALVTree::DeleteTree(ALVTreeNode*& node)
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

ALVTreeNode* ALVTree::SearchMin(ALVTreeNode* node)
{
	if (node->Left == nullptr)
	{
		return node;
	}
	return SearchMin(node->Left);
}

ALVTreeNode* ALVTree::RemoveMin(ALVTreeNode* node)
{
	if (!node->Left)
	{
		return node->Right;
	}
	node->Left = RemoveMin(node->Left);
	return Balace(node);
}

ALVTreeNode* ALVTree::RotateRight(ALVTreeNode* node)
{
	ALVTreeNode* support = node->Left;
	node->Left = support->Right;
	support->Right = node;
	Fixheight(node);
	Fixheight(support);
	return support;
}

ALVTreeNode* ALVTree::RotateLeft(ALVTreeNode* node)
{
	ALVTreeNode* support = node->Right;
	node->Right = support->Left;
	support->Left = node;
	Fixheight(node);
	Fixheight(support);
	return support;
}

ALVTreeNode* ALVTree::Balace(ALVTreeNode* node)
{
	Fixheight(node);
	if (CountBalaceFactor(node) == 2)
	{
		if (CountBalaceFactor(node->Right) < 0)
		{
			node->Right = RotateRight(node->Right);
		}
		return RotateLeft(node);
	}

	if (CountBalaceFactor(node) == -2)
	{
		if (CountBalaceFactor(node->Left) > 0)
		{
			node->Left = RotateLeft(node->Left);
		}
		return RotateRight(node);
	}
	return node;
}

// support function 
unsigned int ALVTree::CountHeight(ALVTreeNode* node)
{
	return node ? node->Height : 0;
}

int ALVTree::CountBalaceFactor(ALVTreeNode* node)
{
	return CountHeight(node->Right) - CountHeight(node->Left);
}

void ALVTree::Fixheight(ALVTreeNode* node)
{
	unsigned int heightL = CountHeight(node->Left);
	unsigned int heightR = CountHeight(node->Right);
	node->Height = (heightL > heightR ? heightL : heightR) + 1;
}
