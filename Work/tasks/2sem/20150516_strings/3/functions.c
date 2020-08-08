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

int delete_spaces(char **current_char, char *sign, char *found, FILE *fp2)
{
	int finish_idx = found - *current_char;
	if ((*current_char)[finish_idx - 1] != ' ')
	{
		(*current_char)[finish_idx] = 0;
		fprintf(fp2, "%s %s ", *current_char, sign);
		(*current_char)[finish_idx] = '+';
		*current_char = *current_char + finish_idx + strlen(sign);
	}
	else
	{
		int finish_space_idx = finish_idx - 1;
		while (finish_space_idx != 0 && (*current_char)[finish_space_idx - 1] == ' ')
		{
			finish_space_idx--;
		}
		(*current_char)[finish_space_idx] = 0;
		fprintf(fp2, "%s %s ", *current_char, sign);
		(*current_char)[finish_space_idx] = ' ';
		*current_char = *current_char + finish_idx + strlen(sign);
	}
	while ((*current_char)[0] == ' ')
	{
		(*current_char)++;
	}	
}

int solve(const char *input,
		  const char *output)
{
	FILE *fp1, *fp2;
	int counter = 0;
	char buffer[MAX_LENGTH];
	int exit = 0;
	int idx, i;
	char *plus, *minus, *multiplication_sign, *division_sign, *comment1, *comment2, *current_char;
	int current_idx, open = 0;
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
			plus = strstr(current_char, "+");
			minus = strstr(current_char, "-");
			multiplication_sign = strstr(current_char, "*");
			division_sign = strstr(current_char, "/");
			comment1 = strstr(current_char, "/*");
			comment2 = strstr(current_char, "*/");
			if (plus == 0 && minus == 0 && multiplication_sign == 0 && division_sign == 0)
			{
				fprintf(fp2, "%s\n", current_char);
				exit = 1;
				continue;
			}
			if (comment1 != 0 && (comment2 == 0 || comment1 < comment2)
			    && (plus == 0|| comment1 < plus) && (minus == 0 || comment1 < minus) 
				&& (comment1 < multiplication_sign) && (comment1 <= division_sign))
			{
				/*current_idx = comment1 - current_char;
				current_char[current_idx] = 0;
				fprintf(fp2, "%s/*", current_char);
				current_char[current_idx] = '/';
				current_char = comment1 + 2;*/
				
				delete_spaces(&current_char, "/*", comment1, fp2);
				counter++;
				continue;
			}
			if (comment2 != 0 && (comment1 == 0 || comment2 < comment1)
			    && (plus == 0|| comment2 < plus) && (minus == 0 || comment2 < minus) 
				&& (comment2 <= multiplication_sign) && (comment2 < division_sign))
			{
				/*current_idx = comment2 - current_char;
				current_char[current_idx] = 0;
				fprintf(fp2, "%s*//*", current_char);
				current_char[current_idx] = '*';
				current_char = comment2 + 2;*/
				delete_spaces(&current_char, "*/", comment2, fp2);
				counter++;
				continue;
			}
			
			if (plus != 0 && (minus == 0 || plus < minus) 
				&& (multiplication_sign == 0 || plus < multiplication_sign)
				&& (division_sign == 0 || plus < division_sign))
			{
				delete_spaces(&current_char, "+", plus, fp2);
				counter++;
				continue;
			}
			if (minus != 0 && (plus == 0 || minus < plus) 
				&& (multiplication_sign == 0 || minus < multiplication_sign)
				&& (division_sign == 0 || minus < division_sign))
			{
				delete_spaces(&current_char, "-", minus, fp2);
				counter++;
				continue;
			}
			if (multiplication_sign != 0 && (plus == 0 || multiplication_sign < plus) 
				&& (minus == 0 || multiplication_sign < minus)
				&& (division_sign == 0 || multiplication_sign < division_sign))
			{
				delete_spaces(&current_char, "*", multiplication_sign, fp2);
				counter++;
				continue;
			}
			if (division_sign != 0 && (plus == 0 || division_sign < plus) 
				&& (multiplication_sign == 0 || division_sign < multiplication_sign)
				&& (minus == 0 || division_sign < minus))
			{
				delete_spaces(&current_char, "/", division_sign, fp2);
				counter++;
				continue;
			}
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
