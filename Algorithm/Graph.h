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
	// 一维数组parent保存生成森林
	void DFS_Trversal(int* parent);
	// 一维数组保存生成森林
	void BFS_Traversal(int* parent);
protected:
	// 递归访问u可达节点
	void DFS(int u, int* parent, ColorType* color);
	// 访问u可达节点
	void BFS(int u, int* parent, ColorType* color);
	// u是起始节点，p是u的双亲节点
	void BiCom(int u, int p);
};

