#include <string.h>
#include <stdio.h>
#include "head.h"

int strcspn_(const char *string1, const char *string2)
{
	int idx = 0, length2 = 0;
	while (string2[length2])
	{
		length2++;
	}
	for (idx = 0; string1[idx]; idx++)
	{
		if (binsearch(string2, length2, string1[idx]))
		{
			return idx;
		}
	}
	return idx;
}
