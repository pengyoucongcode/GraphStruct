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
public:
	GraphLJZ(int num1, int num2);
	void Init();
	void Create();
	int Traver();
	int LocateVex(char node);
};

