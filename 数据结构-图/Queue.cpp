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
		cout << "�������޷����" << endl;
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
		cout << "�ӿգ��޷����ӣ�" << endl;
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
		cout << "����Ϊ�գ��޷���ȡ��ͷԪ�أ�" << endl;
		exit(0);
	}
	e=base[front];
}