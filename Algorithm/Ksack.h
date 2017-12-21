#pragma once
//0/1���������㷨
//����M>0,wi>0,pi>0(0<=i<n),Ҫ��һ��nԪ��(x0,x1,...,xn-1)
//xi����{0,1}  0<=i<n ʹ��(i:[0:n))���wi * xi<=M
//�� (i:[0:n))���pi * xi ���
template<typename T>
class Ksack
{
public:
	Ksack(int mSize,T cap,T*wei,T*prof);
	~Ksack();
protected:
	int n;
	T m;
	T* w;//Ҫ��p[i]/w[i]>=p[i+1]/w[i+1]
	T* p;
public:

	T BKnapsack(int* x);
protected:

	void BKnapsack(int k, T cp, T cw, T& fp, int* x, int* y);
	T Bound(int k, T cp, T cw);
};

