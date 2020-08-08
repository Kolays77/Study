#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

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
		  const char *output)
{
	FILE *fp1, *fp2;
	int idx = 0, id_ = 0,
		counter = 0;
	char buffer[MAX_LENGTH];
	int exit = 0;
	char *current_open, *current_close, *current_char;
	int current_idx, stack = 0;
	if (!(fp1 = fopen(input, "r")))
	{
		return -11;
	}
	if (!(fp2 = fopen(output, "w"))) 
	{
		return -12;
	}
	while (fgets(buffer, MAX_LENGTH, fp1))
	{
		make_string(buffer);
		current_char = buffer;
		exit = 0;
		while (!exit)
		{
			current_idx = 0;
			current_open = strstr(current_char, "/*");
			current_close = strstr(current_char, "*/");
			if (!(current_open || current_close) )
			{
				if (stack == 0)
				{
					fprintf(fp2, "%s", current_char);
				}
				exit = 1;
				fprintf(fp2, "\n");
				continue;
			}
			if ((current_open < current_close || (current_close) == 0) && (current_open) != 0)
			{
				stack++;
				counter++;
				current_idx = current_open - current_char;
				if (stack == 1)
				{
					strcpy(buffer, current_char);
					buffer[current_idx] = 0;
					fprintf(fp2, "%s", buffer);
				}
				current_char = current_open + 2;
			}
			else
			{
				stack--;
				current_char = current_close + 2;
			}
		}
	}
	if (!feof(fp1))
	{
		fclose(fp1);
		fclose(fp2);
		return -2;
	}
	if (stack > 0)
	{
		return -3;
	}
	fclose(fp1);
	fclose(fp2);
	return counter;	
} 
