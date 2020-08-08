#include <string.h>
#include <stdio.h>
#include "head.h"

int strcmp_(const char *string1, const char *string2)
{
	int idx = 0;
	while (string1[idx] && string2[idx])
	{
		if (string1[idx] < string2[idx])
		{
			return -1;
		}
		if (string1[idx] > string2[idx])
		{
			return 1;
		}
		idx++;
	}
	if (string2[idx])
	{
		return -1;
	}
	return (int)string1[idx];	
}
