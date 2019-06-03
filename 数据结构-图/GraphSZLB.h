#pragma once
typedef char VerTexType;
typedef int ArcType;

//弧节点
struct ArcBox
{
	int tailVext, headVext; //该弧的尾和头顶点的位置
	ArcBox* hlink, * tlink; //分别为弧头相同和弧尾相同的链域
	int length;
};
//顶点节点
struct vexNode
{
	VerTexType data;
	ArcBox* linein, * lineout; //指向出弧、入弧
};
//十字链表
class GraphSZLB
{
private:
	int vexnum, arcnum; //顶点数、边数
	vexNode* xlist;
public:
	GraphSZLB(int num1, int num2);
	void Init();
	int LocateVex(char node);
	void Create();
	void Traver();
};
