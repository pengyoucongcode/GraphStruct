// 数据结构-图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "GraphLJZ.h"
#include "GraphLJB.h"
#include "GraphSZLB.h"
using namespace std;

int main()
{
	int num1, num2; //图的顶点数，边数
	cout << "请输入图的顶点数和边数：";
	cin >> num1 >> num2;
	cout << "以十字链表构图：" << endl;
	GraphSZLB g1(num1, num2);
	g1.Init();
	g1.Create();
	g1.Traver();
	cout << "============================" << endl;
	cout << endl;
	cout << "以邻接表构图：" << endl;
	GraphLJB g2(num1, num2);
	g2.initializeTheVertexTable();
	g2.Create();
	g2.DFS_AL();
	cout << "======================================" << endl;
	cout << endl;
	cout << "以邻接矩阵构图：" << endl;
	GraphLJZ g3(num1,num2);
	g3.Init();
	g3.Create();
	g3.Traver();
	cout << "===========================================" << endl;
	cout << endl;
	return 0;
}

