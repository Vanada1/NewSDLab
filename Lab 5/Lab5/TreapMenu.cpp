#include "TreapMenu.h"
#include "Treap.h"

void TreapMenu()
{
	srand(time(NULL));
	Treap* Tree = new Treap();
	bool ending = true;
	int control = 0;
	int number = 0;
	int priority = 0;
	cout << "Enter the count of elemetns\t";
	number = WriteInt();
	Tree->CreateTree(number);
	cout << endl;

	while (ending)
	{
		system("pause");
		system("cls");
		ShowTreap(Tree->Root, 0);
		cout << endl;
		TextOutput("TreapMemu.txt");
		control = WriteInt();
		switch (control)
		{
		case 1:
			cout << "Enter the number\n";
			number = WriteInt();
			cout << endl;
			priority = Tree->SearchElement(number);
			if (priority >= 0)
			{
				cout << priority << endl;
			}
			else
			{
				cout << "Not found\n";
			}
			cout << endl;
			break;
		case 2:
			cout << "Enter the number\n";
			number = WriteInt();
			Tree->Root = Tree->AddElementUA(number, rand() % 100);
			break;
		case 3:
			cout << "Enter the number\n";
			number = WriteInt();
			Tree->AddElementOA(number, rand() % 100);
			break;
		case 4:
			cout << "Enter the number\n";
			number = WriteInt();
			Tree->Root = Tree->RemoveElementUA(number);
			break;
		case 5:
			cout << "Enter the number\n";
			number = WriteInt();
			Tree->RemoveElementOA(number);
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