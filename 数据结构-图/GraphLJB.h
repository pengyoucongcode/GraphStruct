#pragma once
typedef char VerTexType;
typedef int ArcType;

//边节点
struct ArcNode  
{
	int adjvex;
	ArcNode* nextArc;
	int length;
};

//顶点节点
struct VexNode
{
	VerTexType data;
	ArcNode* theArc;
};

//邻接表类
class GraphLJB
{
private:
	VexNode *vertices; //顶点表
	int vexNum, arcNum; //顶点数、边数
public:
	GraphLJB(int node, int line);
	void initializeTheVertexTable();
	int LocateVex(char node);
	void Create();
	void DFS_AL();
};