#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

#define MAX_PRINTABLE_NUMBER 15
#define MAX_LENGTH 10000

int delete_sparse(char *buffer, const char *sparse)
{
  int id_,
      idx,
      len_buffer = strlen(buffer),
      difference = 0;

  while ((id_ = strcspn(buffer, sparse)) != len_buffer)
    {
      buffer[id_] = -1;
    }

  for (id_ = 0; id_ < len_buffer - difference; id_++)
    {
      idx = id_;
      while (buffer[idx + difference] == -1)
        {
          difference++;
        }
      buffer[id_] = buffer[id_ + difference];
      if (buffer[id_] == '\n')
        {
          buffer[id_] = 0;
        }
    }
  buffer[id_] = 0;
}

int solve(const char *input,
	  const char *output,
	  const char *str,
	  const char *sparse)
{
  FILE *fp1, *fp2;
  int len_str = strlen(str),
      len_sparse = strlen(sparse),
      counter = 0;
  char buffer[MAX_LENGTH],
      buffer2[MAX_LENGTH],
      *pointer;

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
      strcpy(buffer2, buffer);
      delete_sparse (buffer, sparse);
      if (strcmp(buffer, str))
        {
          fprintf(fp2, "%s\n", buffer2);
          counter++;
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
