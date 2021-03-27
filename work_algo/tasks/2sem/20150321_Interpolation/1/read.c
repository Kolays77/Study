#include <stdio.h>
#include <stdlib.h>

#define MAX_PRINTABLE_NUMBER 5

int read(const char *name, double *x, double *y, int n)
{
	FILE *fp;
	int idx;
	
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	
	for (idx = 0; idx < n; idx++)
	{
		if (fscanf(fp, "%lf", x + idx) != 1)
		{
			if (!feof(fp))
			{
				fclose(fp);
				return -2;
			}
			fclose(fp);
			if (idx == 0)
			{
				return -3;
			}
			return -4;
		}
		if (fscanf(fp, "%lf", y + idx) != 1)
		{
			if (!feof(fp))
			{
				fclose(fp);
				return -2;
			}
			fclose(fp);
			if (idx == 0)
			{
				return -3;
			}
			return -4;
		}
	}
	fclose(fp);
	return 0;
}

void return_error(int result, const char *name)
{
	switch (result)
	{
		case (-1):
		{
			printf("Cannot open %s!\n", name);
			break;
		}
		case (-2):
		{
			printf("Cannot read %s!\n", name);
			break;
		}
		case (-3):
		{
			printf("%s is empty!\n", name);
			break;
		}
		case (-4):
		{
			printf("Not enough elements in %s!\n", name);
			break;
		}
		default:
		{
			printf("Unknown Error %d in %s!\n", result, name);
		}
	}
	return;
}

void print_function(double *x, double *y, int n)
{
	int idx,
	    left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
		right_board = ((n - left_board) > left_board ? n - left_board : left_board);
	printf("FUNCTION\n");
	for (idx = 1; idx < left_board; idx++)
	{
		printf("f(%.2f) = %.2f\n", x[idx], y[idx]);
	}
	if (2 * MAX_PRINTABLE_NUMBER < n)
	{
		printf(" ...\n");
	}
	for (idx = right_board; idx < n; idx++)
	{
		printf("f(%.2f) = %.2f\n", x[idx], y[idx]);
	}
	return;
}

