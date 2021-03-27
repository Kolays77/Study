#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

#define MAX_PRINTABLE_NUMBER 15
#define MAX_LENGTH 1000

char words[MAX_LENGTH][MAX_LENGTH], array[MAX_LENGTH][MAX_LENGTH];

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

int make_words_ex(char *buffer,
                  const char *sparse)
{
  int id_ = 0,
      idx = 0,
      difference = 0;
  while ((id_ = strcspn(buffer, sparse)) != (int) strlen(buffer))
    {
      if (!id_)
        {
          strcpy(buffer, buffer + 1);
          continue;
        }
      buffer[id_] = 0;
      strcpy(words[idx++], buffer);
      strcpy(buffer, buffer + id_ + 1);
    }
  strcpy(words[idx++], buffer);
  return idx;
}

int make_words(char *buffer, const char *sparse)
{
  int id_ = 0,
      idx = 0,
      difference = 0;
  while ((id_ = strcspn(buffer, sparse)) != (int) strlen(buffer))
    {
      if (!id_)
        {
          strcpy(buffer, buffer + 1);
          continue;
        }
      buffer[id_] = 0;
      strcpy(array[idx++], buffer);
      strcpy(buffer, buffer + id_ + 1);
    }
  strcpy(array[idx++], buffer);
  return idx;
}

int solve(const char *input,
	  const char *output,
	  char *str,
	  const char *sparse)
{
  FILE *fp1, *fp2;
  int idx1, idx2,
      counter = 0,
      num_of_words,
      num_of_finding_words;

  char buffer[MAX_LENGTH],
      buffer2[MAX_LENGTH];

  if (!(fp1 = fopen(input, "r")))
    {
      return -11;
    }
  if (!(fp2 = fopen(output, "w")))
    {
      return -12;
    }

  num_of_finding_words = make_words_ex(str, sparse);
  if (num_of_finding_words < 0)
    {
      return -3;
    }
  while (fgets(buffer, MAX_LENGTH, fp1))
    {
      make_string(buffer);
      strcpy(buffer2, buffer);
      num_of_words = make_words(buffer, sparse);
      for (idx1 = 0; idx1 < num_of_words; idx1++)
        {
          for (idx2 = 0; idx2 < num_of_finding_words; idx2++)
            {
              if (!strcmp(array[idx1], words[idx2]))
                {
                  fprintf(fp2, "%s\n", buffer2);
                  counter++;
                  break;
                }
            }
          if (idx2 < num_of_finding_words && !strcmp(array[idx1], words[idx2]))
            {
              break;
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
