/*
	流水线作业调度问题 （flow shop schedule）
	设一条流水线上有n个作业J={J0,J1...Jn-1}和m台设备P={P1,P2...Pm}。
	每个作业需依次执行m个任务，其中第j个任务只能在第j台设备上执行
	每台设备任一时刻只能处理一项任务
	依次执行:第j-1项任务未完成时不可以处理第j项任务
	设第i个作业的第j项任务Tij所需时间为tij。
	将n * m个任务分配给m台设备
*/
#include"stdafx.h"
#include<math.h>
#include<algorithm>
struct Triplet
{
	int operator<(Triplet b)const { return t < b.t; }
	int jobNo, t, ab;//作业号，处理时间，设备号
};


void FLowShop(int n, int*a, int*b, int *c)
{
	//a[i]和b[i]分别为作业i在两台设备上的处理时间
	const int mSize = 100;
	Triplet d[mSize] = { {0,0,0} };
	for (int i = 0; i < n; i++)//生成三元组表
		if (a[i] < b[i]) {
			d[i].jobNo = i;
			d[i].ab = 0;
			d[i].t = a[i];
		}
		else {
			d[i].jobNo = i;
			d[i].ab = 1;
			d[i].t = b[i];
		}
	std::sort(d, d+n);//排序
	int left = 0, right = n - 1;
	for (int i = 0; i < n; i++)//生成最优解
		if (d[i].ab == 0)c[left++] = d[i].jobNo;
		else c[right--] = d[i].jobNo;
}