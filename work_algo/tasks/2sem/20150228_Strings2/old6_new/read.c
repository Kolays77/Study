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

int make_examplar(char *str, char *flag)
{
	int idx,
	    difference = 0,
	    cur_len = 0;
	for (idx = 0;; idx++)
	{
		if (str[idx + difference] == '\\')
		{
			if (str[idx + difference + 1] == '.' || 
			    str[idx + difference + 1] == '\\')
			{
				difference++;
			}
			else
			{
				return -4;
			}
			str[idx] = str[idx + difference];
			flag[idx] = 0;
			continue;
		}
		if (str[idx + difference] == '.')
		{
			str[idx] = 1;
			flag[idx] = 1;
			continue;
		}
		str[idx] = str[idx + difference];
		if (str[idx + difference] == '\n' ||
			str[idx + difference] == 0)
		{
			str[idx] = 0;
			break;
		}
	}
	return idx;
}

int compare(char *str1, char *str2, char *flag)
{
	int idx;
	if (strlen(str1) != strlen(str2))
	{
		return 0;
	}
	for (idx = 0; str1[idx]; idx++)
	{
		if (!flag[idx] && str1[idx] != str2[idx])
		{
			return 0;
		}
	}
	return 1;
}

int solve(const char *input,
		  const char *output, 
		  char *examplar)
{
	FILE *fp1, *fp2;
	int idx = 0, id_ = 0,
		counter = 0,
		len_ex = strlen(examplar);
		
	char buffer[MAX_LENGTH],
		 flag[len_ex];
	
	if (!(fp1 = fopen(input, "r")))
	{
		return -11;
	}
	if (!(fp2 = fopen(output, "w"))) 
	{
		return -12;
	}
	make_examplar(examplar, flag);
	while (fgets(buffer, MAX_LENGTH, fp1))
	{
		make_string(buffer);
		if (compare(buffer, examplar, flag))
		{
			counter++;
			fprintf(fp2, "%s\n", buffer);
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
