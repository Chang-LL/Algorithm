#pragma once
//0/1背包
#define NoAns
//阶跃点(X,P)
struct XP
{
	float X, P;
};
template<typename T>
class Knapsack
{
public:
	Knapsack(int mSize,float cap,float*wei,T*prof);
	~Knapsack();
private:
	//p b 保存信息构造最优解
	int n;
	//指示集合si在数组p的起始序偶的下标
	int* b;
	float m;
	float* w;
	//顺序存储集合s0 s1...的序偶
	XP* p;
	T* pf;
public:
	//返回最大收益
	T DKnap(int* x);
private:
	T DKnap();
	void TraceBack(int* x);
	//求使得p[u].X+w[i]不超过背包载重的最大下标u
	int Largest(int low, int high, int i);
public:
	T RKnap();
private:
	T f(int j, float X);
};

