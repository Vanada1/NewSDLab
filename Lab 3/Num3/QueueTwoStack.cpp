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

bool QueueTwoStack::Dequeue(int& number)
{
	InvertedStack(Main, Peripheral);
	number = Peripheral->Pop();
	InvertedStack(Peripheral, Main);
	return (number != -1);
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