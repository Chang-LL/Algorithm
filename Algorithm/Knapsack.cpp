#include "stdafx.h"
#include "Knapsack.h"



template<typename T>
Knapsack<T>::Knapsack(int mSize, float cap, float * wei, T * prof)
{
	n = 0;
	m = 0.0f;
}

template<typename T>
Knapsack<T>::~Knapsack()
{
}


template<typename T>
T Knapsack<T>::DKnap(int* x)
{
	return T();
}

template<typename T>
T Knapsack<T>::DKnap()
{
	float ww, pp;
	int next; b[0] = 0;
	p[0].X = p[0].P = 0.0;
	p[1].X = w[0]; p[1].P = pf[0];
	int low = 0, high = 1;
	b[1] = next = 2;
	for (int i = 0; i <= n - 1; i++)
	{
		int k = low;
		int u = Largest(low, high, i);
		for (int j = low; j <= u; j++)
		{
			ww = p[j].X + w[i]; pp = p[j].P + pf[i];
			while (k <= high && p[k].X < ww)
			{
				p[next].X = p[k].X;
				p[next++].P = p[k++].P;
			}
		//TODO	if (k <= high && p[k].X == ww)if (pp < p[k].P) = p[k++].P;
			if (pp > p[next].P) {
				p[next].X = ww;
				p[next].P = pp;
			}
			while (k <= high && p[k].P <= p[next - 1].P)k++;
		}
		while (k <= high)
		{
			p[next].X = p[k].X;
			p[next++].P = p[k++].P;
		}
		low = high + 1; high = next - 1;
		b[i + 1] = next;
	}
	return p[next - 1].P;
}

template<typename T>
void Knapsack<T>::TraceBack(int* x)
{
	float ww = p[b[n] - 1].X;
	for (int j = n - 1; j > 0; j--)
	{
		x[j] = 1;
		for (int k = b[j - 1]; k < b[j]; k++)
			if (ww == p[k].X)x[j] = 0;
		if (x[j])ww = ww - w[j];
	}

	if (ww == 0)x[0] = 0;
	else x[0] = 1;
}

template<typename T>
int Knapsack<T>::Largest(int low, int high, int i)
{
	int u = low - 1;
	for (int j = low; j < =high; j++)
	{
		float ww = p[j].X + w[i];
		if (ww <= m)u = j;
	}
	return u;
}

template<typename T>
T Knapsack<T>::RKnap()
{
	if (n > 0)return f(n - 1, m);
	else return NoAns;

}

template<typename T>
T Knapsack<T>::f(int j, float X)
{
	if (j < 0)return((X < 0) ? -INFINITY : 0);
	if (X < w[j])return f(j - 1, X);
	else {
		T a = f(j - 1, X);
		T b = f(j - 1, X - w[j]) + p[j];
		return a > b ? a : b;
	}
}
