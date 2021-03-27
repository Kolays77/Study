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

int make_examplar(char *str,
                  char *first,
                  char *last)
{
	int idx,
		id_ = 0,
	    difference = 0,
	    cur_len = 0;
	for (idx = 0;; idx++)
	{
		if (str[idx + difference] == '\\')
		{
			if (str[idx + difference + 1] == '[' || 
			    str[idx + difference + 1] == ']' ||
			    str[idx + difference + 1] == '\\')
			{
				difference++;
			}
			else
			{
				return -4;
			}
			str[idx] = str[idx + difference];
			first[idx] = last[idx] = 1;
			continue;
		}
		if (str[idx + difference] == '[')
		{
			str[idx] = 1;
			first[idx] = str[idx + difference + 1];
			last[idx] = str[idx + difference + 3];
			if (str[idx + difference + 2] != '-' || str[idx + difference + 4] != ']')
			{
				return -4;
			}
			difference += 4;
			continue;
		}
		str[idx] = str[idx + difference];
		first[idx] = last[idx] = 1;
		if (str[idx + difference] == '\n' ||
			str[idx + difference] == 0)
		{
			str[idx] = first[idx] = last[idx] = 0;
			break;
		}
	}
	return id_;
}

int compare(char *str,
			char *examplar,
			char *first,
			char *last)
{
	int idx = 0,
	    len_new = strlen(str),
	    len_examplar = strlen(examplar);
	    
	if (len_new != strlen(first) || len_new != strlen(last))
	{
		return 0;
	}
	for (idx = 0; str[idx]; idx++)
	{
		if (first[idx] == 1 && str[idx] != examplar[idx])
		{
			return 0;
		}
		if (examplar[idx] == 1 && (str[idx] < first[idx] || str[idx] > last[idx]))
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
		counter = 0;
		
	char buffer[MAX_LENGTH],
	     first[MAX_LENGTH],
	     last[MAX_LENGTH];
	
	if (!(fp1 = fopen(input, "r")))
	{
		return -11;
	}
	if (!(fp2 = fopen(output, "w"))) 
	{
		return -12;
	}
	make_examplar(examplar, first, last);
	
	while (fgets(buffer, MAX_LENGTH, fp1))
	{
		make_string(buffer);
		if (compare(buffer, examplar, first, last))
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
