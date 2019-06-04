#pragma once
//队列类
class Queue
{
private:
	int* base;
	int length; //队列长度
	int front;
	int rear;
public:
	Queue(int num);
	void Enqueue(int num);
	void Dequeue(int &num);
	bool Empty();
	void GetTop(int &e);
};