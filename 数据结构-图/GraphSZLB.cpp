#include "GraphSZLB.h"
#include <iostream>
using namespace std;
//构造函数
GraphSZLB::GraphSZLB(int num1, int num2)
{
	vexnum = num1;
	arcnum = num2;
	xlist = new vexNode[vexnum];
}
//初始化顶点表
void GraphSZLB::Init()
{
	cout << "请输入顶点信息：";
	for (int i = 0; i < vexnum; i++)
	{
		cin >> xlist[i].data;
		xlist[i].linein = NULL;
		xlist[i].lineout = NULL;
	}
}
//获取顶点序号
int GraphSZLB::LocateVex(char node)
{
	int i;
	for (i = 0; i < vexnum; i++)
		if (xlist[i].data == node)
			break;
	if (i == vexnum)
	{
		cout << "顶点信息错误！" << endl;
		exit(0);
	}
	return i;
}
//创建十字链表结构的有向图
void GraphSZLB::Create()
{
	for (int k = 0; k < arcnum; k++)
	{
		char v1, v2;
		cout << "请输入起点和终点：";
		cin >> v1 >> v2;
		int i, j;
		i = LocateVex(v1);
		j = LocateVex(v2);
		ArcBox* next = new ArcBox;
		next->headVext = i;
		next->tailVext = j;
		cout << "输入该边的权重：";
		cin >> next->length;
		next->hlink = NULL;
		next->tlink = NULL;
		//该位置的顶点的出度还为空时，直接让 lineout 指针指向新的表结点
		//记录出度信息
		if (xlist[i].lineout == NULL)
		{
			xlist[i].lineout = next;
		}
		else
		{
			ArcBox* now;
			now = xlist[i].lineout;
			while (now->tlink)
			{
				now = now->tlink;
			}
			now->tlink = next;
		}
		//记录入度信息
		if (xlist[j].linein == NULL)
		{
			xlist[j].linein = next;
		}
		else
		{
			ArcBox* now;
			now = xlist[j].linein;
			while (now->hlink)
			{
				now = now->hlink;
			}
			now->hlink = next;
		}
	}
}
//遍历图
void GraphSZLB::Traver()
{
	int i;
	cout << "各个顶点的出度信息：" << endl;
	for (i = 0; i < vexnum; i++)
	{
		ArcBox* now;
		now = xlist[i].lineout;
		while (now)
		{
			cout << xlist[i].data << "->" << xlist[now->tailVext].data << ":" << now->length << " ";
			now = now->tlink;
		}
		cout << "^" << endl;
	}
	cout << "各个顶点的入度信息：" << endl;
	for (i = 0; i < vexnum; i++)
	{
		ArcBox* now;
		now = xlist[i].linein;
		while (now)
		{
			cout << xlist[i].data << "<-" << xlist[now->headVext].data << ":" << now->length << " ";
			now = now->hlink;
		}
		cout << "^" << endl;
	}
}