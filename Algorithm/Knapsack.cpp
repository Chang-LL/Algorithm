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
	return T();
}

template<typename T>
void Knapsack<T>::TraceBack(int* x)
{
}

template<typename T>
int Knapsack<T>::Largest(int low, int high, int i)
{
	return 0;
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
