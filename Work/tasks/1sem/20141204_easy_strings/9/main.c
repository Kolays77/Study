#include <stdio.h>
#include <string.h>
#include <time.h>
#include "head.h"

const int LENGTH = 1e5;
const int NUMBER = 1e5;

int main(void)
{
	char string1[LENGTH], string2[LENGTH], *pointer;
	double counter_of_time;
	int number, idx;
	
	printf("Input string1: ");
	if (!fgets(string1, LENGTH, stdin))
	{
		printf("Cannot read!\n");
		return -1;
	}
	for (idx = 0; string1[idx]; idx++)
	{
		if (string1[idx] == '\n')
		{
			string1[idx] = 0;
			break;
		}
	}
	
	printf("Input string2: ");
	if (!fgets(string2, LENGTH, stdin))
	{
		printf("Cannot read!\n");
		return -1;
	}
	for (idx = 0; string2[idx]; idx++)
	{
		if (string2[idx] == '\n')
		{
			string2[idx] = 0;
			break;
		}
	}
	
	counter_of_time = clock();
	for (number = 0; number < NUMBER; number++)
	{
		pointer = strstr(string1, string2);
	}
	printf("Standard function %s was called %d times\n", "strstr()", NUMBER);
	printf("Answer: %s\n", pointer);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("Elapsed  = %.6lf\n\n", counter_of_time);
	
	counter_of_time = clock();
	for (number = 0; number < NUMBER; number++)
	{
		pointer = strstr_(string1, string2);
	}
	printf("New function %s was called %d times\n", "strstr_()", NUMBER);
	printf("Answer: %s\n", pointer);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("Elapsed_ = %.6lf\n\n", counter_of_time);
	
	return 0;
}
