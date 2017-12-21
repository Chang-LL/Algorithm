#include "stdafx.h"
#include "Ksack.h"


template<typename T>
Ksack<T>::Ksack(int mSize, T cap, T * wei, T * prof)
{
}

template<typename T>
Ksack<T>::~Ksack()
{
}

template<typename T>
T Ksack<T>::BKnapsack(int * x)
{
	//一维数组x返回最优解 函数返回最优解值
	int y[n] = { 0 };//TODO 可能有问题
	T fp;
	BKnapsack(0, 0, 0, fp, x, y);
	return fp;
}

template<typename T>
inline void Ksack<T>::BKnapsack(int k, T cp, T cw, T & fp, int * x, int * y)
{
	//cp是当前收益 cw是当前背包重量 k是当前待考察的物品编号
	//p[i]/w[i]>=p[i+1]/w[i+1]
	//fp是当前最大收益
	//考察左孩子节点
	int j; T bp;
	if (cw + w[k] <= m) {//左子树需要重新计算约束函数，无需计算子树的上界函数
		y[k] = 1;
		if (k < n - 1)
			BKnapsack(k + 1, cp + p[k], cw + w[k], fp, x, y);
		if (cp + p[k] > fp&&k == n - 1) {
			fp = cp + p[k];//找到一个收益更高的可行解
			for (j = 0; j <= k; j++)x[j] = y[j];//x[]保存对应fp的可行解
		}
	}
	//考察右子树节点
	if (Bound(k, cp, cw) >= fp) {//对右子树重新计算上界函数
		y[k] = 0;
		if (k < n - 1)BKnapsack(k + 1, cp, cw, fp, x, y);
		if (cp > fp&&k == n - 1) {//找到一个。。。。
			fp = np;
			for (j = 0; j <= k; j++)x[j] = y[j];//。。。
		}
	}

}

template<typename T>
T Ksack<T>::Bound(int k, T cp, T cw)
{
	//cp是当前收益 cw是当前背包重量 k是当前待考察的物品编号
	T b = cp, c = cw;
	for (int i = k+1; i < n; i++)
	{
		c += w[i];
		if (c < m)b += p[i];
		else return (b + (1 - (c - m) / w[i])*p[i]);
	}
	return b;
}
