#pragma once
//矩阵连乘算法
class MatrixChain
{
public:
	MatrixChain(int mSize,int*q);
	~MatrixChain();
private:
	int *p;//A[i]维数 p[i] x p[i+1]
	int **m;//m[i][j] A[i:j]的最少次数
	int **s;//s[i][j] 使m[i][j]最小的k
	int n;
public:
	// 一般动态规划求最优解值
	int MChain();
	// 备忘录方法求解
	int LookupChain();
	// 构造最优解的公有函数
	void Traceback();
protected:
	// 构造最优解的私有递归函数
	void Traceback(int i, int j);
private:
	// 备忘录方法私有递归
	int LookupChain(int i, int j);
};

