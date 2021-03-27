#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "student.h"

#define MAX_LENGTH 25
#define MIN_LENGTH 5
#define MAX_VALUE 1000

int generate (student *array, int n)
{
	int idx, idx_string, current_length, current_value = 0;
	char current_char, current_name[MAX_LENGTH];

	srand (time (NULL));

	for (idx = 0; idx < n; idx++)
	  {
		current_length = rand () % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
		for (idx_string = 0; idx_string < current_length; idx_string++)
		  {
			current_char = rand () % ('z' - 'a' + 1) + 'a';
			current_name[idx_string] = current_char;
		  }
		current_name[idx_string] = 0;
		current_value = rand () % (MAX_VALUE + 1);
		array[idx].init (current_name, current_value);
	  }
	return n;
}
