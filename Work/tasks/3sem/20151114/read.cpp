#include "tree.h"
#include "read.h"

#define LEN 1024
#define MAX_LEVEL 7

int read_tree (const char *file_name, tree_node *root, int m)
{
  FILE *fp;
  char name[LEN];
  int value;
  student *new_node;
  if (!(fp = fopen (file_name, "r")))
    {
      return -1;
    }

  if (fscanf (fp, "%s %d", name, &value) != 2)
    {
      return -2;
    }
  new_node->init (name, value);
  root = tree_node (new_node, 0, m, 1);
  while (fscanf (fp, "%s %d", name, &value) == 2)
    {
      new_node->init (name, value);
      add_new_node (root, new_node);
    }
  if (!feof (fp))
    {
      return -3;
    }
  return 0;
}

static int draw = 0;

void print_tree (tree_node *root, int level)
{
  if (level > MAX_LEVEL)
    {
      return;
    }
  if (root)
    {
      for (int i = 0; i < 2 * m; i++)
        {
          if (root->get_student (i))
          printf ("%s;  ", root->get_student(i));
          else
            printf ("NULL; ");
        }
      printf ("\n");
      for (int i = 0; i < 2*m + 1; i++)
        {
          for (int i = 0; i < level; i++) printf ("    ");
          printf ("\n");
          printf ("%d) ", i);
          print_tree (root->get_descedant (i), level + 1);
        }

    }
}

void return_error (int result, const char *file_name)
{
  switch (result)
    {
    case (-1):
      fprintf (stdout, "Cannot open %s\n", file_name);
      break;
    case (-3):
      fprintf (stdout, "Cannot read %s\n", file_name);
      break;
    case (-2):
      fprintf (stdout, "%s is empty\n", file_name);
      break;
    default:
      fprintf (stdout, "Unknown error %d in %s\n", result, file_name);
    }
  return;
}
