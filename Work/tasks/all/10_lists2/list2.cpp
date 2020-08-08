#include "list2.h"

void list::add_first (node *new_element)
{
  new_element->set_next (head);
  new_element->set_prev (NULL);
  head = new_element;
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
    }
  number_of_elements = 0;
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
      new_head->set_prev (NULL);
    }
  else
    {
      head = 0;
    }
  number_of_elements--;
  return 0;
}

int list::delete_curr (node *curr)
{
  node *prev, *next;
  if (!curr)
    {
      return -1;
    }
  prev = curr->get_prev ();
  next = curr->get_next ();
  number_of_elements--;
  delete curr;
  if (!prev)
    {
      if (!next)
        {
          head = 0;
          return 0;
        }
      next->set_prev (NULL);
      head = next;
      return 0;
    }
  if (!next)
    {
      prev->set_next (NULL);
      return 0;
    }
  prev->set_next (next);
  next->set_prev (prev);
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
      new_next->set_prev (curr);
    }
  return 0;
}


int list::delete_prev (node *curr)
{
  node *prev, *new_prev;
  if (!curr)
    {
      return -1;
    }
  prev = curr->get_prev ();
  if (!prev)
    {
      return -1;
    }
  new_prev = prev->get_prev ();
  delete prev;
  number_of_elements--;
  if (!new_prev)
    {
      curr->set_prev (NULL);
      head = curr;
    }
  else
    {
      curr->set_prev (new_prev);
      new_prev->set_next (curr);
    }
  return 0;
}


int list::delete_segment (node *first, node *last)
{
  node *curr = first, *next;
  int last_is_tail = 0;
  if (!first && !last)
    {
      return -1;
    }
  if (!(last->get_next ()))
    {
      last_is_tail = 0;
    }
  while (curr && curr != last)
    {
      next = curr->get_next ();
      delete_curr (curr);
      curr = next;
    }
  if (!curr && !last_is_tail)
    {
      return -2;
    }
  delete_curr (last);
  return 0;
}

int list::delete_segment_without_last (node *first, node *last)
{
  node *curr = first, *next;
  int last_is_tail = 0;
  if (!first && !last)
    {
      return -1;
    }
  if (!(last->get_next ()))
    {
      last_is_tail = 0;
    }
  while (curr && curr != last)
    {
      next = curr->get_next ();
      delete_curr (curr);
      curr = next;
    }
  if (!curr && !last_is_tail)
    {
      return -2;
    }
  return 0;
}
