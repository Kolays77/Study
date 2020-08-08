#include "head.h"

char *strcpy_ (char *string1, const char *string2)
{
  int idx;
  for (idx = 0; string2[idx]; idx++)
    {
      string1[idx] = string2[idx];
    }
  string1[idx] = 0;
  return string1;
}

char *strcat_ (char *string1, const char *string2)
{
  int idx;
  for (idx = 0; string1[idx]; idx++) {}
  strcpy_ (string1 + idx, string2);
  return string1;
}

int strcmp_ (char *string1, char *string2)
{
  int idx;
  for (idx = 0;
       string1[idx] && string1[idx] == string2[idx];
       idx++) {}
  return string1[idx] - string2[idx];
}

char *strchr_ (const char *string, int ch)
{
  int idx = 0;
  for (; string[idx]; idx++)
    {
      if (string[idx] == ch)
        {
          return (char *) string + idx;
        }
    }
  if (ch == 0)
    {
      return (char *) string + idx;
    }
  return 0;
}

char *strrchr_ (const char *string, int ch)
{
  int idx = 0;
  char *pointer = 0;
  for (; string[idx]; idx++)
    {
      if (string[idx] == ch)
        {
          pointer = (char *) string + idx;
        }
    }
  if (pointer)
    {
      return pointer;
    }
  if (ch == 0)
    {
      return (char *) string + idx;
    }
  return 0;
}

int strcspn_ (const char *string, const char *set_chars)
{
  int was_char[NUM_CHAR];
  int idx;

  for (idx = 0; idx < NUM_CHAR; idx++)
    {
      was_char[idx] = 0;
    }
  for (idx = 0; idx < set_chars[idx]; idx++)
    {
      was_char[(unsigned int) set_chars[idx]] = 1;
    }
  for (idx = 0; idx < string[idx]; idx++)
    {
      if (was_char[(unsigned int) string[idx]])
        {
          return idx;
        }
    }
  return idx;
}

int strspn_ (const char *string, const char *set_chars)
{
  int was_char[NUM_CHAR];
  int idx;

  for (idx = 0; idx < NUM_CHAR; idx++)
    {
      was_char[idx] = 0;
    }
  for (idx = 0; idx < set_chars[idx]; idx++)
    {
      was_char[(unsigned int) set_chars[idx]] = 1;
    }
  for (idx = 0; string[idx]; idx++)
    {
      if (!was_char[(unsigned int) string[idx]])
        {
          return idx;
        }
    }
  return idx;
}

char *strstr_ (char *string1, const char *string2)
{
  int idx1 = 0, idx2 = 0, start = 0;

  while (string1[start])
    {
      for (idx1 = start; string1[idx1] && (string1[idx1] != string2[0]); idx1++) {}
      if (!string1[idx1])
        {
          return 0;
        }
      else
        {
          for (idx2 = 0; (string1[idx1 + idx2] == string2[idx2] && string2[idx2]); idx2++);
          if (!string2[idx2])
            {
              return string1 + idx1;
            }
          else
            {
              start = idx1 + 1;
            }
        }
    }
  return 0;
}
