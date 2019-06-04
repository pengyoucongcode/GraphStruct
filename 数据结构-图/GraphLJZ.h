#pragma once

#include<iostream>
#define MinInt 0
typedef char VerTexType;
typedef int ArcType;
using namespace std;

class GraphLJZ
{
private:
	int vexnum, arcnum; //ͼ�ܶ�����Ŀ���ܱ���Ŀ
	VerTexType* vexs;  //�����
	ArcType** arcs; //�ڽӾ���
	bool* visit; //���ʱ�־
	void RedeafultVisit();//�ָ����ʱ�־���Ĭ������
public:
	GraphLJZ(int num1, int num2);
	void Init();
	void Create();
	int Print();
	int LocateVex(char node);
	void BFS(int v);//���������������ͼ
	void DFS(int v);//���������������ͼ
};

