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
//初始化顶点表和邻接矩阵
void GraphLJZ::Init()
{
	int i, k;
	cout << "请按顺序输入顶点信息：";
	for (i = 0; i < vexnum; i++)
		cin >> vexs[i];       //依次输入点的信息
	for (i = 0; i < vexnum; i++)
		for (k = 0; k < vexnum; k++)
			arcs[i][k] = MinInt;       //初始化邻接矩阵，边的权值均设置为最小值0
}
//确定顶点序号
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
		cout << "顶点信息错误！" << endl;
		exit(0);
	}
	return i;
}
//创建有向图
void GraphLJZ::Create()
{
	int i, k;
	for (int j = 0; j < arcnum; j++)
	{
		char v1, v2;
		cout << "请输入起点和终点：";
		cin >> v1 >> v2;
		i = LocateVex(v1);
		k = LocateVex(v2);
		int temp;
		cout << "请输入该边的权重：";
		cin >> temp;
		arcs[i][k] = temp;

	}
}

//以深度优先搜索遍历图
int GraphLJZ::Traver()
{
	int i, j;
	cout << "图的邻接矩阵为：" << endl;
	for (i = 0; i < vexnum; i++)
	{
		for (j = 0; j < vexnum; j++)
		{
			cout << arcs[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "各个邻接边的信息：" << endl;
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