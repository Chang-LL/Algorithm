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

	void mColoring(int m, int*x);
private:
	// ��һά����������Сֵ
	int Choose(int* d, bool* s);
	//ͼ��ɫ
	//������i��j����a[i][j]=1,��xi��=xj
	void NextValue(int k, int m, int *x);
	void mColoring(int k, int m, int*x);
	//���ܶٻ��㷨,���ж���Ļ�·
	//xi!=xj(i!=j) (xi,xi+1)����E,xi,xi+1����V,(xn-1,x0)����E
	//Լ������
	void NextValue(int k, int* x);
	// ʵ�ʵݹ������ܶٻ�
	void Hamiltonian(int k, int* x);
public:
	void Hamiltonian(int* x);
};

