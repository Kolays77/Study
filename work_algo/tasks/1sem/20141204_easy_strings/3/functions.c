#include <string.h>
#include <stdio.h>
#include "head.h"

char *strcat_(char *string1, const char *string2)
{
	int idx, length1;
	for (length1 = 0; string1[length1]; length1++)
	{
	}
	for (idx = 0; string2[idx]; idx++)
	{
		string1[length1 + idx] = string2[idx];
	}
	return string1;	
}
