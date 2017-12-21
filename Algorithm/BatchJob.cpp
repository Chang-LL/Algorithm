#include "stdafx.h"
#include "BatchJob.h"

BatchJob::BatchJob(int sz, int * aa, int * bb, int up)
{
	n = sz; U = up; f = f1 = 0;
	a = new int[n]; b = new int[n];
	f2 = new int[n]; y = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = aa[i]; b[i] = bb[i]; y[i] = i;
	}
}

BatchJob::~BatchJob()
{
}


// 求最优调度方案和最小FT值
int BatchJob::JobSch(int* x)
{
	//一维数组x保存最优作业调度方案
	//返回最小FT
	JobSch(0,x);
	return U;
}


// 递归函数
void BatchJob::JobSch(int i, int* x)
{
	if (i == n) {//记录迄今为止的最优解
		for (int i = 0; i < n; i++)
		{
			x[i] = y[i];
		}
		U = f;
	}
	else
	{
		for (int j = i; j < n; j++) {//考察剩余作业的各种可能排列
			f1 += a[y[j]];//第i个处理作业j
			f2[i] = ((f2[i - 1] > f1) ? f2[i - 1] : f1)
				+ b[y[j]];//p2执行必须在f1+a[i]时间之后开始
			f += f2[i];//累计作业i的完成时间f2[i]
			if (f < U) {
				std::swap(y[i],y[j]);
				JobSch(i + 1, x);
				std::swap(y[i], y[j]);//选择新的排列
			}
			f1 -= a[y[j]]; f -= f2[i];//恢复原来的f和f1值
		}
	}
}
