#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "student.h"
#include "stack.h"
#include "queue.h"

#define MAX_LENGTH 10
#define MIN_LENGTH 5
#define MAX_VALUE 100


int generate_file (const char *filename, int n)
{
  FILE *fp;
  char name[MAX_LENGTH];
  int value, current_char, current_length, idx_string;

  if (!(fp = fopen (filename, "w")))
    {
      return -1;
    }
  srand (time (NULL));
  for (int i = 0; i < n; i++)
    {
      current_length = rand () % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
      for (idx_string = 0; idx_string < current_length; idx_string++)
        {
          current_char = rand () % ('z' - 'a' + 1) + 'a';
          name[idx_string] = current_char;
        }
      name[idx_string] = 0;
      value = rand () % (MAX_VALUE);
      fprintf (fp, "%s %d\n", name, value);
    }
  fclose (fp);
  return 0;
}
