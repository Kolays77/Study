#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

#define MAX_PRINTABLE_NUMBER 15
#define MAX_LENGTH 10000

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

int make_examplar(char *str)
{
  int idx,
      id_ = 0,
      difference = 0,
      cur_len = 0;
  for (idx = 0;; idx++)
    {
      if (str[idx + difference] == '\\')
        {
          if (str[idx + difference + 1] == '.' ||
              str[idx + difference + 1] == '\\')
            {
              difference++;
            }
          else
            {
              return -4;
            }
          str[idx] = str[idx + difference];
          continue;
        }
      if (str[idx + difference] == '.')
        {
          str[idx] = 1;
          continue;
        }
      str[idx] = str[idx + difference];
      if (str[idx + difference] == '\n' ||
          str[idx + difference] == 0)
        {
          str[idx] = 0;
          break;
        }
    }
  return id_;
}

int compare(char *new_string,
            char *examplar)
{
  int idx = 0,
      len_new,
      len_examplar;

  if ((len_new = strlen(new_string)) !=
      (len_examplar = strlen(examplar)))
    {
      return 0;
    }
  for (idx = 0; idx < len_new; idx++)
    {
      if (examplar[idx] == 1)
        {
          continue;
        }
      if (examplar[idx] != new_string[idx])
        {
          return 0;
        }
    }
  return 1;
}

int solve(const char *input,
	  const char *output,
	  char *examplar)
{
  FILE *fp1, *fp2;
  int idx = 0, id_ = 0,
      counter = 0;

  char buffer[MAX_LENGTH];

  if (!(fp1 = fopen(input, "r")))
    {
      return -11;
    }
  if (!(fp2 = fopen(output, "w")))
    {
      return -12;
    }
  make_examplar(examplar);
  while (fgets(buffer, MAX_LENGTH, fp1))
    {
      make_string(buffer);
      if (compare(buffer, examplar))
        {
          counter++;
          fprintf(fp2, "%s\n", buffer);
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
