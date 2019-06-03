#pragma once
typedef char VerTexType;
typedef int ArcType;

//���ڵ�
struct ArcBox
{
	int tailVext, headVext; //�û���β��ͷ�����λ��
	ArcBox* hlink, * tlink; //�ֱ�Ϊ��ͷ��ͬ�ͻ�β��ͬ������
	int length;
};
//����ڵ�
struct vexNode
{
	VerTexType data;
	ArcBox* linein, * lineout; //ָ��������뻡
};
//ʮ������
class GraphSZLB
{
private:
	int vexnum, arcnum; //������������
	vexNode* xlist;
public:
	GraphSZLB(int num1, int num2);
	void Init();
	int LocateVex(char node);
	void Create();
	void Traver();
};
