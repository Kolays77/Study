#include <string.h>
#include <stdio.h>
#include "head.h"

char *strstr_(const char *string1, const char *string2)
{
	int cur_length = 0, idx1 = 0;
	int length2 = 0;
	while (string2[length2++])
	{
	}
	length2--;
	while (string1[idx1])
	{
		if (string1[idx1] == string2[cur_length])
		{
			cur_length++;
			if (cur_length != length2)
			{
				idx1++;
				continue;
			}
			return (char *) string1 + idx1 - length2 + 1; 
		}
		else
		{
			cur_length = find_shift(string2, cur_length, string1[idx1]);
		}
		idx1++;
	}
	return 0;
}

int find_shift(const char *string, int cur_length, char elem)
{
	int shift, idx = 0, was_change = 0;
	for (shift = 1; shift <= cur_length; shift++)
	{	
		for (idx = 0; shift + idx < cur_length; idx++)
		{
			if (string[idx] != string[idx + shift])
			{
				break;
			}
		}
		if (idx + shift == cur_length && string[idx] == elem)
		{
			was_change = 1;
			cur_length -= (shift - 1);
			break;
		} 
	}
	if (!was_change)
	{
		return 0;
	}
	return cur_length;
}
