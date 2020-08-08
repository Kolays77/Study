#include <string.h>
#include <stdio.h>
#include "head.h"

char *strcpy_(char *string1, const char *string2)
{
	int idx = 0;
	for (idx = 0; string2[idx]; idx++)
	{
		string1[idx] = string2[idx];
	}
	return string1;	
}
