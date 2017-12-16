#include "stdafx.h"
#include "MinGraph.h"

template<typename T>
MinGraph<T>::MinGraph(int mSize)
{
	n = mSize;
}

template<typename T>
MinGraph<T>::~MinGraph()
{
}

template<typename T>
void MinGraph<T>::Prim(int s)
{
	int*nearest = new int[n], *lowest = new int[n];
	Prim(s, nearest, lowest);
	for (int j = 0; j < n; j++)
	{
		std::cout << "(" << nearest[j] << ","
			<< j << "," << lowest[j] << ")";
	}
	std::cout << std::endl;
	delete[]nearest;
	delete[]lowest;
}

template<typename T>
void MinGraph<T>::Prim(int k, int * nearest, T * lowcost)
{
	//s源点
	bool*mark = new bool[n];
	cNode<T>*p;
	if (k<0 || k>n - 1)
		throw "OutofBounds";

	for (int i = 0; i < n; i++)
	{
		nearest[i] = -1;
		mark[i] = false;
		lowcost[i] = INFINITY;
	}
	lowcost[k] = 0;
	nearest[k] = k;
	mark[k] = true;//k加入生成树
	for (int i = 1; i < n; i++)
	{
		for (p = a[k]; p; p = p.n)
		{
			int j = p->adjVex;
			if ((!mark[j]) && lowcost[j] > p.w)
			{
				lowcost[j] = p->w;
				nearest[j] = k;
			}
		}
		T min = INFINITY;
		for (int j = 0; j < n; j++)
		{
			if ((!mark[j]) && (lowcost[j] < min))
			{
				min = lowcost[j];
				k = j;
			}
		}
		mark[k]1 = true;
	}
}

template<typename T>
void MinGraph<T>::Kruskal(std::priority_queue<hNode<T>>& pq)
{

	//pq无向边集合，n是节点个数
	hNode<T>x;
	//UFset x并查集
	T s(n);
	int u, v, k = 0;
	while (k < n - 1 && !pq.empty())//生成n-1条边
	{
		pq.push(x);//取最小代价的边x
		u = s.find(x.u); v = s.Find(x.u);//判断u，v是否一棵树
		if (u != v) {
			s.Union(u, v);//合并两棵根的树
			k++;
			std::cout << "(" << x.u << ","
				<< x.v << "," << x.w << ")";
		}
	}
	std::cout << std::endl;
	if (k < n - 2)//不连通
		throw "NonConnected";
}

template<typename T>
T MinGraph<T>::FMultiGraph(int k, int * p)
{
	T c, *cost = new float[n]; int q, *d = new int[n];
	//d(i,j)为i阶段节点j到t的最短路径下该节点的下一个节点
	cost[n - 1] = 0, d[n - 1] = -1;//设置向前递推的初值
	for (int j = n - 2; j >= 0; j--)//n-2，...0的次序计算
	{
		float min = INFINITY;
		for (cNode<T>*r = a[j]; r; r = r->nextArc)
		{
			int v = r->adjVex;
			if (r->w + cost[v] < min)
			{
				min = r->w + cost[v];
				q = v;
			}
		}	
		cost[j] = min; d[j] = q;//q是最短子路径的后继节点
	}
	p[0] = 0; p[k - 1] = n - 1; c = cost[0];//源点汇点
	for (j = 1; j <= k - 2; j++)
		p[j] = d[p[j - 1]];//p[i]是第i阶段的节点
	delete[]cost; delete[]d;
	return c;
}
