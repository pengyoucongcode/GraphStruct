#pragma once
typedef char VerTexType;
typedef int ArcType;

//�߽ڵ�
struct ArcNode  
{
	int adjvex;
	ArcNode* nextArc;
	int length;
};

//����ڵ�
struct VexNode
{
	VerTexType data;
	ArcNode* theArc;
};

//�ڽӱ���
class GraphLJB
{
private:
	VexNode *vertices; //�����
	int vexNum, arcNum; //������������
public:
	GraphLJB(int node, int line);
	void initializeTheVertexTable();
	int LocateVex(char node);
	void Create();
	void DFS_AL();
};