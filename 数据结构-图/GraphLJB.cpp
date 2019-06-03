#include "GraphLJB.h"
#include <iostream>
using namespace std;

//构造函数
GraphLJB::GraphLJB(int node, int line)
{
	vexNum = node;
	arcNum = line;
	vertices = new VexNode[vexNum];
}
//初始化顶点表
void GraphLJB::initializeTheVertexTable()
{
	cout << "请输入顶点信息：";
	for (int i = 0; i < vexNum; i++)
	{
		cin >> vertices[i].data;
		vertices[i].theArc = NULL;
	}
}
//获取顶点的序号
int GraphLJB::LocateVex(char node)
{
	int i;
	for(i=0;i<vexNum;i++)
		if (vertices[i].data == node)
		{
			break;
		}
	if (i == vexNum)
	{
		cout << "顶点信息错误！" << endl;
		exit(0);
	}
	return i;
}
//创建邻接表
void GraphLJB::Create()
{
	for (int k = 0; k < arcNum; k++)
	{
		char v1, v2;
		int i, j;
		cout << "请输入起点和终点：";
		cin >> v1 >> v2;
		i = LocateVex(v1);
		j = LocateVex(v2);
		ArcNode* next = new ArcNode;
		next->adjvex = j;
		cout << "请输入该边权重：";
		cin >> next->length;
		next->nextArc = NULL;
		//将边串联
		if (vertices[i].theArc == NULL)
		{
			vertices[i].theArc = next;
		}
		else
		{
			ArcNode* p;
			p = vertices[i].theArc;
			while (p->nextArc) //找到链表的最后一个结点
			{
				p = p->nextArc;
			}
			p->nextArc = next;
		}
	}
}
//以深度优先搜索遍历图
void GraphLJB::DFS_AL()
{
	int i;
	cout << "图的邻接表为：" << endl;
	for (i = 0; i < vexNum; i++)
	{
		ArcNode* now;
		now = vertices[i].theArc;
		while (now)
		{
			cout << vertices[i].data << "->" << vertices[now->adjvex].data << ":" << now->length << endl;
			now = now->nextArc;
		}
	}
}