#include "stdafx.h"
#include "Knapspack.h"

template<typename T>
Knapspack<T>::Knapspack(int mSize, float cap, float* wei, T* prof)
{
	m = 0.0f;
	n = 0;
}

template<typename T>
Knapspack<T>::~Knapspack()
{
}

// //����xΪ������������Ž�
template<typename T>
void Knapspack<T>::GreedyKnapsack(float* x)
{//w[i]����p[i]/w[i]������������
	float u = m;// ����ʣ��������
	for (int i = 0; i < n; i++)
	{
		x[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (w[i] > u)
			break;
		x[i] = 1.0;
		u -= w[i];
	}
	if (i < n)
	{
		x[i] = u / w[i];
	}
}

//template<typename T>
//void Knapspack<T>::GreedyJob(int d[], Set x, int n)
//{//p0>=p1>=p2...pn-1
//	X = { 0 };
//	for (int i = 0; i < n; i++)
//	{
////		if (/*set X U{i}�����ڸ�����ʱ�������*/)
////			X = XU{ i };
//	}
//}

template<typename T>
int Knapspack<T>::JS(int * d, int * x, int n)
{//p0>=p1...����
	//x ������ d  ʱ��
	int k = 0;
	x[0] = 0;
	for (int j = 1; j < n; j++)
	{
		int r = k;//j����λ��
		while (r >= 0
			&& d[x[r]] > d[j] && d[x[r]] > r + 1)
			r--;
		if ((r < 0 || d[x[r]] <= d[j]) && d[x[r]] > r + 1)
		{
			for (int i = k; i >= r + 1; i--)
			{
				x[i + 1] = x[i];
			}
			x[r + 1] = j;//j����r+1��
			k++;
		}
	}
	return 0;
}

template<typename T>
int Knapspack<T>::FJS(int * d, int * x, int n)
{
	T s(n);//n�����Ĳ��鼯
	int b, k = -1, *f = new int[n + 1];
	for (int i = 0; i < = n; i++)
	{
		f[i] = i;//��ҵiʱ��Ƭi-1��i
	}
	for (int i = 0; i < n; i++)
	{
		if (n < d[i])b = n;
		else b = d[i];
		int r = s.find(b);
		if (f[r]) {
			x[++k] = i;
			int t = s.find(f[r] - 1);//Ѱ��ʱ��Ϊ ������t
			s.Union(t, r);
			f[r] = f[t];
		}
	}
	delete[]f;
	return k;
}

template<typename T>
BTNode<T>* Knapspack<T>::CreateHfmTree(T * w, int n)
{//wΪһά���鱣��Ȩֵ
	std::priority_queue<HNode<T>>pq(2 * n - 1);
	BTNode<T>*p; HNode<T>a, b;
	for (int i = 0; i < n; i++)
	{
		p = new BTNode<T>(w[i]);
		a.ptr = p; a.weight = w[i];//ȨֵΪ��
		pq.pop(a);//n��ֻ�и��Ķ�����������
	}
	for (int i = 0; i < n; i++)//�����ϲ�n-1�Σ�n����-1����
	{
		pq.pop(a); pq.pop(b);//Ȩֵ��С��������
		a.weight += b.weight;
		p = new BTNode<T>(a.weight, a.ptr, b.ptr);
		a.ptr = p;
		pq.pop(a);//��������
	}
	pq.push(a);//ȡ������
	return a.ptr;
}
//���򰴷Ǽ���������
template<typename T>
void Knapspack<T>::Store(int n, int m)
{
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		std::cout << "������" << i
			<< " �ӵ��Ŵ�" << j << std::endl;
		j = (j + 1) % m;
	}
	std::cout << std::endl;
}
