#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

#define MAX_PRINTABLE_NUMBER 15
#define MAX_LENGTH 10000

int make_string(char *buffer)
{
	int id_;
	for (id_ = 0; buffer[id_]; id_++)
	{
		if (buffer[id_] == '\n')
		{
			buffer[id_] = 0;
			break;
		}
	}
	return id_;
}

int solve(const char *input,
		  const char *output, 
		  const char *substr,
		  const char *new_substr)
{
	FILE *fp1, *fp2;
	int id_ = 0, 
		was_changed = 0, 
		len_buffer = 0,
		len_substr = strlen(substr),
		len_new_substr = strlen(new_substr),
		number = 0,
		difference = len_new_substr - len_substr,
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
	while (fgets(buffer, MAX_LENGTH, fp1))
	{
		number = 0;
		make_string(buffer);
		pointer = strstr(buffer, substr);
		
		while (pointer)
		{
			number++;
			len_buffer = strlen(buffer);
			was_changed = 1;
			for (id_ = len_buffer + difference; id_ >= pointer + len_new_substr - buffer; id_--)
			{
				buffer[id_] = buffer[id_ - difference];
			}
			strncpy(pointer, new_substr, len_new_substr);
			if (len_new_substr + strlen(substr) <= strlen(pointer))
			{
				pointer = strstr(pointer + len_new_substr, substr);
				
			}
			else
			{
				pointer = 0;
			}
		}
		if (was_changed)
		{
			counter++;
			was_changed = 0;
	 	}
	 	fprintf(fp2, "%s\n", buffer);
	 	strcpy(buffer, "");
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
