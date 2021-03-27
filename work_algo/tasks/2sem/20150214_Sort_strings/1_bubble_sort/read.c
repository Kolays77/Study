#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

const int MAX_PRINTABLE_NUMBER = 15;
const int MAX_LENGTH = 1e5;

int read_array(const char *name, char **array, int n)
{
	FILE *fp;
	int idx, id_;
	char buffer[MAX_LENGTH];
	
	if (!(fp = fopen(name, "r")))
	{
		return -1;
	}
	
	for (idx = 0; idx < n; idx++)
	{
		if (!fgets(buffer, MAX_LENGTH, fp))
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
			printf("The number of strings in %s is less than n\nNumber of strings is %d\n", name, idx);
			return idx;
		}
		for (id_ = 0; buffer[id_]; id_++)
		{
			if (buffer[id_] == '\n')
			{
				buffer[id_] = 0;
				break;
			}
		}
		if (!(array[idx] = (char *) malloc((id_ + 1) * sizeof(char))))
		{
			printf("Not enough memory!\n");
			return -4;
		}
		strcpy(array[idx], buffer);
	}
	fclose(fp);
	return idx;	
} 

void print_array(char **array, int n)
{
	int idx,
	    left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
		right_board = ((n - left_board) > left_board ? n - left_board : left_board);
	printf("ARRAY:\n");
	for (idx = 0; idx < left_board; idx++)
	{
		printf("string %2d: %s\n", idx, array[idx]);
	}
	if (2 * MAX_PRINTABLE_NUMBER < n)
	{
		printf("...\n");
	}
	for (idx = right_board; idx < n; idx++)
	{
		printf("string %2d: %s\n", idx, array[idx]);
	}
	printf("\n");
	return;
}
