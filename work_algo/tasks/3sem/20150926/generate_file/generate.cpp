#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 25
#define MIN_LENGTH 5
#define MAX_VALUE 1000

int main (int argc, char *argv[])
{
	int n, idx, idx_string, current_length;
	const char *file_name = "a.txt";
	FILE *file_output;
	srand (time (NULL));
	
	if (argc != 2)
	  {
		fprintf (stdout, "Usage: %s [n]\n", argv[0]);
		return 1;
	  }
	if (sscanf (argv[1], "%d", &n) != 1)
	  {
		fprintf (stdout, "Cannot read [n]!\n");
		return 2;
	  }
	if (!(file_output = fopen (file_name, "w")))
	  {
		fprintf (stdout, "Cannot open file!\n");
		return 3;
	  }
	
	for (idx = 0; idx < n; idx++)
	  {
		current_length = rand () % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
		for (idx_string = 0; idx_string < current_length; idx_string++)
		  {
			fprintf (file_output, "%c", rand () % ('z' - 'a' + 1) + 'a');
		  }
		fprintf (file_output, " ");
		fprintf (file_output, "%d\n", rand () % (MAX_VALUE + 1));
	  }
	fclose (file_output);
	return 0;
}
