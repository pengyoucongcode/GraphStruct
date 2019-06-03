#include "GraphLJB.h"
#include <iostream>
using namespace std;

//���캯��
GraphLJB::GraphLJB(int node, int line)
{
	vexNum = node;
	arcNum = line;
	vertices = new VexNode[vexNum];
}
//��ʼ�������
void GraphLJB::initializeTheVertexTable()
{
	cout << "�����붥����Ϣ��";
	for (int i = 0; i < vexNum; i++)
	{
		cin >> vertices[i].data;
		vertices[i].theArc = NULL;
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
//�����������������ͼ
void GraphLJB::DFS_AL()
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