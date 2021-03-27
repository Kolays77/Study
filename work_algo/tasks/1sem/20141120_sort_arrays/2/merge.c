#include <stdio.h>
#include "head.h"

void merge(double *a, double *b, int len_a, int len_b, double *result)
{
	int idx_a = 0, idx_b = 0;
	while (idx_a != len_a && idx_b != len_b)
	{
		if (a[idx_a] < b[idx_b])
		{
			result[idx_a + idx_b] = a[idx_a];
			idx_a++;
		}
		else
		{
			result[idx_a + idx_b] = b[idx_b];
			idx_b++;
		}
	}
	for (; idx_a < len_a; idx_a++)
	{
		result[idx_a + idx_b] = a[idx_a];
	}
	for (; idx_b < len_b; idx_b++)
	{
		result[idx_a + idx_b] = b[idx_b];
	}
	return;
}
