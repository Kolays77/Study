#include <stdio.h>
#include "head.h"

int merge_union(double *a, double *b, int len_a, int len_b, double *result)
{
	int idx_a = 0, idx_b = 0, count_equal = 0;
	while (idx_a != len_a && idx_b != len_b)
	{
		if (a[idx_a] < b[idx_b])
		{
			result[idx_a + idx_b - count_equal] = a[idx_a];
			idx_a++;
			continue;
		}
		if (a[idx_a] > b[idx_b])
		{
			result[idx_a + idx_b - count_equal] = b[idx_b];
			idx_b++;
			continue;
		}
		result[idx_a + idx_b - count_equal] = b[idx_b];
		idx_b++;
		idx_a++;
		count_equal++;
	}
	for (; idx_a < len_a; idx_a++)
	{
		result[idx_a + idx_b - count_equal] = a[idx_a];
	}
	for (; idx_b < len_b; idx_b++)
	{
		result[idx_a + idx_b - count_equal] = b[idx_b];
	}
	return len_a + len_b - count_equal;
}
