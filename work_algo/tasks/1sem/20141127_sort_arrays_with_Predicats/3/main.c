#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

int main(void)
{
	const char *name1 = "a.txt", *name2 = "b.txt";
	int len_a = 0, len_b = 0, result;
	double counter_of_time;
	double *a, *b, *c;
	int (*ptr) (double, double);
	
	ptr = &comparator;
	
	printf("Input n: ");
	if (scanf("%d", &len_a) != 1)
	{
		printf("Input Error\n");
		return -1;
	}
	if (len_a <= 0)
	{
		printf("n must be more than 0!\n");
		return 1;
	}
	if (!(a = (double *) malloc(len_a * sizeof(double))))
	{
		printf("Not enough memory\n");
		return -4;
	} 
	result = read_array(name1, a, len_a);
	if (result < 0)
	{
		return_error(name1, result);
		free(a);
		return -1;
	}
	len_a = result;
	if (!check_array(a, len_a, ptr))
	{
		free(a);
		printf("This is not suitable with this problem in %s!\n", name1);
		return -5;
	}
	
	printf("Input m: ");
	if (scanf("%d", &len_b) != 1)
	{
		printf("Input Error\n");
		free(a);
		return -1;
	}
	if (len_b <= 0)
	{
		printf("m must be more than 0!\n");
		free(a);
		return 1;
	}
	if (!(b = (double *) malloc(len_b * sizeof(double))))
	{
		printf("Not enough memory\n");
		free(a);
		return -4;
	} 
	result = read_array(name2, b, len_b);
	if (result < 0)
	{
		return_error(name2, result);
		free(a); free(b);
		return -1;
	}
	len_b = result;
	if (!check_array(b, len_b, ptr))
	{
		free(a); free(b);
		printf("This is not suitable with this problem in %s!\n", name1);
		return -5;
	}
	
	print_array(a, len_a);
	print_array(b, len_b);
	if (!(c = (double *) malloc((len_a + len_b) * sizeof(double))))
	{
		printf("Not enough memory for new array!\n");
		free(a); free(b);
		return -5;
	}
	counter_of_time = clock();
	result = merge_union(a, b, len_a, len_b, c, ptr);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	print_array(c, result);
	printf("Elapsed = %.2lf\n", counter_of_time);
	free(a); free(b); free(c);
	return 0;
}
