#include <string.h>
#include <stdio.h>
#include "head.h"

const int N = 256;

int strlen_(const char *string)
{
	int idx;
	for (idx = 0; string[idx]; idx++)
	{
	}
	return idx;
}

int strcspn_(const char *string1, const char *string2)
{
	int idx = 0;
	unsigned int *was_char;
	
	if (!(was_char = (unsigned int *) malloc(N * sizeof(unsigned int))))
	{
		printf("Not enough memory!\n");
		return 0;
	}

	for (idx = 0; string2[idx]; idx++)
	{
		was_char[(int)string2[idx]] = 1;
	}
	
	for (idx = 0; string1[idx]; idx++)
	{
		if (!was_char[(int)string1[idx]])
		{
			return idx;
		}
	}
	return idx;
}
