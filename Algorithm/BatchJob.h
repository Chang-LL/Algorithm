#pragma once
//批处理作业调度
class BatchJob
{
public:
	BatchJob(int sz,int*aa,int*bb,int up);
	~BatchJob();
	// 求最优调度方案和最小FT值
	int JobSch(int* x);
private:
	int* a;
	int* b;
	int n;
	int U;//保存输入数据
	int f, f1, *f2, *y;//局部数据
	// 递归函数
	void JobSch(int i, int* x);
};

