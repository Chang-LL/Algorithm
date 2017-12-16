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
private:
	// 在一维数组里求最小值
	int Choose(int* d, bool* s);
};

