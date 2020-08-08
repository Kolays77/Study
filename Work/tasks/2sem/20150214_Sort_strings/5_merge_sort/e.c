#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_PRINTABLE_NUMBER 100
void print_array(int *array, int n)
{
	int idx,
	    left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
		right_board = ((n - left_board) > left_board ? n - left_board : left_board);
	printf("ARRAY:\n");
	for (idx = 0; idx < left_board; idx++)
	{
		printf("string %2d: %d\n", idx, array[idx]);
	}
	if (2 * MAX_PRINTABLE_NUMBER < n)
	{
		printf("...\n");
	}
	for (idx = right_board; idx < n; idx++)
	{
		printf("string %2d: %d\n", idx, array[idx]);
	}
	printf("\n");
	return;
}
void copy(int a, int b)
{
	*a = *b;
	return;
}
int main(void)
{
	int *a, *b, *tmp;
	if (!(a = (int *) malloc(20 * sizeof(int))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	if (!(b = (int *) malloc(20 * sizeof(int))))
	{
		printf("Not enough memory!\n");
		return 2;
	}
	*a = 0; *(a+1) = 1; *(a+2) = 2; *(a+3) = 3; *(a+4) = 4; *(a+5) = 5;
	*b = 10; *(b+1) = 9; *(b+2) = 8; *(b+9) = 123; *(a+9) = 321;
	tmp =(a+2);
	a=b;
	cop(b+2, tmp);
	print_array(a, 10);
	print_array(b, 10);
	return 0;
}
