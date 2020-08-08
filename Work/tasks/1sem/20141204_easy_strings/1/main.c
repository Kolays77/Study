#include "head.h"

int main(void)
{
  char string[LENGTH];
  double counter_of_time;
  int number, answer, idx;
  printf("Input string: ");
  if (!fgets(string, LENGTH, stdin))
    {
      printf("Cannot read string!\n");
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
  counter_of_time = clock();
  for (number = 0; number < NUMBER; number++)
    {
      answer = strlen(string);
    }
  counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
  printf("Length of string is %d bytes\n", answer);
  printf("Elapsed  = %.6lf\n\n", counter_of_time);

  counter_of_time = clock();
  for (number = 0; number < NUMBER; number++)
    {
      answer = strlen_(string);
    }
  counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
  printf("Length of string is %d bytes\n", answer);
  printf("Elapsed_ = %.6lf\n\n", counter_of_time);
  return 0;
}
