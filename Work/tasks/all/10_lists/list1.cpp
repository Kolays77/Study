#include "list1.h"

void list::add_first (node *new_element)
{
  new_element->set_next (head);
  head = new_element;
  number_of_elements++;
  return;
}

void list::add_to_tail (node *new_element)
{
  node *tail = head;
  if (!head)
    {
      add_first (new_element);
      number_of_elements++;
      return;
    }
  while (tail)
    {
      tail = tail->get_next ();
    }
  tail->set_next (new_element);
  number_of_elements++;
  return;
}

void list::delete_list ()
{
  node *curr = head, *next;
  if (!head)
    {
      return;
    }
  for (curr = head; curr; curr = next)
    {
      next = curr->get_next ();
      delete curr;
      number_of_elements--;
    }
}


int list::delete_first ()
{
  node *new_head;
  if (!head)
    {
      return -1;
    }
  new_head = head->get_next ();
  delete head;
  if (new_head)
    {
      head = new_head;
    }
  else
    {
      head = 0;
    }
  number_of_elements--;
  return 0;
}

int list::delete_last ()
{
  node *new_tail, *tail;
  if (!head)
    {
      return -1;
    }
  new_tail = head;
  tail = new_tail->get_next ();
  if (!(tail))
    {
      delete head;
      head = 0;
    }
  while (tail)
    {
      new_tail = tail;
      tail = tail->get_next ();
    }

  new_tail->set_next (0);
  delete tail;
  number_of_elements--;
  return 0;
}

int list::delete_next (node *curr)
{
  node *next, *new_next;
  if (!curr)
    {
      return -1;
    }
  next = curr->get_next ();
  if (!next)
    {
      return -1;
    }
  new_next = next->get_next ();
  delete next;
  number_of_elements--;
  if (!new_next)
    {
      curr->set_next (NULL);
    }
  else
    {
      curr->set_next (new_next);
    }
  return 0;
}
