#include "queue.h"

#define MAX_PRINTABLE_NUMBER 3

queue::~queue ()
{
  while (top)
    {
      pop_left();
    }
  top = 0;
}

int queue::empty ()
{
  if (top)
    {
      return 0;
    }
  return 1;
}

void queue::pop_left ()
{
  student_node *new_top = top->get_next();
  delete top;
  top = new_top;
  //student_list::print(5);
}

student_node *queue::get_top()
{
  return top;
}


void queue::add (student_node *new_student)
{
  if (!top)
    {
      top = new_student;
      tail = new_student;
      return;
    }
  tail->set_next (new_student);
  tail = new_student;
}

void queue::add (const char *initial_name, int initial_value)
{
  student_node *new_student = new student_node (initial_name, initial_value);
  queue::add (new_student);
}


int queue::read (FILE **file_input, int n)
{
  int idx = 0;
  student *curr_student = 0;

  curr_student = new student;

  while (idx < n && curr_student->read (file_input))
    {
      student_node *new_student = new student_node (curr_student->get_name(), curr_student->get_value());
      add (new_student);
      idx++;
      delete new_student;
    }
  if (!(idx == n || feof (*file_input)))
    {
      delete curr_student;
      return -2;
    }
  delete curr_student;
  return idx;
}

void queue::print (int n)
{
  int idx = 0,
      left_board = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER: n),
      right_board = ((n - left_board) > left_board ? n - left_board : left_board);
  student_node *curr;
  printf ("QUEUE:\n");
  printf ("~~~~~~~~~~~~~~~~\n");
  for (curr = top; curr; curr = curr->get_next())
    {
      if (idx >= left_board)
        {
          break;
        }
      printf ("%2d: ", idx++);
      curr->print();
    }

  if (2 * MAX_PRINTABLE_NUMBER < n)
    {
      printf ("...   ...   ...\n...   ...   ...\n");
    }
  for (; idx < right_board && curr; curr = curr->get_next(), idx++)
    {
      if (idx == right_board)
        {
          break;
        }
    }

  if (n > 2 * MAX_PRINTABLE_NUMBER)
    {
      printf ("~~~~~~~~~~~~~~~~\n");
    }
  for (; curr; curr = curr->get_next())
    {
      if (idx == n)
        {
          break;
        }
      printf ("%2d: ", idx++);
      curr->print();
    }
  printf ("\n");
}
