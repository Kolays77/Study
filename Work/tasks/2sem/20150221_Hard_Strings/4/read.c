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

int delete_sparse(char *buffer, const char *sparse)
{
	int id_, 
	    idx,
	    len_buffer = strlen(buffer),
	    difference = 0;
	
	while ((id_ = strcspn(buffer, sparse)) != len_buffer)
	{
		buffer[id_] = -1;
	}
		
	for (id_ = 0; id_ < len_buffer - difference; id_++)
	{
		idx = id_;
		while (buffer[idx + difference] == -1)
		{
			difference++;
		}
		buffer[id_] = buffer[id_ + difference];
		if (buffer[id_] == '\n')
		{
			buffer[id_] = 0;
		}
	}
	buffer[id_] = 0;
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
		 buffer2[MAX_LENGTH];
	
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
		strcpy(buffer2, buffer);
		delete_sparse(buffer, sparse);
		if (strstr(buffer2, str))
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
