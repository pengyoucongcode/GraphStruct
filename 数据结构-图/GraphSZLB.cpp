#include "GraphSZLB.h"
#include <iostream>
using namespace std;
//���캯��
GraphSZLB::GraphSZLB(int num1, int num2)
{
	vexnum = num1;
	arcnum = num2;
	xlist = new vexNode[vexnum];
}
//��ʼ�������
void GraphSZLB::Init()
{
	cout << "�����붥����Ϣ��";
	for (int i = 0; i < vexnum; i++)
	{
		cin >> xlist[i].data;
		xlist[i].linein = NULL;
		xlist[i].lineout = NULL;
	}
}
//��ȡ�������
int GraphSZLB::LocateVex(char node)
{
	int i;
	for (i = 0; i < vexnum; i++)
		if (xlist[i].data == node)
			break;
	if (i == vexnum)
	{
		cout << "������Ϣ����" << endl;
		exit(0);
	}
	return i;
}
//����ʮ������ṹ������ͼ
void GraphSZLB::Create()
{
	for (int k = 0; k < arcnum; k++)
	{
		char v1, v2;
		cout << "�����������յ㣺";
		cin >> v1 >> v2;
		int i, j;
		i = LocateVex(v1);
		j = LocateVex(v2);
		ArcBox* next = new ArcBox;
		next->headVext = i;
		next->tailVext = j;
		cout << "����ñߵ�Ȩ�أ�";
		cin >> next->length;
		next->hlink = NULL;
		next->tlink = NULL;
		//��λ�õĶ���ĳ��Ȼ�Ϊ��ʱ��ֱ���� lineout ָ��ָ���µı���
		//��¼������Ϣ
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
		//��¼�����Ϣ
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
//����ͼ
void GraphSZLB::Traver()
{
	int i;
	cout << "��������ĳ�����Ϣ��" << endl;
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
	cout << "��������������Ϣ��" << endl;
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