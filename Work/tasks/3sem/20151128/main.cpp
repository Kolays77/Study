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
  int result, index, n = 0, m = 0, k = 0;
  double counter_of_time;
  tree *root = 0;

  if (argc != 4 && argc != 3)
    {
      fprintf (stdout, "Usage: %s [m] [#] [<n>]\n", argv[0]);
      return 1;
    }

  if ((m = atoi (argv[1])) <= 0)
    {
      fprintf (stdout, "Cannot read [m]!\n");
      return 1;
    }
  if ((index = atoi (argv[2])) <= 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 1;
    }
  else
    {
      if (index > 6)
        {
          fprintf (stdout, "The number of solve is in [1..6]!\n");
          return 1;
        }
    }
  root = new tree (m);
  if (argc == 3)
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
      if ((n = atoi (argv[3])) <= 0)
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
  print_tree (root->get_root(), 0);

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
      if (k >= m)
        {
          fprintf (stdout, "[k] must not be more then [m]!\n");
        }
      result = count_vertex_children_K (root->get_root(), k);
      fprintf (stdout, "The number of vertexes is %d\n", result);
      break;
    case (2):
      result = count_vertex_subtrees_K (root->get_root(), k);
      fprintf (stdout, "The number of vertexes is %d\n", result);
      break;
    case (3):
      result = count_vertex_levels_K (root->get_root(), k);
      fprintf (stdout, "The number of vertexes is %d\n", result);
      break;
    case (4):
      result = count_vertex_subtrees_on_level_K (root->get_root(), k);
      fprintf (stdout, "The number of vertexes is %d\n", result);
      break;
    case (5):
      result = number_of_elements_on_level_h (root->get_root(), k);
      fprintf (stdout, "The number of vertexes is %d\n", result);
      break;
    case (6):
      result = count_elements_branches_K (root->get_root(), k, 1);
      fprintf (stdout, "The number of vertexes is %d\n", result);
      break;
    }
  counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
  fprintf (stdout, "Elapsed = %.3f\n", counter_of_time);

  delete root;
  return 0;
}
