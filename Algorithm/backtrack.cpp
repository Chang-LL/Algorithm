#include "stdafx.h"
////T()表示x[k]可以取值的集合
////B()为约束函数
////递归回溯法
//void RBacktrack(int k)
//{//k 应该为0
//	for (每个x[k], 使得x[k]属于
//		T(x[0], ..., x[k - 1]) && (B(x[0], .., x[k])))
//	{
//		if (x[0], ..x[k]是一个可行解)
//			输出(x[0], ..x[k]);
//		RBacktrack(k+1);//深度优先下一层
//	}
//
//}
//
////迭代回溯法
//void IBacktrack(int n)
//{
//	int k = 0;
//	while (k >= 0)
//	{
//		if (还剩下未检测的x[k], 使得x[k]属于
//			T(x[0], ..., x[k - 1]) && (B(x[0], .., x[k])))
//		{
//			if (x[0], ..x[k]是一个可行解)//考虑x[k]的下一个取值
//			输出(x[0], ..x[k]);
//			k++;//考虑下一层
//		}
//		else k--;//回溯到上一层
//	}
//}

//蒙特卡罗算法
//集合S是未受限的xk的取值
//Size()返回S的大小
//Choose()从集合S中为xk随机选择一个值，生成一条随机路径
//int Estimate(SType*x)
//{
//	int k = 0, m = 1, r = 1;
//	do {
//		SetType S = { x[k] | x[k]属于
//			T(x[0], ..., x[k - 1]) && (B(x[0], .., x[k]) == true) };
//		if (!Size(S))return m;
//		r = r * Size(S); m = m + r;
//		x[k] = Choose(S); k++;
//	} while (true);
//}