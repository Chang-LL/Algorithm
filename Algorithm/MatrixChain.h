#pragma once
//���������㷨
class MatrixChain
{
public:
	MatrixChain(int mSize,int*q);
	~MatrixChain();
private:
	int *p;//A[i]ά�� p[i] x p[i+1]
	int **m;//m[i][j] A[i:j]�����ٴ���
	int **s;//s[i][j] ʹm[i][j]��С��k
	int n;
public:
	// һ�㶯̬�滮�����Ž�ֵ
	int MChain();
	// ����¼�������
	int LookupChain();
	// �������Ž�Ĺ��к���
	void Traceback();
protected:
	// �������Ž��˽�еݹ麯��
	void Traceback(int i, int j);
private:
	// ����¼����˽�еݹ�
	int LookupChain(int i, int j);
};

