#include "BinaryMenu.h"
#include "WorkWithFiles.h"

void BinaryTreeMenu()
{
	bool isEnd = false;
	//TODO: Почему здесь?(Done)
	//TODO: RSDN(Done)
	BinaryTree* tree = new BinaryTree();
	cout << "Enter the count of elemetns\t";
	tree->CreateTree(ReadInt());
	cout << endl;

	while (!isEnd)
	{
		system("pause");
		system("cls");
		ShowBinaryTree(tree->Root, 0);
		cout << endl;
		TextOutput("BinaryMenu.txt");
		switch (ReadInt())
		{
			//TODO: RSDN(Done)
			case 1:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				if (tree->AddElement(number))
				{
					OutputDone();
				}
				else
				{
					OutputError();
				}
				break;
			}
			case 2:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				tree->Root = tree->RemoveElement(tree->Root, number);
				break;
			}
			case 3:
			{
				cout << "Enter the number\n";
				int number = ReadInt();
				cout << endl;
				List* foundElements = tree->SearchElement(number);
				ShowList(foundElements);
				if (foundElements != nullptr)
				{
					foundElements->Clear();
				}
				delete foundElements;
				break;
			}
			case 4:
			{
				if (tree->Root == nullptr)
				{
					cout << "No element\n";
				}
				else
				{
					cout << tree->SearchMax(tree->Root)->Data << endl;
				}
				break;
			}
			case 5:
			{
				if (tree->Root == nullptr)
				{
					cout << "No element\n";
				}
				else
				{
					cout << tree->SearchMin(tree->Root)->Data << endl;
				}
				break;
			}
			case 9:
			{
				isEnd = true;
				break;
			}
			default:
			{
				cout << "Strange comand\n";
				break;
			}
		}
	}
	if (tree->Root != nullptr)
	{
		tree->DeleteTree(tree->Root);
	}
	delete tree;
}