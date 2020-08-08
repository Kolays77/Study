#include <stdio.h>
#include <string.h>
#include <time.h>
#include "head.h"

const int LENGTH = 1e5;
const int NUMBER = 1e3;

int main(void)
{
	char string[LENGTH], chr, *pointer;
	double counter_of_time;
	int number, idx;

	printf("Input string: ");
	if (!fgets(string, LENGTH, stdin))
	{
		printf("Cannot read!\n");
		return -1;
	}
	for (idx = 0; string[idx]; idx++)
	{
		if (string[idx] == '\n')
		{
			string[idx] = 0;
			break;
		}
	}
	
	printf("Input char: ");
	if (!scanf("%c", &chr))
	{
		printf("Input Error!\n");
		return -1;
	}
	
	counter_of_time = clock();
	for (number = 0; number < NUMBER; number++)
	{
		pointer = strrchr(string, chr);
	}
	printf("Standard function %s was called %d times\n", "strrchr()", NUMBER);
	printf("Answer: %s\n", pointer);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("Elapsed  = %.6lf\n\n", counter_of_time);
	
	counter_of_time = clock();
	for (number = 0; number < NUMBER; number++)
	{
		pointer = strrchr_(string, chr);
	}
	printf("New function %s was called %d times\n", "strrchr_()", NUMBER);
	printf("Answer: %s\n", pointer);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	printf("Elapsed_ = %.6lf\n\n", counter_of_time);

	return 0;
}
