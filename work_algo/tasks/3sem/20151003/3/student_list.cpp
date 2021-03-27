#include "student_list.h"

void student_list::delete_next ()
{
   student_node *next_curr;

   if (!curr->get_next())
     {
       return;
     }
   next_curr = curr->get_next()->get_next();
   delete curr->get_next();
   curr->set_next (next_curr);
}

void student_list::add (student_node *new_element)
{
  student_node *next_curr;
  next_curr = curr->get_next();
  curr->set_next (new_element);
  new_element->set_next (next_curr);
}

void student_list::add_first (student_node *new_element)
{
  new_element->set_next (head);
  head = new_element;
}

void student_list::delete_first ()
{
  student_node *curr_head;
  curr_head = head->get_next();
  delete head;
  head = curr_head;
}

void student_list::goto_head ()
{
  curr = head;
}

void student_list::goto_next ()
{
  curr = curr->get_next();
}
