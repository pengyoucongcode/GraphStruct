#include "GraphLJZ.h"

GraphLJZ::GraphLJZ(int num1, int num2)
{
	vexnum = num1;
	arcnum = num2;
	vexs = new char[vexnum];
	int temp = vexnum;
	arcs = new int* [temp];
	for (int i = 0; i < temp; i++)
		arcs[i] = new int[temp];
}
//��ʼ���������ڽӾ���
void GraphLJZ::Init()
{
	int i, k;
	cout << "�밴˳�����붥����Ϣ��";
	for (i = 0; i < vexnum; i++)
		cin >> vexs[i];       //������������Ϣ
	for (i = 0; i < vexnum; i++)
		for (k = 0; k < vexnum; k++)
			arcs[i][k] = MinInt;       //��ʼ���ڽӾ��󣬱ߵ�Ȩֵ������Ϊ��Сֵ0
}
//ȷ���������
int GraphLJZ::LocateVex(char node)
{
	int i;
	for (i = 0; i < vexnum; i++)
	{
		if (node == vexs[i])
			break;
	}
	if (i == vexnum)
	{
		cout << "������Ϣ����" << endl;
		exit(0);
	}
	return i;
}
//��������ͼ
void GraphLJZ::Create()
{
	int i, k;
	for (int j = 0; j < arcnum; j++)
	{
		char v1, v2;
		cout << "�����������յ㣺";
		cin >> v1 >> v2;
		i = LocateVex(v1);
		k = LocateVex(v2);
		int temp;
		cout << "������ñߵ�Ȩ�أ�";
		cin >> temp;
		arcs[i][k] = temp;

	}
}

//�����������������ͼ
int GraphLJZ::Traver()
{
	int i, j;
	cout << "ͼ���ڽӾ���Ϊ��" << endl;
	for (i = 0; i < vexnum; i++)
	{
		for (j = 0; j < vexnum; j++)
		{
			cout << arcs[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "�����ڽӱߵ���Ϣ��" << endl;
	int count = 0;
	for (i = 0; i < vexnum; i++)
		for (j = 0; j < vexnum; j++)
		{
			if (arcs[i][j] != 0)
			{
				cout << vexs[i] << "->" << vexs[j] << ":" << arcs[i][j] << endl;
				count++;
				if (count == arcnum)
					return count;
			}
		}
}