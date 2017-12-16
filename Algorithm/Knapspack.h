#pragma once
#include<queue>
template<typename T>
struct HNode
{
	operator T()const { return weight; }
	BTNode<T>*ptr;
	T weight;
};
template<typename T>
struct hNode
{
	operator T()const { return w; }
	int u, v;
	T w;
};
template<typename T>
class Knapspack
{
public:
	Knapspack(int mSize, float cap, float* wei, T* prof);
	~Knapspack();
private:
	float m;//背包载重量
	float *w;//存储n个背包重量的数组
	T* p;//存储n个物品收益的数组
	int n;//物品数目
public:
	//数组x为背包问题的最优解
	void GreedyKnapsack(float* x);
	//X为解集合
//	void GreedyJob(int d[], Set x, int n);
	//带时限的作业排序
	int JS(int *d, int *x, int n);
	int FJS(int *d, int *x, int n);
	BTNode<T>* CreateHfmTree(T*w, int n);
	//多带最优存储
	//n个程序 m个磁带
	void Store(int n, int m);

};

