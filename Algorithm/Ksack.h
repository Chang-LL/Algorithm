#pragma once
//0/1背包回溯算法
//给定M>0,wi>0,pi>0(0<=i<n),要求一个n元组(x0,x1,...,xn-1)
//xi属于{0,1}  0<=i<n 使得(i:[0:n))求和wi * xi<=M
//且 (i:[0:n))求和pi * xi 最大
template<typename T>
class Ksack
{
public:
	Ksack(int mSize,T cap,T*wei,T*prof);
	~Ksack();
protected:
	int n;
	T m;
	T* w;//要求p[i]/w[i]>=p[i+1]/w[i+1]
	T* p;
public:

	T BKnapsack(int* x);
protected:

	void BKnapsack(int k, T cp, T cw, T& fp, int* x, int* y);
	T Bound(int k, T cp, T cw);
};

