#include "stdafx.h"
#include "MatrixChain.h"

//������ά����m s һάp����ʼ��
MatrixChain::MatrixChain(int mSize, int * q)
{

}

MatrixChain::~MatrixChain()
{
}


// һ�㶯̬�滮�����Ž�ֵ
int MatrixChain::MChain()
{//��A[0:n-1]�����Ž�ֵ
	for (int i = 0; i < n; i++)m[i][i] = 0;
	for(int r=2;r<=n;r++)
		for (int i = 0; i <= n - r; i++)
		{
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i] * p[i + 1] * p[j + 1];
			s[i][j] = i;
			for (int k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}

	return m[0][n-1];
}


// ����¼�������
int MatrixChain::LookupChain()
{
	return LookupChain(0,n-1);
}


// �������Ž�Ĺ��к���
void MatrixChain::Traceback()
{
	std::cout << '(';
	Traceback(0, n - 1);
	std::cout << ")\n";
	
}


// �������Ž��˽�еݹ麯��
void MatrixChain::Traceback(int i, int j)
{
	using std::cout;
	if (i == j) { cout << 'A' << j; return; }

	if (i < s[i][j])cout << '(';
	Traceback(i, s[i][j]);
	if (i < s[i][j])cout << ')';

	if (s[i][j] + 1 < j)cout << '(';
	Traceback(s[i][j] + 1, j);
	if (s[i][j] + 1 < j)cout << ')';
}


// ����¼����˽�еݹ�
int MatrixChain::LookupChain(int i, int j)
{
	if (m[i][j] > 0)return m[i][j];//�������Ѿ����ֱ������
	if (i == j)return 0;
	int u = LookupChain(i + 1, j) + p[i] * p[i + 1] * p[j + 1];//���ʼ��Сֵ
	s[i][j] = i;
	for (int k = i + 1; k < j; k++)
	{
		int t = LookupChain(i, k) + LookupChain(k + 1, j) + p[i] * p[k + 1] * p[j + 1];
		if (t < u) {
			u = t;
			s[i][j] = k;
		}
	}
	m[i][j] = u; return u;//���沢������Сֵ
	return 0;
}
