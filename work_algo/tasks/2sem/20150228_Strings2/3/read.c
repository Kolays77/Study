#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

#define MAX_PRINTABLE_NUMBER 15
#define MAX_LENGTH 10000

void make_string(char *str)
{
	int idx, len = strlen(str) - 1, max_idx = len / 2;
	char ch;
	
	str[len] = 0;
	for (idx = 0; idx <= max_idx; idx++)
	{
		ch = str[idx];
		str[idx] = str[len - idx - 1];
		str[len - idx - 1] = ch;
	}	
	return;
}

int solve(const char *input,
		  const char *output, 
		  char *str)
{
	FILE *fp1, *fp2;
	int idx = 0, id_ = 0,
		counter = 0;
		
	char buffer[MAX_LENGTH],
		 buffer2[MAX_LENGTH];
	
	if (!(fp1 = fopen(input, "r")))
	{
		return -11;
	}
	if (!(fp2 = fopen(output, "w"))) 
	{
		return -12;
	}
	
	make_string(str);
	while (fgets(buffer, MAX_LENGTH, fp1))
	{
		strcpy(buffer2, buffer);
		make_string(buffer);
		if (strstr(buffer, str) == buffer)
		{
			counter++;
			fprintf(fp2, "%s", buffer2);
		}
	}
	if (!feof(fp1))
	{
		fclose(fp1);
		fclose(fp2);
		return -2;
	}
	
	fclose(fp1);
	fclose(fp2);
	return counter;	
} 
