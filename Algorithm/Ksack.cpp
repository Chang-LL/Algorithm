#include "stdafx.h"
#include "Ksack.h"


template<typename T>
Ksack<T>::Ksack(int mSize, T cap, T * wei, T * prof)
{
}

template<typename T>
Ksack<T>::~Ksack()
{
}

template<typename T>
T Ksack<T>::BKnapsack(int * x)
{
	//һά����x�������Ž� �����������Ž�ֵ
	int y[n] = { 0 };//TODO ����������
	T fp;
	BKnapsack(0, 0, 0, fp, x, y);
	return fp;
}

template<typename T>
inline void Ksack<T>::BKnapsack(int k, T cp, T cw, T & fp, int * x, int * y)
{
	//cp�ǵ�ǰ���� cw�ǵ�ǰ�������� k�ǵ�ǰ���������Ʒ���
	//p[i]/w[i]>=p[i+1]/w[i+1]
	//fp�ǵ�ǰ�������
	//�������ӽڵ�
	int j; T bp;
	if (cw + w[k] <= m) {//��������Ҫ���¼���Լ����������������������Ͻ纯��
		y[k] = 1;
		if (k < n - 1)
			BKnapsack(k + 1, cp + p[k], cw + w[k], fp, x, y);
		if (cp + p[k] > fp&&k == n - 1) {
			fp = cp + p[k];//�ҵ�һ��������ߵĿ��н�
			for (j = 0; j <= k; j++)x[j] = y[j];//x[]�����Ӧfp�Ŀ��н�
		}
	}
	//�����������ڵ�
	if (Bound(k, cp, cw) >= fp) {//�����������¼����Ͻ纯��
		y[k] = 0;
		if (k < n - 1)BKnapsack(k + 1, cp, cw, fp, x, y);
		if (cp > fp&&k == n - 1) {//�ҵ�һ����������
			fp = np;
			for (j = 0; j <= k; j++)x[j] = y[j];//������
		}
	}

}

template<typename T>
T Ksack<T>::Bound(int k, T cp, T cw)
{
	//cp�ǵ�ǰ���� cw�ǵ�ǰ�������� k�ǵ�ǰ���������Ʒ���
	T b = cp, c = cw;
	for (int i = k+1; i < n; i++)
	{
		c += w[i];
		if (c < m)b += p[i];
		else return (b + (1 - (c - m) / w[i])*p[i]);
	}
	return b;
}
