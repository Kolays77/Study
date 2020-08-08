#include "head.h"

int main (int argc, char *argv[])
{
  char string1[LENGTH], string2[LENGTH];
  int task_number;
  int result;

  if (argc != 2)
    {
      fprintf (stdout, "Usage: %s [#]\n", argv[0]);
      return 1;
    }
  if ((task_number = atoi (argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 1;
    }
  fprintf (stdout, "Input string:  ");
  if (!fgets (string1, LENGTH, stdin))
    {
      fprintf (stdout, "Cannot read string!\n");
      return -1;
    }
  for (int idx = 0; string1[idx]; idx++)
    {
      if (string1[idx] == '\n')
        {
          string1[idx] = 0;
          break;
        }
    }

  switch (task_number)
    {
    case 1:
      {
        strcpy_ (string2, string1);
        fprintf (stdout, "New string:  %s\n", string2);
        break;
      }

    case 2:
      {
        fprintf (stdout, "Input second string:  ");
        if (!fgets (string2, LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read string!\n");
            return -1;
          }
        for (int idx = 0; string2[idx]; idx++)
          {
            if (string2[idx] == '\n')
              {
                string2[idx] = 0;
                break;
              }
          }

        fprintf (stdout, "New string:  %s\n", strcat_ (string1, string2));
        string1[0] = 0;
        strcat_ (string1, string2);
        break;
      }

    case 3:
      {
        fprintf (stdout, "Input second string:  ");
        if (!fgets (string2, LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read string!\n");
            return -1;
          }
        for (int idx = 0; string2[idx]; idx++)
          {
            if (string2[idx] == '\n')
              {
                string2[idx] = 0;
                break;
              }
          }

        result = strcmp_ (string1, string2);

        if (result < 0)
          {
            fprintf (stdout, "the first < the second\n");
          }
        else if (result > 0)
          {
            fprintf (stdout, "the first > the second\n");
          }
        else
          {
            fprintf (stdout, "the first = the second\n");
          }

        result = strcmp_ (string1, string2);
        break;
      }

    case 4:
      {
        char ch;
        char *entry;

        fprintf (stdout, "Input char:  ");
        if (fscanf (stdin, "%c", &ch) != 1)
          {
            fprintf (stdout, "Cannot read [char]!\n");
            return -1;
          }

        if ((entry = strchr_ (string1, ch)) != 0)
          {
            fprintf (stdout, "The first entry:  %s\n", entry);
          }
        else
          {
            fprintf (stdout, "There is no char '%c' in string\n", ch);
          }
        entry = strchr_ (string1, ch);
        break;
      }

    case 5:
      {
        char ch;
        char *entry;

        fprintf (stdout, "Input char:  ");
        if (fscanf (stdin, "%c", &ch) != 1)
          {
            fprintf (stdout, "Cannot read [char]!\n");
            return -1;
          }

        if ((entry = strrchr_ (string1, ch)) != 0)
          {
            fprintf (stdout, "The last entry:  %s\n", entry);
          }
        else
          {
            fprintf (stdout, "There is no char '%c' in string\n", ch);
          }
        entry = strrchr_ (string1, ch);
        break;
      }

    case 6:
      {
        fprintf (stdout, "Input second string:  ");
        if (!fgets (string2, LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read string!\n");
            return -1;
          }
        for (int idx = 0; string2[idx]; idx++)
          {
            if (string2[idx] == '\n')
              {
                string2[idx] = 0;
                break;
              }
          }

        fprintf (stdout, "Index = %d\n", strcspn_ (string1, string2));

        result = strcspn_ (string1, string2);
        break;
      }

    case 7:
      {
        fprintf (stdout, "Input second string:  ");
        if (!fgets (string2, LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read string!\n");
            return -1;
          }
        for (int idx = 0; string2[idx]; idx++)
          {
            if (string2[idx] == '\n')
              {
                string2[idx] = 0;
                break;
              }
          }

        fprintf (stdout, "Index = %d\n", strspn_ (string1, string2));

        result = strspn_ (string1, string2);
        break;
      }

    case 8:
      {
        char *entry;

        fprintf (stdout, "Input second string:  ");
        if (!fgets (string2, LENGTH, stdin))
          {
            fprintf (stdout, "Cannot read string!\n");
            return -1;
          }
        for (int idx = 0; string2[idx]; idx++)
          {
            if (string2[idx] == '\n')
              {
                string2[idx] = 0;
                break;
              }
          }
        if ((entry = strstr_ (string1, string2)) != 0)
          {
            fprintf (stdout, "The first entry:  %s\n", entry);
          }
        else
          {
            fprintf (stdout, "There is no substring \"%s\" in string\n", string2);
          }
        entry = strstr_ (string1, string2);
        break;
      }
    default:
      {
        fprintf (stdout, "There is no task with number [%d]\n", task_number);
        return 1;
      }
    }

  return 0;
}
