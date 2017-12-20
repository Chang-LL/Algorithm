#include "stdafx.h"
#include "MGraph.h"

template<typename T>
MGraph<T>::MGraph()
{
	n = 0;
}

template<typename T>
MGraph<T>::~MGraph()
{
}


//void MGraph::Disjkstra(int s)
//{
//}


// 迪杰斯特拉算法
//d s到i的最短路径长度
//path s到i的最短路径的i的前一个节点
template<typename T>
void MGraph<T>::Disjkstra(int s, T*& d, int*& path)
{
	int k, i, j;
	if (s<0 || s>n - 1)
		throw "OutOfBounds";
	bool*inS = new bool[n];
	d = new T[n]; path = new int[n];
	for (int i = 0; i < n; i++)
	{
		inS[i] = false;
		d[i] = a[s][i];
		if (i != s && d[i] < INFINITY)path[i] = s;
		else path[i] = -1;
	}
	inS[s] = true; d[s] = 0;//源点
	for (int i = 0; i < n - 1; i++)//n-1条最短路径
	{
		k = Choose(d, inS);//下一条最短的k
		inS[k] = true;
		for (int j = 0; j < n; j++)//更新d和path
		{
			if (!inS[j] && d[k] + a[k][i] < d[i])
			{
				d[j] = d[k] + a[k][j];
				path[j] = k;
			}
		}
	}
}

template<typename T>
void MGraph<T>::Floyd(T **& d, int **& path)
{
	//d保存各条最短路径的长度d[i][j]=i to j
	int i, j, k;
	d = new T*[n]; path = new int*[n];
	for (i = 0; i < n; i++)
	{
		d[i] = new T[n]; path[i] = new int[n];
		for ( j = 0; j < n; j++)
		{
			d[i][j] = a[i][j];
			if (i != j && w[i][j] < INFINITY)
				path[i][j] = i;
			else path[i][j] = -1;
		}
	}
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					path[i][j] = path[k][j];
				}
}

template<typename T>
void MGraph<T>::mColoring(int m, int * x)
{
}


// 在一维数组里求最小值
template<typename T>
int MGraph<T>::Choose(int* d, bool* s)
{
	int i, minpos;
	T min;
	min = INFINITY;
	minpos = -1;
	for (int i = 1; i < n; i++)
	{
		if (d[i] < min && !s[i])
		{
			min = d[i];
			minpos = i;
		}
	}
	return minpos;
}

template<typename T>
void MGraph<T>::NextValue(int k, int m, int * x)
{
	int j;
	do {
		x[k] = (x[k] + 1) % (m + 1);
		if (!x[k])return;
		for (j = 0; j < k; j++)
		{
			if (a[k][j] && x[k] == x[j])
				break;
		}
		if (j == k)return;
	} while (1);
}

template<typename T>
void MGraph<T>::mColoring(int k, int m, int * x)
{
	do {
		NextValue(k, m, x);
		if (!x[k])break;
		if (k == n - 1)
		{
			for (int i = 0; i < n; i++)
				std::cout << x[i] << ' ';
			std::cout << std::endl;
		}
		else mColoring(k + 1, m, x);
	} while (true);
}
