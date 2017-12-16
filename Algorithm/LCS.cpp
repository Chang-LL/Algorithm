#include "stdafx.h"
#include "LCS.h"




LCS::LCS(int nx, int ny, char * x, char * y)
{
}

LCS::~LCS()
{
}


// 求最优解值//最长公共子序列长度
void LCS::LCSLength()
{
	for (int i = 1; i <= m; i++)c[i][0] = 0;
	for (int i = 1; i <= n; i++)c[0][i] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i] == b[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				s[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j]; s[i][j] = 2;
			}
			else {
				c[i][j] = c[i][j - 1]; s[i][j] = 3;
			}
}


// 构造最优解//最长公共子序列
void LCS::CLCS()
{
}


void LCS::CLCS(int i, int j)
{
	if (i == 0 || j == 0)return;
	if (s[i][j] == 1) {
		CLCS(i - 1, j - 1);
		std::cout << a[i];
	}
	else if (s[i][j] == 2)CLCS(i - 1, j);
	else CLCS(i, j - 1);
}
