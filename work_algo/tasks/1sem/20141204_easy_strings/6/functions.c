#include <string.h>
#include <stdio.h>
#include "head.h"

char *strrchr_(const char *string, int ch)
{
	int idx;
	char *pointer = 0;
	for (idx = 0; string[idx]; idx++)
	{
		if (string[idx] == ch)
		{
			pointer = (char *)string + idx;
		}
	}
	return 0;
}
