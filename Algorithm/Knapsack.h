#pragma once
//0/1����
#define NoAns
//��Ծ��(X,P)
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
	//p b ������Ϣ�������Ž�
	int n;
	//ָʾ����si������p����ʼ��ż���±�
	int* b;
	float m;
	float* w;
	//˳��洢����s0 s1...����ż
	XP* p;
	T* pf;
public:
	//�����������
	T DKnap(int* x);
private:
	T DKnap();
	void TraceBack(int* x);
	//��ʹ��p[u].X+w[i]�������������ص�����±�u
	int Largest(int low, int high, int i);
public:
	T RKnap();
private:
	T f(int j, float X);
};

