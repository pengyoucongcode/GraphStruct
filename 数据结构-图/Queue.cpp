#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int num)
{
	length = num;
	base = new int[length];
	front = rear = 0;
}
void Queue::Enqueue(int num)
{
	if ((rear + 1) % length == front)
	{
		cout << "队满，无法入队" << endl;
		exit(0);
	}
	else
	{
		base[rear] = num;
		rear = (rear + 1) % length;
	}
}
bool Queue::Empty()
{
	if (front == rear)
		return true;
	return false;
}
void Queue::Dequeue(int &num)
{
	if (Empty())
	{
		cout << "队空，无法出队！" << endl;
		exit(0);
	}
	else
	{
		num = base[front];
		front = (front + 1) % length;
	}
}
void Queue::GetTop(int &e)
{
	if (Empty())
	{
		cout << "队列为空，无法获取队头元素！" << endl;
		exit(0);
	}
	e=base[front];
}