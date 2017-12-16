#pragma once
//0/1±³°ü
#define NoAns
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
	int n;
	int* b;
	float m;
	float* w;
	XP* p;
	T* pf;
public:
	T DKnap(int* x);
private:
	T DKnap();
	void TraceBack(int* x);
	int Largest(int low, int high, int i);
public:
	T RKnap();
private:
	T f(int j, float X);
};

