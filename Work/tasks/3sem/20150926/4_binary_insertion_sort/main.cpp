#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "read.h"
#include "sort.h"
#include "generate.h"

int main (int argc, char **argv)
{
	const char *file_name = "a.txt";
	int n, result;
	double counter_of_time;
	student *array;
	
	if (argc != 3 && argc != 2)
	  {
		fprintf (stdout, "Usage: %s [n] [<file>]\n", argv[0]);
		return 1;
	  }
	if ((n = atoi (argv[1])) <= 0)
	  {
		fprintf (stdout, "Cannot read [n]!\n");
		return 1;
	  }

	array = new student[n];
	
	if (argc == 3)
	  {
		file_name = argv[2];  
		result = read_array (file_name, array, n);
		if (result < 0)
		  {
			switch (result)
			  {
				case (-1):
					fprintf (stdout, "Cannot open %s\n", file_name);
					break;
				case (-2):
					fprintf (stdout, "Cannot read %s\n", file_name);
					break;
				case (-3):
					fprintf (stdout, "%s is empty\n", file_name);
					break;
				default:
					fprintf (stdout, "Unknown error %d in %s\n", result, file_name);
			  }
			delete [] array;
			return -1;
		  }
	  }
	else
	  {
		result = generate (array, n);
		if (result < 0)
		  {
			switch (result)
			  {
				case (1):
					fprintf (stdout, "Cannot open %s\n", file_name);
				default:
					fprintf (stdout, "Unknown error %d in generating array\n", result);
			  }
			delete [] array;
			return -2;    
		  }
	  }
	n = result;
	print_array (array, n);
	counter_of_time = clock();
	binary_insertion_sort (array, n);
	counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
	print_array (array, n);
	
	printf("Elapsed = %.3f\n", counter_of_time);
	delete [] array;
	return 0;
}
