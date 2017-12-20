#include "stdafx.h"
#include "SumOfSub.h"
//s目前的和 k索引 r 数组w的和 x标志数组 m所要求和 w集合
void SumOfSub(float s, int k, float r, int * x, float m, float * w)
{
	x[k] = 1;
	if (s + w[k] == m) {
		for (int j = 0; j <= k; j++)
		{
			std::cout << x[j] << ' ';
		}
		std::cout << std::endl;
	}
	else if (s + w[k] + w[k + 1] <= m)//左子树
	{
		SumOfSub(s + w[k], k + 1, r - w[k], x, m, w);
	}
	if ((s + r - w[k] >= m) && s + w[k + 1] <= m)//右子树
	{
		x[k] = 0;
		SumOfSub(s, k + 1, r - w[k], x, m, w);
	}
}

void SumOfSub(int * x, int n, float m, float * w)
{
	float r = 0;
	for (int i = 0; i < n; i++)// 计算r
	{
		r += w[i];
	}
	std::sort(w, w + n);//wi<=wi+1
	if (r >= m && w[0] <= m)
		SumOfSub(0, 0, r, x, m, w);
}
