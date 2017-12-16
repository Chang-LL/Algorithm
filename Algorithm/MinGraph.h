#pragma once
#include<queue>
#include"Knapspack.h"
template<typename T>
struct cNode
{//带权图的边结点
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
	//普里姆算法
	void Prim(int k, int* nearest, T* lowcost);
	//克鲁斯卡尔算法
	void Kruskal(std::priority_queue<hNode<T>>&pq);
	//多段图的向前递推算法
	T FMultiGraph(int k, int*p);
};

