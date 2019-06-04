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
	bool* visit; //访问标志表
	void RedeafultVisit();//恢复访问标志表的默认设置
	
public:
	GraphLJB(int node, int line);
	void initializeTheVertexTable();
	int LocateVex(char node);
	void Create();
	void Print();
	void BFS(int v); //广度优先搜索遍历图
	void DFS(int v);//深度优先搜索遍历图
};