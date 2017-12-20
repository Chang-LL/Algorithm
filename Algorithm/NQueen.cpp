#include "stdafx.h"
#include "NQueen.h"

bool Place(int k, int i, int * x)
{
	for (int j = 0; j < k; j++)
	{
		if ((x[j] == i) || abs(x[j] - i) == abs(j - k))
			return false;
	}
	return true;
}

void NQueens(int k, int n, int * x)
{
	for (int i = 0; i < n; i++)
	{
		if (Place(k, i, x))
		{
			x[k] = i;
			if (k == n - 1)
			{
				for (int i = 0; i < n; i++)
				{
					std::cout << x[i] << " ";
				}			
				std::cout << std::endl;
			}
			else NQueens(k + 1, n, x);//深度优先下一层
		}
	}
}

void NQueens(int n, int * x)
{
	NQueens(0, n, x);
}
