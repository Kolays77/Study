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
  int m = 0;
  tree_node *root = 0;
  if (argc != 2)
    {
      return 0;
    }
  else
    {
      m = atoi (argv[1]);
    }

  read_tree (file_name, root, m);

  fprintf (stdout, "TREE: \n");
  print_tree (root, 0);


  return 0;
}
