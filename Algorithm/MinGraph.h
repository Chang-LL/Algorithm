#pragma once
#include<queue>
#include"Knapspack.h"
template<typename T>
struct cNode
{//��Ȩͼ�ı߽��
	int adjVex;
	T w;
	cNode*nextArc;
};
template<typename T>
class MinGraph
{
public:
	MinGraph(int mSize);
	~MinGraph();
protected:
	cNode<T>** a;
	int n;
public:
	void Prim(int s);
protected:
	//����ķ�㷨
	void Prim(int k, int* nearest, T* lowcost);
	//��³˹�����㷨
	void Kruskal(std::priority_queue<hNode<T>>&pq);
	//���ͼ����ǰ�����㷨
	T FMultiGraph(int k, int*p);
};

