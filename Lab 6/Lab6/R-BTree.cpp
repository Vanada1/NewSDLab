#include "R-BTree.h"

void RBTree::RotateLeft(RBTreeNode* RotateElem)
{
	RBTreeNode* temp = RotateElem->Right;
	//establish RotateElem->Right link
	RotateElem->Right = temp->Left;
	if (temp->Left != Nil)
	{
		temp->Left->Parent = RotateElem;
	}
	//establish temp->Parent link
	if (temp != Nil)
	{
		temp->Parent = RotateElem->Parent;
	}
	if (RotateElem->Parent)
	{
		if (RotateElem == RotateElem->Parent->Left)
		{
			RotateElem->Parent->Left = temp;
		}
		else
		{
			RotateElem->Parent->Right = temp;
		}
	}
	else
	{
		Root = temp;
	}
	temp->Left = RotateElem;
	if (RotateElem != Nil)
	{
		RotateElem->Parent = temp;
	}
}

void RBTree::RotateRight(RBTreeNode* RotateElem)
{

	RBTreeNode* temp = RotateElem->Left;
	//establish RotateElem->Left link
	RotateElem->Left = temp->Right;
	if (temp->Right != Nil)
	{
		temp->Right->Parent = RotateElem;
	}
	//establish temp->Parent link
	if (temp != Nil)
	{
		temp->Parent = RotateElem->Parent;
	}
	if (RotateElem->Parent) 
	{
		if (RotateElem == RotateElem->Parent->Right)
			RotateElem->Parent->Right = temp;
		else
			RotateElem->Parent->Left = temp;
	}
	else {
		Root = temp;
	}
	temp->Right = RotateElem;
	if (RotateElem != Nil)
	{
		RotateElem->Parent = temp;
	}
}

void RBTree::InsertFixup(RBTreeNode* node)
{
	// check red-black properties
	while (node != Root && node->Parent->Color == RED)
	{
		if (node->Parent == node->Parent->Parent->Left)
		{
			RBTreeNode* temp = node->Parent->Parent->Right;
			// if uncle is RED
			if (temp->Color == RED)
			{
				node->Parent->Color = BLACK;
				temp->Color = BLACK;
				node->Parent->Parent->Color = RED;
				node = node->Parent->Parent;
			}
			// if uncle is BLACK
			else
			{
				if (node == node->Parent->Right)
				{
					node = node->Parent;
					RotateLeft(node);
				}
				// recolor and rotate
				node->Parent->Color = BLACK;
				node->Parent->Parent->Color = RED;
				RotateRight(node->Parent->Parent);
			}
		}
		else
		{
			// mirror image of above code 
			RBTreeNode* temp = node->Parent->Parent->Left;
			// if uncle is RED
			if (temp->Color == RED)
			{
				node->Parent->Color = BLACK;
				temp->Color = BLACK;
				node->Parent->Parent->Color = RED;
				node = node->Parent->Parent;
			}
			// if uncle is BLACK
			else
			{
				if (node == node->Parent->Left)
				{
					node = node->Parent;
					RotateRight(node);
				}
				// recolor and rotate
				node->Parent->Color = BLACK;
				node->Parent->Parent->Color = RED;
				RotateLeft(node->Parent->Parent);
			}
		}
	}
	Root->Color = BLACK;
}

bool RBTree::Insert(int data)
{
	RBTreeNode* current, * parent, * insertedElem;

	current = Root;
	parent = nullptr;
	while (current != Nil && current)
	{
		if (data == current->Data) return false;
		parent = current;
		current = (data < current->Data) ?
			current->Left : current->Right;
	}
	insertedElem = new RBTreeNode(data, RED, parent);
	insertedElem->Left = insertedElem->Right = Nil;
	// insert node in the tree
	if (parent)
	{
		if (data < parent->Data)
		{
			parent->Left = insertedElem;
		}
		else
		{
			parent->Right = insertedElem;
		}
	}
	else
	{
		Root = insertedElem;
	}
	InsertFixup(insertedElem);
	return true;
}

void RBTree::DeleteFixup(RBTreeNode* node)
{
	while (node != Root && node->Color == BLACK)
	{
		if (node == node->Parent->Left)
		{
			RBTreeNode* temp = node->Parent->Right;
			if (temp->Color == RED)
			{
				temp->Color = BLACK;
				temp->Parent->Color = RED;
				RotateLeft(node->Parent);
				temp = node->Parent->Right;
			}
			if (temp->Left->Color == BLACK && temp->Right->Color == BLACK)
			{
				temp->Color = RED;
				node = node->Parent;
			}
			else
			{
				if (temp->Right->Color == BLACK)
				{
					temp->Left->Color = BLACK;
					temp->Color = RED;
					RotateRight(temp);
					temp = node->Parent->Right;
				}

				temp->Color = node->Parent->Color;
				node->Parent->Color = BLACK;
				temp->Right->Color = BLACK;
				RotateLeft(node->Parent);
				node = Root;
			}
		}
		// mirror 
		else
		{
			RBTreeNode* temp = node->Parent->Left;
			if (temp->Color == RED)
			{
				temp->Color = BLACK;
				temp->Parent->Color = RED;
				RotateRight(node->Parent);
				temp = node->Parent->Left;
			}
			if (temp->Left->Color == BLACK && temp->Right->Color == BLACK)
			{
				temp->Color = RED;
				node = node->Parent;
			}
			else
			{
				if (temp->Left->Color == BLACK)
				{
					temp->Right->Color = BLACK;
					temp->Color = RED;
					RotateLeft(temp);
					temp = node->Parent->Left;
				}

				temp->Color = node->Parent->Color;
				node->Parent->Color = BLACK;
				temp->Left->Color = BLACK;
				RotateRight(node->Parent);
				node = Root;
			}
		}
	}
	node->Color = BLACK;
}

bool RBTree::DeleteElem(RBTreeNode* elem)
{
	RBTreeNode* temp, *deleteElem;

	if (!elem || elem == Nil) return false;

	// deleteElem is Nil node as a child
	if (elem->Left == Nil || elem->Right == Nil)
	{
		deleteElem = elem;
	}
	//find tree successor with a Nil node as a child
	else
	{
		deleteElem = elem->Right;
		while (deleteElem->Left != Nil)
		{
			deleteElem = deleteElem->Left;
		}
	}
	// current is deleteElem's only child
	if (deleteElem->Left != Nil)
	{
		temp = deleteElem->Left;
	}
	else
	{
		temp = deleteElem->Right;
	}

	// remove deleteElem from the parent chain
	temp->Parent = deleteElem->Parent;
	if (deleteElem->Parent)
	{
		if (deleteElem == deleteElem->Parent->Left)
		{
			deleteElem->Parent->Left = temp;
		}
		else
		{
			deleteElem->Parent->Right = temp;
		}
	}
	else
	{
		Root = temp;
	}
	if (deleteElem != elem)
	{
		elem->Data = deleteElem->Data;
	}
	if (deleteElem->Color == BLACK)
	{
		DeleteFixup(temp);
	}
	delete deleteElem;
}

bool RBTree::SearchElem(RBTreeNode*& elem, int data)
{
	RBTreeNode* current = Root;
	if (!Root)
	{
		return false;
	}
	while (current!= Nil)
	{
		if (data == current->Data)
		{
			elem = current;
			return true;
		}
		current = (data < current->Data) ? 
			current->Left : current->Right;
	}
	elem = nullptr;
	return false;
}

void RBTree::ClearTree(RBTreeNode* node)
{
	if (node->Left != Nil)
	{
		ClearTree(node->Left);
	}
	if (node->Right != Nil)
	{
		ClearTree(node->Right);
	}
	delete node;
}