#include "stdafx.h"
#include "Knapspack.h"

template<typename T>
Knapspack<T>::Knapspack(int mSize, float cap, float* wei, T* prof)
{
	m = 0.0f;
	n = 0;
}

template<typename T>
Knapspack<T>::~Knapspack()
{
}

// //数组x为背包问题的最优解
template<typename T>
void Knapspack<T>::GreedyKnapsack(float* x)
{//w[i]按照p[i]/w[i]非增次序排序
	float u = m;// 背包剩余载重量
	for (int i = 0; i < n; i++)
	{
		x[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (w[i] > u)
			break;
		x[i] = 1.0;
		u -= w[i];
	}
	if (i < n)
	{
		x[i] = u / w[i];
	}
}

//template<typename T>
//void Knapspack<T>::GreedyJob(int d[], Set x, int n)
//{//p0>=p1>=p2...pn-1
//	X = { 0 };
//	for (int i = 0; i < n; i++)
//	{
////		if (/*set X U{i}可以在给定的时限内完成*/)
////			X = XU{ i };
//	}
//}

template<typename T>
int Knapspack<T>::JS(int * d, int * x, int n)
{//p0>=p1...收益
	//x 解向量 d  时限
	int k = 0;
	x[0] = 0;
	for (int j = 1; j < n; j++)
	{
		int r = k;//j插入位置
		while (r >= 0
			&& d[x[r]] > d[j] && d[x[r]] > r + 1)
			r--;
		if ((r < 0 || d[x[r]] <= d[j]) && d[x[r]] > r + 1)
		{
			for (int i = k; i >= r + 1; i--)
			{
				x[i + 1] = x[i];
			}
			x[r + 1] = j;//j插入r+1处
			k++;
		}
	}
	return 0;
}

template<typename T>
int Knapspack<T>::FJS(int * d, int * x, int n)
{
	T s(n);//n棵树的并查集
	int b, k = -1, *f = new int[n + 1];
	for (int i = 0; i < = n; i++)
	{
		f[i] = i;//作业i时间片i-1，i
	}
	for (int i = 0; i < n; i++)
	{
		if (n < d[i])b = n;
		else b = d[i];
		int r = s.find(b);
		if (f[r]) {
			x[++k] = i;
			int t = s.find(f[r] - 1);//寻找时限为 的树根t
			s.Union(t, r);
			f[r] = f[t];
		}
	}
	delete[]f;
	return k;
}

template<typename T>
BTNode<T>* Knapspack<T>::CreateHfmTree(T * w, int n)
{//w为一维数组保存权值
	std::priority_queue<HNode<T>>pq(2 * n - 1);
	BTNode<T>*p; HNode<T>a, b;
	for (int i = 0; i < n; i++)
	{
		p = new BTNode<T>(w[i]);
		a.ptr = p; a.weight = w[i];//权值为根
		pq.pop(a);//n棵只有根的二叉树，队列
	}
	for (int i = 0; i < n; i++)//两两合并n-1次，n棵树-1棵树
	{
		pq.pop(a); pq.pop(b);//权值最小的两棵树
		a.weight += b.weight;
		p = new BTNode<T>(a.weight, a.ptr, b.ptr);
		a.ptr = p;
		pq.pop(a);//进队新树
	}
	pq.push(a);//取树返回
	return a.ptr;
}
//程序按非减次序排序
template<typename T>
void Knapspack<T>::Store(int n, int m)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		std::cout << "将程序" << i
			<< " 加到磁带" << j << std::endl;
		j = (j + 1) % m;
	}
	std::cout << std::endl;
}
