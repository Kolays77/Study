#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "tree.h"

#define MAX_LENGTH 200

int main (int /*argc*/, char** /*argv*/)
{
  const char *file_name = "a.txt";
  //int m = 0;
  b_tree *root = 0;
//  if (argc != 2)
//    {
//      return 0;
//    }
//  else
//    {
//      m = atoi (argv[1]);
//    }

  root = new b_tree ();
  root->read (file_name);

  fprintf (stdout, "TREE: \n");
  root->print (root->get_root (), 0);
  //printf ("%s %d\n", root->get_root ()->get_student(0)->get_name (), root->get_root ()->get_student(0)->get_value ());
 // printf ("%s %d\n", root->get_root ()->get_student(1)->get_name (), root->get_root ()->get_student(1)->get_value ());
  //printf ("%s %d\n", root->get_root ()->get_student(0)->get_name (), root->get_root ()->get_student(0)->get_value ());



  //  fx
  //bd msyz




  return 0;
}
