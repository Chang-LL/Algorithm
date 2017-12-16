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
	float m;//����������
	float *w;//�洢n����������������
	T* p;//�洢n����Ʒ���������
	int n;//��Ʒ��Ŀ
public:
	//����xΪ������������Ž�
	void GreedyKnapsack(float* x);
	//XΪ�⼯��
//	void GreedyJob(int d[], Set x, int n);
	//��ʱ�޵���ҵ����
	int JS(int *d, int *x, int n);
	int FJS(int *d, int *x, int n);
	BTNode<T>* CreateHfmTree(T*w, int n);
	//������Ŵ洢
	//n������ m���Ŵ�
	void Store(int n, int m);

};

