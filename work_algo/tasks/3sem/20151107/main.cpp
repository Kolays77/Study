#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "read.h"
#include "solve.h"
#include "tree.h"

#define MAX_LENGTH 200

int main (int argc, char **argv)
{
  const char *file_name = "a.txt";
  int result, index, n = 0, k = 0;
  double counter_of_time;
  tree *root = 0;

  if (argc != 3 && argc != 2)
    {
      fprintf (stdout, "Usage: %s [#] [<n>]\n", argv[0]);
      return 1;
    }

  if ((index = atoi (argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 1;
    }
  else
    {
      if (index > 9)
        {
          fprintf (stdout, "The number of solve is in [1..9]!\n");
          return 1;
        }
    }

  root = new tree;
  if (argc == 2)
    {
      result = read_tree (file_name, root);
      if (result < 0)
        {
          return_error (result, file_name);
          delete root;
          return -1;
        }
    }
  else
    {
      if ((n = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          delete root;
          return 1;
        }
      result = generate (root, n);
      if (result < 0)
        {
          fprintf (stdout, "Unknown error %d in generating list", result);
          delete root;
          return -2;
        }
    }

  n = result;

  fprintf (stdout, "TREE: \n");
  print_tree (root->get_root(), 0, 0);

  counter_of_time = clock();
  fprintf (stdout, "#%d\n", index);
  fprintf (stdout, "Input [k]: ");
  if (fscanf (stdin, "%d", &k) != 1)
    {
      fprintf (stdout, "Cannot read [k]!\n");
      return -1;
    }

  switch (index)
    {
    case (1):
      result = count_subtrees_vertex (root->get_root(), k);
      fprintf (stdout, "The number of subtrees is %d\n", result);
      break;
    case (2):
      result = sum_of_number_elements_in_subtrees (root->get_root(), k);
      fprintf (stdout, "The summary number of elements in subtrees is %d\n", result);
      break;
    case (3):
      result = count_subtrees_levels (root->get_root(), k);
      fprintf (stdout, "The number of subtrees is %d\n", result);
      break;
    case (4):
      result = count_subtrees_elements_on_level (root->get_root(), k);
      fprintf (stdout, "The number of subtrees is %d\n", result);
      break;
    case (5):
      result = number_of_elements_on_level_k (root->get_root(), k);
      fprintf (stdout, "The number of elements on level [k] is %d\n", result);
      break;
    }
  counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
  fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);

  delete root;
  return 0;
}
