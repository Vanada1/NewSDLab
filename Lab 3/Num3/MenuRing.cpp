#include <iostream>
#include"InputOutput.h"
#include "MenuRing.h"
#include"RingBuffer.h"
#include"WorkWithFiles.h"

using namespace std;

void MenuRing()
{
	RingBuffer* struc = new RingBuffer;
	struc->CreateBuffer(BUFFER);
	bool isEnd = false;
	//TODO: Почему здесь?(Done)
	
	while (!isEnd)
	{
		system("pause");
		system("cls");
		ShowRingBuf(struc->Array, struc->Front,
			struc->Tail, struc->Capacity);
		ShowFreeSpace(struc->Capacity, struc->Size);
		OccupiedSpace(struc->Size);
		TextOutput("QueueRingBuff_menu.txt");
		switch (ReadInt())
		{
			//TODO: {}(Done)
			case 1:
			{
				cout << "Enter the element\n";
				int number = ReadInt();
				struc->AddElement(number);
				cout << "Added\n";
				break;
			}
			case 2:
			{
				int number = struc->GetElement();
				OutputNumberRing(number);
				break;
			}
			case 3:
			{
				struc->DeleteRingBuf();
				cout << "Ring deleted\n";
				break;
			}
			case 4:
			{
				struc->Resize();
				break;
			}
			case 9:
			{
				isEnd = true;
				break;
			}
			default:
			{
				cout << "Wrong\n";
				break;
			}
		}
	}
	struc->DeleteRingBuf();
}