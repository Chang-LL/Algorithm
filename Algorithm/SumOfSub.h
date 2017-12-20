#pragma once
//子集和数算法
/*
	已知n个不同的正数wi(0<=i<=n-1)的集合
	求该集合所有满足条件的子集
	使得每个子集中的正数之和等于给定的另一个正数M
*/
//前置条件
//wi<=wi+1(0<=i<n-1) s+r>=m&&s+wk<=m 
//(s=(i:0 - k-1)求和wixi,r=(i:k - n-1)求和wi
//后置条件
//在以x0,x1...xk为根的子树上搜索答案状态
void SumOfSub(float s, int k, float r, int*x, float m, float*w);
void SumOfSub(int*x, int n, float m, float*w);