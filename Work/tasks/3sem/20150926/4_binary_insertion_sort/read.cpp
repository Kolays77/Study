#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "student.h"

#define MAX_PRINTABLE_NUMBER 15
#define MAX_LENGTH 25

int read_array (const char *filename, student *array, int n)
{
	FILE *file_input;
	int idx;
	char name[MAX_LENGTH];
	int value;
	
	if (!(file_input = fopen (filename, "r")))
	  {
		return -1;
	  }
	
	for (idx = 0; idx < n; idx++)
	  {
		if (fscanf (file_input, "%s%d", name, &value) != 2)
		  {
			if (!feof (file_input))
			  {
				fclose (file_input);
				return -2;
			  }
			fclose (file_input);
			if (idx == 0)
			  {
				return -3;
			  }
			printf ("The number of students in %s is less than n\nNumber of students is %d\n", name, idx);
			return idx;
		  }
		array[idx].init (name, value);
	  }
	fclose (file_input);
	return idx;	
} 

void print_array (student *array, int n)
{
	int idx,
	    left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n),
		right_board = ((n - left_board) > left_board ? n - left_board : left_board);
	printf ("ARRAY OF STUDENTS:\n");
	for (idx = 0; idx < left_board; idx++)
	  {
		printf (" %2d: %s %d\n", idx, array[idx].get_name(), array[idx].get_value());
	  }
	if (2 * MAX_PRINTABLE_NUMBER < n)
	  {
		printf ("...............\n");
	  }
	for (idx = right_board; idx < n; idx++)
	  {
		printf (" %2d: %s %d\n", idx, array[idx].get_name(), array[idx].get_value());
	  }
	printf ("\n");
	return;
}
