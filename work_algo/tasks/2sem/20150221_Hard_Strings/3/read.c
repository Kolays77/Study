#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

#define MAX_PRINTABLE_NUMBER 15
#define MAX_LENGTH 10000

int make_string(char *str)
{
	int idx;
	for (idx = 0; str[idx]; idx++)
	{
		if (str[idx] == '\n')
		{
			str[idx] = 0;
			break;
		}
	}	
	return idx;
}

int solve(const char *input,
		  const char *output, 
		  char *str,
		  const char *sparse)
{
	FILE *fp1, *fp2;
	int len_buffer,
		counter = 0;
	char buffer[MAX_LENGTH],
	     *pointer;
	
	if (!(fp1 = fopen(input, "r")))
	{
		return -11;
	}
	if (!(fp2 = fopen(output, "w"))) 
	{
		return -12;
	}
	
	strcat(str, sparse);
	while (fgets(buffer, MAX_LENGTH, fp1))
	{
		len_buffer = make_string(buffer);
		if (strspn(buffer, str) == len_buffer)
		{
			fprintf(fp2, "%s\n", buffer);
			counter++;
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
