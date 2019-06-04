#include "GraphLJZ.h"
#include "Queue.h"

GraphLJZ::GraphLJZ(int num1, int num2)
{
	vexnum = num1;
	arcnum = num2;
	vexs = new char[vexnum];
	visit = new bool[vexnum];
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
	{
		cin >> vexs[i];       //������������Ϣ
		visit[i] = false;
	}
	vexs[i] = '\0';
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

//���ͼ
int GraphLJZ::Print()
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
//���������������ͼ
void GraphLJZ::BFS(int num)
{
	int temp=0;
	Queue q(vexnum);
	visit[num] = true;
	cout << vexs[num] << " ";
	q.Enqueue(num);
	while (!q.Empty())
	{
		int w;
		q.GetTop(w);
		q.Dequeue(temp);
		for(int u=0;u<vexnum;u++)
			if (arcs[w][u] != 0 && visit[u] == false)
			{
				cout << vexs[u] << " ";
				q.Enqueue(u);
				visit[u] = true;
			}
	}
	cout << endl;
	RedeafultVisit();
}
//�ָ����ʱ�־���Ĭ������
void GraphLJZ::RedeafultVisit()
{
	for (int i = 0; i < vexnum; i++)
		visit[i] = false;
}
//���������������ͼ
void GraphLJZ::DFS(int v)
{
	cout << vexs[v]<<" ";
	visit[v] = true;
	for (int w = 0; w < vexnum; w++)
		if (arcs[v][w] != 0 && visit[w] == false)
			DFS(w);
}