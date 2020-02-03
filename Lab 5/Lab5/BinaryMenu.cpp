#include "BinaryMenu.h"

void BinaryTreeMenu()
{
	bool ending = true;
	//TODO: Почему здесь?
	int control = 0;
	int number = 0;
	//TODO: RSDN
	BinaryTree* Tree = new BinaryTree();
	List* Temp;
	cout << "Enter the count of elemetns\t";
	number = WriteInt();
	Tree->CreateTree(number);
	cout << endl;

	while (ending)
	{
		system("pause");
		system("cls");
		ShowBinaryTree(Tree->Root, 0);
		cout << endl;
		TextOutput("BinaryMenu.txt");
		control = WriteInt();
		switch (control)
		{
			//TODO: RSDN
		case 1:
			cout << "Enter the number\n";
			number = WriteInt();
			if (Tree->AddElement(number))
			{
				Done();
			}
			else
			{
				Error();
			}
			break;
		case 2:
			cout << "Enter the number\n";
			number = WriteInt();
			Tree->Root = Tree->RemoveElement(Tree->Root, number);
			break;
		case 3:
			cout << "Enter the number\n";
			number = WriteInt();
			cout << endl;
			Temp = Tree->SearchElement(number);
			ShowList(Temp);
			if (Temp != nullptr)
			{
				Temp->Clear();
			}
			delete Temp;
			break;
		case 4:
			if (Tree->Root == nullptr)
			{
				cout << "No element\n";
			}
			else 
			{
				cout << Tree->SearchMax(Tree->Root)->Data << endl;
			}
			break;
		case 5:
			if (Tree->Root == nullptr)
			{
				cout << "No element\n";
			}
			else
			{
				cout << Tree->SearchMin(Tree->Root)->Data << endl;
			}
			break;
		case 9:
			ending = false;
			break;
		default:
			cout << "Strange comand\n";
			break;
		}
	}
	if (Tree->Root != nullptr)
	{
		Tree->DeleteTree(Tree->Root);
	}
	delete Tree;
}