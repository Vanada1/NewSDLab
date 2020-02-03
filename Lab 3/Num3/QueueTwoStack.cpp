#include "QueueTwoStack.h"
#include "InputOutput.h"

void QueueTwoStack::ClearQueue()
{
	Main->ClearStack();
	Peripheral->ClearStack();
}

void QueueTwoStack::Enqueue(int number)
{
	Main->Push(number);
}

void QueueTwoStack::CreateQueue()
{
	Main = new Stack();
	Peripheral = new Stack();
}

int QueueTwoStack::Dequeue()
{
	InvertedStack(Main, Peripheral);
	int temp = Peripheral->Pop();
	InvertedStack(Peripheral, Main);
	return temp;
}

void QueueTwoStack::InvertedStack(Stack*& main, Stack*& second)
{
	while (main->Top != nullptr)
	{
		second->Push(main->Pop());
	}
}

void QueueTwoStack::Delete()
{
	Main->ClearStack();
	Peripheral->ClearStack();
}