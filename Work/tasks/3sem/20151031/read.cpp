#include "tree.h"
#include "read.h"

#define LEN 4
#define MAX_LEVEL 6

int read_tree (const char *file_name, tree *root)
{
  FILE *fp;
  char name[LEN];
  int value;
  tree_node *new_root, *new_node;
  if (!(fp = fopen (file_name, "r")))
    {
      return -1;
    }

  if (fscanf (fp, "%s %d", name, &value) != 2)
    {
      return -2;
    }
  new_root = new tree_node;
  new_root->init (name, value);
  root->set_root (new_root);
  while (fscanf (fp, "%s %d", name, &value) == 2)
    {
      new_node = new tree_node;
      new_node->init (name, value);
      add_new_node (new_root, new_node);
    }
  if (!feof (fp))
    {
      return -3;
    }
  return 0;
}

static int draw = 0;

void print_tree (tree_node *root, int level, int from)
{
  if (level > MAX_LEVEL)
    {
      return;
    }
  if (root)
    {
      draw = (draw << 1);
      if (from == 1)
        {
          draw = draw | 1;
        }
      print_tree (root->get_left(), level + 1, 0);
      for (int i = 0; i < level; i++)
        {
          if (i == level - 1)
            {
              fprintf (stdout, "     |-----");
              continue;
            }
          if ((1 << (level - i - 1) & draw) >> (level - i - 1))
            {
              fprintf (stdout, "     |     ");
              continue;
            }
          fprintf (stdout, "           ");
        }
      if (level == MAX_LEVEL)
        {
          fprintf (stdout, " . . . \n");
        }
      else
        {
          fprintf (stdout, "[%s %2d]\n", root->get_name(), root->get_value());
        }
      draw = (draw >> 1) << 1;
      if (from == 0)
        {
          draw = draw | 1;
        }
      print_tree(root->get_right(), level + 1, 1);
      draw = draw >> 1;
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
