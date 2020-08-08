#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

#define MAX_PRINTABLE_NUMBER 15
#define MAX_LENGTH 10000

void make_string(char *str, char *sparse)
{
	int idx = 0, len = strlen(str) - 1;
	str[len] = 0;
	while (strchr(sparse, str[idx]))
	{
		idx++;
	}
	strcpy(str, str + idx);
	return;
}

int solve(const char *input,
		  const char *output, 
		  char *str,
		  char *sparse)
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
	
	make_string(str, sparse);
	while (fgets(buffer, MAX_LENGTH, fp1))
	{
		strcpy(buffer2, buffer);
		make_string(buffer, sparse);
		if (strstr(buffer, str))
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
