#pragma once
class LCS
{
public:
	LCS(int nx,int ny,char*x,char*y);//������άc��s ��һάa b ���г�ʼ��
	~LCS();
	
private:
	void CLCS(int i, int j);
	int** c;//c[i][j] a[i] to b[j]������������г���
	int** s;
	int m;
	int n;
	char* a;
	char* b;
public:
	// �����Ž�ֵ//����������г���
	void LCSLength();
	// �������Ž�//�����������
	void CLCS();
//	
};

