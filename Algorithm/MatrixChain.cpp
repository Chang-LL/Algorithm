#include "stdafx.h"
#include "MatrixChain.h"

//创建二维数组m s 一维p，初始化
MatrixChain::MatrixChain(int mSize, int * q)
{

}

MatrixChain::~MatrixChain()
{
}


// 一般动态规划求最优解值
int MatrixChain::MChain()
{//求A[0:n-1]的最优解值
	for (int i = 0; i < n; i++)m[i][i] = 0;
	for(int r=2;r<=n;r++)
		for (int i = 0; i <= n - r; i++)
		{
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i] * p[i + 1] * p[j + 1];
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}

	return m[0][n-1];
}


// 备忘录方法求解
int MatrixChain::LookupChain()
{
	return LookupChain(0,n-1);
}


// 构造最优解的公有函数
void MatrixChain::Traceback()
{
	std::cout << '(';
	Traceback(0, n - 1);
	std::cout << ")\n";
	
}


// 构造最优解的私有递归函数
void MatrixChain::Traceback(int i, int j)
{
	using std::cout;
	if (i == j) { cout << 'A' << j; return; }

	if (i < s[i][j])cout << '(';
	Traceback(i, s[i][j]);
	if (i < s[i][j])cout << ')';

	if (s[i][j] + 1 < j)cout << '(';
	Traceback(s[i][j] + 1, j);
	if (s[i][j] + 1 < j)cout << ')';
}


// 备忘录方法私有递归
int MatrixChain::LookupChain(int i, int j)
{
	if (m[i][j] > 0)return m[i][j];//子问题已经求解直接引用
	if (i == j)return 0;
	int u = LookupChain(i + 1, j) + p[i] * p[i + 1] * p[j + 1];//求初始最小值
	s[i][j] = i;
	for (int k = i + 1; k < j; k++)
	{
		int t = LookupChain(i, k) + LookupChain(k + 1, j) + p[i] * p[k + 1] * p[j + 1];
		if (t < u) {
			u = t;
			s[i][j] = k;
		}
	}
	m[i][j] = u; return u;//保存并返回最小值
	return 0;
}
