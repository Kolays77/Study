#include "student_list.h"

void student_list::delete_next () //+
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

void student_list::delete_previous () //+
{
   student_node *previous_curr;

   if (curr == head)
     {
       printf ("No previous element\n");
       return;
     }
   else if (curr == head->get_next())
     {
       delete head;
       head = curr;
       return;
     }
   else
     {
       previous_curr = curr->get_previous()->get_previous();
       delete curr->get_previous();
       curr->set_previous (previous_curr);
       previous_curr->set_next (curr);
     }
}

void student_list::add_next (student_node *new_element) //+
{
  student_node *next_curr;
  next_curr = curr->get_next();
  curr->set_next (new_element);
  new_element->set_next (next_curr);
  next_curr->set_previous (new_element);
}

void student_list::add_previous (student_node *new_element) //+
{
  student_node *previous_curr;
  previous_curr = curr->get_previous();
  curr->set_previous (new_element);
  new_element->set_previous (previous_curr);
  new_element->set_next (curr);
  previous_curr->set_next (new_element);
}

void student_list::add_first (student_node *new_element) //+
{
  head->set_previous (new_element);
  new_element->set_next (head);
  head = new_element;
  new_element->set_previous (NULL);
}

void student_list::add_last (student_node *new_element) //+
{
  tail->set_next (new_element);
  new_element->set_previous (tail);
  tail = new_element;
  new_element->set_next (NULL);
}

void student_list::delete_first () //+
{
  student_node *curr_head;
  curr_head = head->get_next();
  delete head;
  head = curr_head;
  curr_head->set_previous (NULL);
}

void student_list::delete_last () //+
{
  student_node *curr_tail;
  curr_tail = tail->get_previous();
  delete tail;
  tail = curr_tail;
  curr_tail->set_next (NULL);
}

void student_list::goto_head ()
{
  curr = head;
}

void student_list::goto_tail ()
{
  curr = tail;
}

void student_list::goto_next ()
{
  curr = curr->next;
}

void student_list::goto_previous ()
{
  curr = curr->get_previous();
}
