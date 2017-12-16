#pragma once
class LCS
{
public:
	LCS(int nx,int ny,char*x,char*y);//创建二维c，s 和一维a b 进行初始化
	~LCS();
	
private:
	void CLCS(int i, int j);
	int** c;//c[i][j] a[i] to b[j]的最长公共子序列长度
	int** s;
	int m;
	int n;
	char* a;
	char* b;
public:
	// 求最优解值//最长公共子序列长度
	void LCSLength();
	// 构造最优解//最长公共子序列
	void CLCS();
//	
};

