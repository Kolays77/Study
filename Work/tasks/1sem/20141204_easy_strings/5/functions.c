#include <string.h>
#include <stdio.h>
#include "head.h"

char *strchr_(const char *string, int ch)
{
	int idx;;
	for (idx = 0; string[idx]; idx++)
	{
		if (string[idx] == ch)
		{
			return (char *)string + idx;
		}
	}
	return 0;
}
