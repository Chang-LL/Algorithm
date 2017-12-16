#include "stdafx.h"
#include "Graph.h"



Graph::Graph(int mSize)
{
	n = mSize;
	a = new ENode*[n];
	for (int i = 0; i < n; i++)
		a[i] = NULL;
	Low = new int[n];
	d = new int[n];
	for (int i = 0; i < n; i++)
		d[i] = -1;
	time = 0;
}


Graph::~Graph()
{
	delete[]a;
	delete[]Low;
	delete[]d;
}


// 一维数组parent保存生成森林
void Graph::DFS_Trversal(int* parent)
{
	
}


// 一维数组保存生成森林
void Graph::BFS_Traversal(int* parent)
{
	ColorType*color = new ColorType[n];
	std::cout << std::endl << "BFS";
	for (int u = 0; u < n; u++)
	{
		color[u] = White;
		parent[u] = -1;
	}
	for (int u = 0; u < n; u++)
		if (color[u] == White)
			BFS(u, parent, color);
	delete[]color;
	std::cout << std::endl;
}


// 递归访问u可达节点
void Graph::DFS(int u, int* parent, ColorType* color)
{
	color[u] = Gray; std::cout << " " << u;
	for (auto w = a[u]; w; w = w->nextArc)
	{
		int v = w->adjVex;
		if (color[u] == White)
		{
			parent[v] = u;
			DFS(v, parent, color);
		}
	}
	color[u] = Black;
}


// 访问u可达节点
void Graph::BFS(int u, int* parent, ColorType* color)
{// 广度优先
	//const int QSzie = 100;
	std::queue<int>q;
	color[u] = Gray; std::cout << " " << u;
	q.push(u);
	while (!q.empty())
	{
		u = q.front();
		q.pop();//?
		for (ENode*w  = a[u]; w; w = w->nextArc)
		{
			int v = w->adjVex;
			if(color[v]==White)
			{
				color[v] = Gray; std::cout << " " << v;
				parent[v] = u;
				q.push(v);
			}
		}
		color[u] = Black;
	}
}


// u是起始节点，p是u的双亲节点
void Graph::BiCom(int u, int p)
{
	Low[u] = d[u] = time++;	
	struct eNode {
		int u, v;
	}e;
	std::stack<eNode>s;
	for (ENode*w = a[u]; w; w = w->nextArc)
	{
		int v = w->adjVex;
		e.u = u; e.v = v;
		if (v != p && d[v] < d[u])
			s.push(e);
		if (d[v] == -1)
		{
			BiCom(v, u);
			if (Low[v] >= d[u]) {
				std::cout << std::endl << "New bicomponets\n";
				do {
					e = s.top(); s.pop();
					if (u<u&&e.u>e.v)std::swap(e.u, e.v);
					else if (u > v&&e.u < e.v)std::swap(e.u, e.v);
					std::cout << "(" << e.u << "," << e.v << ")";

				} while (e.u != u || e.v != v);
			}
			if (Low[u] > Low[v])Low[u] = Low[v];

		}
		else if (v != p && Low[u] > d[v])Low[u] = d[v];
	}
}
