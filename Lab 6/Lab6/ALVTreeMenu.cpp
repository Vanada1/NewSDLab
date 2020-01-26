#include "ALVTreeMenu.h"

void ALVTreeMenu()
{
	bool ending = true;
	int control = 0;
	int number = 0;
	ALVTree* Tree = new ALVTree();
	cout << "Enter the count of elemetns\t";
	number = WriteInt();
	srand(time(NULL));
	for (int i = 0; i < number; i++)
	{
		Tree->Root = Tree->AddElement(Tree->Root, rand() % 100);
	}
	cout << endl;

	while (ending)
	{
		system("pause");
		system("cls");
		ALVTreeShow(Tree->Root, 0);
		cout << endl;
		TextOutput("ALVTreeMenu.txt");
		control = WriteInt();
		switch (control)
		{
		case 1:
			cout << "Enter the number\n";
			number = WriteInt();
			Tree->Root = Tree->AddElement(Tree->Root, number);
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
			if (Tree->SearchElement(number))
			{
				Done();
			}
			else
			{
				None();
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