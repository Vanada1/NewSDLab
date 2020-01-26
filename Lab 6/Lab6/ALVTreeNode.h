#pragma once

struct ALVTreeNode
{
	int Data;
	ALVTreeNode* Left;
	ALVTreeNode* Right;
	unsigned int Height;
	ALVTreeNode(int data)
	{
		Data = data;
		Left = Right = nullptr;
		Height = 1;
	}
};