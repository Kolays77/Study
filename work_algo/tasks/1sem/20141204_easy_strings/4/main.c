#include <stdio.h>
#include <string.h>
#include <time.h>
#include "head.h"

const int LENGTH = 1e5;
const int NUMBER = 1e3;

int main(void)
{
	char string1[LENGTH], string2[LENGTH];
	double counter_of_time;
	int number, idx, answer;

	printf("Input the 1st string: ");
	if (!fgets(string1, LENGTH, stdin))
	{
		printf("Cannot read the 1st string!\n");
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
	
	printf("Input the 2nd string: ");
	if (!fgets(string2, LENGTH, stdin))
	{
		printf("Cannot read the 2nd string!\n");
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
		answer = strcmp(string1, string2);
	}
	printf("Standard function %s was called %d times\n", "strcmp()", NUMBER);
	printf("Answer: %d\n", answer);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("Elapsed  = %.6lf\n\n", counter_of_time);
	
	counter_of_time = clock();
	for (number = 0; number < NUMBER; number++)
	{
		answer = strcmp_(string1, string2);
	}
	printf("New function %s was called %d times\n", "strcmp_()", NUMBER);
	printf("Answer: %d\n", answer);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("Elapsed_ = %.6lf\n\n", counter_of_time);
	return 0;
}
