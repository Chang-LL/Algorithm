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
	// �Ͻ�˹�����㷨
	void Disjkstra(int s, T*& d, int*& path);
	//���������㷨
	void Floyd(T**&d, int**&path);
private:
	// ��һά����������Сֵ
	int Choose(int* d, bool* s);
};

