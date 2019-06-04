#pragma once

#include<iostream>
#define MinInt 0
typedef char VerTexType;
typedef int ArcType;
using namespace std;

class GraphLJZ
{
private:
	int vexnum, arcnum; //图总顶点数目、总边数目
	VerTexType* vexs;  //顶点表
	ArcType** arcs; //邻接矩阵
	bool* visit; //访问标志
	void RedeafultVisit();//恢复访问标志表的默认设置
public:
	GraphLJZ(int num1, int num2);
	void Init();
	void Create();
	int Print();
	int LocateVex(char node);
	void BFS(int v);//广度优先搜索遍历图
	void DFS(int v);//深度优先搜索遍历图
};

