#include "read1.h"

int list::read_list (const char *filename)
{
  FILE *fp;
  char name[MAX_LENGTH];
  node *curr = 0, *next = 0;

  if (!(fp = fopen (filename, "r")))
    {
      return -1;
    }
  if (fscanf (fp, "%s", name) == 1)
    {
      curr = new node (name);
      set_head (curr);
      number_of_elements++;
    }
  else
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      fclose (fp);
      return -3;
    }
  while (fscanf (fp, "%s", name) == 1)
    {
      next = new node (name);
      curr->set_next (next);
      curr = next;
      number_of_elements++;
    }
  curr->set_next (NULL);

  if (!feof (fp))
    {
      fclose (fp);
      return -2;
    }

  fclose (fp);
  return 0;
}

void list::print_list (FILE *fp)
{
  int idx = 0,
      left_board = (number_of_elements > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : number_of_elements),
      right_board = ((number_of_elements - left_board) > left_board ? number_of_elements - left_board : left_board);

  node *curr;

  fprintf (fp, "LIST OF STUDENTS (%d):\n", number_of_elements);
  for (curr = head; curr; curr = curr->get_next())
    {
      if (idx > left_board)
        {
          break;
        }
      fprintf (fp, " %2d: %s\n", idx++, curr->get_name());
    }

  if (2 * MAX_PRINTABLE_NUMBER < number_of_elements)
    {
      fprintf (fp, "  ...   ...   ...\n");
      fprintf (fp, "  ...   ...   ...\n");
    }
  for (; idx < right_board && curr; curr = curr->get_next(), idx++)
    {
      if (idx == right_board)
        {
          break;
        }
    }

  for (; curr; curr = curr->get_next())
    {
      if (idx == number_of_elements)
        {
          break;
        }
      fprintf (fp, " %2d: %s\n", idx++, curr->get_name());
    }
  fprintf (fp, "\n");
  return;
}

void return_error (int result, const char *file_name)
{
  switch (result)
    {
    case (-1):
      {
        fprintf (stdout, "Cannot open %s\n", file_name);
        break;
      }
    case (-2):
      {
        fprintf (stdout, "Cannot read %s\n", file_name);
        break;
      }
    case (-3):
      {
        fprintf (stdout, "%s is empty\n", file_name);
        break;
      }
    default:
      {
        fprintf (stdout, "Unknown error %d in %s\n", result, file_name);
      }
    }
  return;
}
