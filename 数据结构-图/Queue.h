#pragma once
//������
class Queue
{
private:
	int* base;
	int length; //���г���
	int front;
	int rear;
public:
	Queue(int num);
	void Enqueue(int num);
	void Dequeue(int &num);
	bool Empty();
	void GetTop(int &e);
};