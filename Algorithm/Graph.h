#pragma once
#include<queue>
#include<stack>
enum ColorType
{
	White, Gray, Black
};
struct ENode
{
	int adjVex;
	ENode*nextArc;
};
class Graph
{
public:
	Graph(int mSize);
	~Graph();
protected:
	ENode * * a;
	int n;
	int*Low, *d;
	int time;
public:
	// һά����parent��������ɭ��
	void DFS_Trversal(int* parent);
	// һά���鱣������ɭ��
	void BFS_Traversal(int* parent);
protected:
	// �ݹ����u�ɴ�ڵ�
	void DFS(int u, int* parent, ColorType* color);
	// ����u�ɴ�ڵ�
	void BFS(int u, int* parent, ColorType* color);
	// u����ʼ�ڵ㣬p��u��˫�׽ڵ�
	void BiCom(int u, int p);
};

