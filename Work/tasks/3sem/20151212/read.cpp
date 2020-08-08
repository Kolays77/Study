#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"

#define MAX_PRINTABLE_NUMBER 2
#define MAX_LENGTH 200
#define MAX_LEVEL 5

int tree::read (FILE *fp, int n3)
{
  int i, new_value;
  char name[MAX_LENGTH];
  tree_node *new_node;

  if (fscanf (fp, "%s%d", name, &new_value) != 2)
    {
      return -3;
    }
  new_node = new tree_node;
  new_node->init (name, new_value);
  root = new_node;

  for (i = 1; i < n3; i++)
    {
      if (fscanf (fp, "%s%d", name, &new_value) != 2)
        {
          return -3;
        }
      new_node = new tree_node;
      new_node->init (name, new_value);
      add (root, new_node);
    }
  make_first (root);
  return 0;
}

int queue::read (FILE *fp, int n2, int n3)
{
  int i;
  queue_node *new_node;
  for (i = 0; i < n2; i++)
    {
      new_node = new queue_node;
      new_node->read (fp, n3);
      add (new_node);
    }
  return 0;
}

int stack::read (FILE *fp, int n1, int n2, int n3)
{
  int i;
  stack_node *new_node;
  for (i = 0; i < n1; i++)
    {
      new_node = new stack_node;
      new_node->read (fp, n2, n3);
      add (new_node);
    }
  return 0;
}

void student::print ()
{
  printf ("%s %d\n", name, value);
}

static int draw = 0;

void tree::print (tree_node *root, int level, const char *pretty_string)
{
  if (level > MAX_LEVEL)
    {
      return;
    }
  if (root)
    {
      printf ("%s ", pretty_string);
      draw = (draw << 1);
      if (root->get_next())
        {
          draw = draw | 1;
        }
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
          fprintf (stdout, " . . . . . .\n");
          return;
        }
      else
        {
          fprintf (stdout, "[%d][%s %2d]\n", root->get_idx_of_child(), root->get_name(), root->get_value());
        }
      for (tree_node *curr_child = root->get_child(); curr_child; curr_child = curr_child->get_next())
        {
          if (!curr_child->get_next())
            {
              print (curr_child, level + 1, pretty_string);
              draw = (draw >> 1) << 1;
            }
          else
            {
              print (curr_child, level + 1, pretty_string);
            }
          draw = draw >> 1;
        }
    }
}

void queue::print (const char *pretty_string)
{
  int idx = 0,
      left_board = (number_of_elements > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : number_of_elements),
      right_board = ((number_of_elements - left_board) > left_board ? number_of_elements - left_board : left_board);
  queue_node *curr;
  char new_pretty_string[MAX_LENGTH];
  new_pretty_string[0] = 0;
  strcat (new_pretty_string, pretty_string);
  strcat (new_pretty_string, "    ");
  printf ("%s ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", pretty_string);
  for (curr = top; curr; curr = curr->get_next())
    {
      if (idx >= left_board)
        {
          break;
        }
      printf ("%s %d) TREE OF STUDENTS:\n", new_pretty_string, idx++);
      draw = 0;
      curr->print (curr->get_root(), 0, new_pretty_string);
      printf ("%s ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", pretty_string);
    }

  if (2 * MAX_PRINTABLE_NUMBER < number_of_elements)
    {
      printf ("%s   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...\n", pretty_string);
      printf ("%s   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...\n", pretty_string);
      printf ("%s   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...\n", pretty_string);
    }
  for (; idx < right_board && curr; curr = curr->get_next(), idx++)
    {
      if (idx == right_board)
        {
          break;
        }
    }

  if (number_of_elements > 2 * MAX_PRINTABLE_NUMBER)
    {
      printf ("%s ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", pretty_string);
    }
  for (; curr; curr = curr->get_next())
    {
      printf ("%s %d) TREE OF STUDENTS:\n", new_pretty_string, idx++);
      draw = 0;
      curr->print (curr->get_root(), 0, new_pretty_string);
      printf ("%s ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", pretty_string);
    }
}

void stack::print ()
{
  int idx = number_of_elements - 1,
      left_board = (number_of_elements > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : number_of_elements),
      right_board = ((number_of_elements - left_board) > left_board ? number_of_elements - left_board : left_board);
  stack_node *curr;
  char pretty_string[MAX_LENGTH];
  pretty_string[0] = 0;
  strcat (pretty_string, "::::");

  printf ("STACK OF QUEUES:\n");
  printf ("==========================================================================\n");
  printf ("==========================================================================\n");
  for (curr = last; curr; curr = curr->get_prev())
    {
      if (idx < right_board)
        {
          break;
        }
      printf ("%s %d. QUEUE OF TREES:\n", pretty_string, idx--);
      curr->print (pretty_string);
      printf ("==========================================================================\n");
      printf ("==========================================================================\n");
    }

  if (2 * MAX_PRINTABLE_NUMBER < number_of_elements)
    {
      printf ("...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...\n");
      printf ("...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...\n");
      printf ("...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...\n");
      printf ("...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...\n");
    }
  for (; idx >= left_board && curr; curr = curr->get_prev(), idx--)
    {}

  if (number_of_elements > 2 * MAX_PRINTABLE_NUMBER)
    {
      printf ("==========================================================================\n");
      printf ("==========================================================================\n");
    }
  for (; curr; curr = curr->get_prev())
    {
      printf ("%s %d. QUEUE OF TREES:\n", pretty_string, idx--);
      curr->print (pretty_string);
      printf ("==========================================================================\n");
      printf ("==========================================================================\n");
    }
}


void return_error (int result, const char *file_name)
{
  switch (result)
    {
    case (-1):
      fprintf (stdout, "Cannot open %s\n", file_name);
      break;
    case (-2):
      fprintf (stdout, "Cannot read %s\n", file_name);
      break;
    case (-3):
      fprintf (stdout, "%s is empty\n", file_name);
      break;
    default:
      fprintf (stdout, "Unknown error %d in %s\n", result, file_name);
    }
  return;
}
