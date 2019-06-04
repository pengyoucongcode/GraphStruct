#include "GraphLJB.h"
#include "Queue.h"
#include <iostream>
using namespace std;

//���캯��
GraphLJB::GraphLJB(int node, int line)
{
	vexNum = node;
	arcNum = line;
	vertices = new VexNode[vexNum];
	visit = new bool[vexNum];
}
//��ʼ�������
void GraphLJB::initializeTheVertexTable()
{
	cout << "�����붥����Ϣ��";
	for (int i = 0; i < vexNum; i++)
	{
		cin >> vertices[i].data;
		vertices[i].theArc = NULL;
		visit[i] = false;
	}
}
//��ȡ��������
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
		cout << "������Ϣ����" << endl;
		exit(0);
	}
	return i;
}
//�����ڽӱ�
void GraphLJB::Create()
{
	for (int k = 0; k < arcNum; k++)
	{
		char v1, v2;
		int i, j;
		cout << "�����������յ㣺";
		cin >> v1 >> v2;
		i = LocateVex(v1);
		j = LocateVex(v2);
		ArcNode* next = new ArcNode;
		next->adjvex = j;
		cout << "������ñ�Ȩ�أ�";
		cin >> next->length;
		next->nextArc = NULL;
		//���ߴ���
		if (vertices[i].theArc == NULL)
		{
			vertices[i].theArc = next;
		}
		else
		{
			ArcNode* p;
			p = vertices[i].theArc;
			while (p->nextArc) //�ҵ���������һ�����
			{
				p = p->nextArc;
			}
			p->nextArc = next;
		}
	}
}
//���ͼ�ı�
void GraphLJB::Print()
{
	int i;
	cout << "ͼ���ڽӱ�Ϊ��" << endl;
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
//���������������ͼ
void GraphLJB::BFS(int v)
{
	int temp;
	Queue q(vexNum);
	cout << vertices[v].data << " ";
	visit[v] = true;
	q.Enqueue(v);
	while (!q.Empty())
	{
		int w;
		q.GetTop(w);
		q.Dequeue(temp);
		for (ArcNode* u = vertices[w].theArc; u != NULL; u = u->nextArc)
		{
			if (visit[u->adjvex] == false)
			{
				cout << vertices[u->adjvex].data << " ";
				q.Enqueue(u->adjvex);
				visit[u->adjvex] = true;
			}
		}
	}
	cout << endl;
	RedeafultVisit();
}
void GraphLJB::RedeafultVisit()
{
	for (int i = 0; i < vexNum; i++)
		visit[i] = false;
}
//���������������ͼ
void GraphLJB::DFS(int v)
{
	cout << vertices[v].data << " ";
	visit[v] = true;
	ArcNode* p = vertices[v].theArc;
	while (p != NULL)
	{
		int w = p->adjvex;
		if (visit[w] == false)
			DFS(w);
		p = p->nextArc;
	}
}