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
	mColoring(0, m, x);
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
{//在[1:m]中为x[k]确定一个最小的且不与其邻接点冲突的颜色
	//x[k]=0表示没有可用颜色，颜色从1开始编号
	int j;
	do {
		x[k] = (x[k] + 1) % (m + 1);//尝试下一种颜色
		if (!x[k])return;//没有可用颜色
		for (j = 0; j < k; j++)
		{
			if (a[k][j] && x[k] == x[j])//(i,j)是图的边，且相邻节点k和j颜色相同
				break;//冲突，选下一种颜色
		}
		if (j == k)return;//成功选择，返回
	} while (1);
}

template<typename T>
void MGraph<T>::mColoring(int k, int m, int * x)
{
	do {
		NextValue(k, m, x);//为x[k]分配颜色
		if (!x[k])break;//x[k]=0表示没有合适的颜色
		if (k == n - 1)//得到一种m-着色方案
		{
			for (int i = 0; i < n; i++)
				std::cout << x[i] << ' ';
			std::cout << std::endl;
		}
		else mColoring(k + 1, m, x);//已经对前k个节点分配颜色，尝试其余节点
	} while (true);
}

// 哈密顿环算法，约束函数
template<typename T>
void MGraph<T>::NextValue(int k, int* x)
{
	do {
		x[k] = (x[k] + 1) % n;//下一个节点
		if (!x[k])return;
		if (a[x[k - 1]][x[k]]) {//(x[k-1],x[k]是否为边
			for (int j = 0; j < k; j++)//检查与前k个节点是否相同
				if (x[j] == x[k])
					break;//重复
			if (j == k)//可取
				if ((k < n - 1) || (k == n - 1) && a[x[n - 1]][x[0]])
					return;
		}
	} while (true);
}

// 实际递归计算哈密顿环
template<typename T>
void MGraph<T>::Hamiltonian(int k, int* x)
{
	do {
		NextValue(k, x);
		if (!x[k])return;
		if (k == n - 1) {
			for (int i = 0; i < n; i++)
			{
				std::cout << x[i] << " ";
			}
			std::cout << "0\n";
		}
		else Hamiltonian(k + 1, x);
	} while (true);
}

template<typename T>
void MGraph<T>::Hamiltonian(int* x)
{
	Hamiltonian(1, x);
}
