#pragma once
template<typename T>
class MGraph
{
public:
	MGraph();
	~MGraph();
private:
	int n;
	T** a;
public:
	// 迪杰斯特拉算法
	void Disjkstra(int s, T*& d, int*& path);
	//弗洛伊德算法
	void Floyd(T**&d, int**&path);

	void mColoring(int m, int*x);
private:
	// 在一维数组里求最小值
	int Choose(int* d, bool* s);
	//图着色
	//对所有i和j，若a[i][j]=1,则xi！=xj
	void NextValue(int k, int m, int *x);
	void mColoring(int k, int m, int*x);
	//哈密顿环算法,所有顶点的回路
	//xi!=xj(i!=j) (xi,xi+1)属于E,xi,xi+1属于V,(xn-1,x0)属于E
	//约束函数
	void NextValue(int k, int* x);
	// 实际递归计算哈密顿环
	void Hamiltonian(int k, int* x);
public:
	void Hamiltonian(int* x);
};

