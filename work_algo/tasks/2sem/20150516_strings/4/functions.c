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
	char *open, *close, *current_char;
	int current_idx, bracket_idx = 0, space_idx;
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
			open = strstr(current_char, "(");
			close = strstr(current_char, ")");
			/*printf("%s\n", current_char);
			if (scanf("%d", &i) != 1)
			{
				return 0;
			}
			printf("%s\n%s\n", open, close);*/
			if (open == 0 && close == 0)
			{
				fprintf(fp2, "%s\n", current_char);
				exit = 1;
				continue;
			}
			if (close == 0 || (open != 0) && open < close)
			{
				current_idx = open - current_char;
				if (current_idx == 0)
				{
					counter++;
					fprintf(fp2, "(");
					current_char++;
				}
				else
				{
					space_idx = current_idx - 1;
					if (current_char[space_idx] != ' ')
					{
						current_char[current_idx] = 0;
						fprintf(fp2, "%s (", current_char);
						current_char[current_idx] = '(';
						counter++;
						current_char = current_char + current_idx + 1;
					}
					else
					{
						while (space_idx >= 0 && current_char[space_idx]  == ' ')
						{
							space_idx--;
						}
						current_char[space_idx + 1] = 0;
						counter++;
						fprintf(fp2, "%s (", current_char);
						current_char[space_idx + 1] = ' ';
						current_char = current_char + current_idx + 1;
					}
				}
				bracket_idx = 0;
				while (current_char[bracket_idx] == '(' || current_char[bracket_idx] == ' ')
				{
					while (current_char[bracket_idx] == '(')
					{
						counter++;
						fprintf(fp2, "%c", '(');
						bracket_idx++;
					}
					while (current_char[bracket_idx] == ' ')
					{
						bracket_idx++;
					}
				}
				current_char += bracket_idx;
			}
			else
			{
				int length = strlen(current_char);
				bracket_idx = close - current_char;
				current_char[bracket_idx] = 0;
				fprintf(fp2, "%s", current_char);
				current_char[bracket_idx] = ')';
				while (bracket_idx < length && current_char[bracket_idx] == ')')
				{
					while (current_char[bracket_idx] == ')')
					{
						counter++;
						fprintf(fp2, "%c", ')');
						bracket_idx++;
					}
					while (current_char[bracket_idx] == ' ')
					{
						bracket_idx++;
					}
				}
				current_char += bracket_idx;
				if (bracket_idx == length)
				{
					fprintf(fp2,"\n");
				}
				else
				{
					fprintf(fp2, " ");
				}
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
