#include "solve2.h"


int compare2 (node *elem, const char *string)
{
  return (strcmp (elem->get_name (), string) > 0);
}

int compare4 (node *elem, const char *string)
{
  return strstr (elem->get_name (), string) != 0;
}

int compare6 (node *elem, const char *string)
{
  const char *name = elem->get_name ();
  return (strspn (name, string) == strlen (name));
}

list *solve2 (list *list_head, const char *string, int (*cmp) (node *, const char*))
{
  node *curr = list_head->get_head (), *next;
  while (curr)
    {
      next = curr->get_next ();
      if ((*cmp) (curr, string))
        {
          list_head->delete_curr (curr);
        }
      curr = next;
    }
  return list_head;
}

int compare8 (node *elem)
{
  return (strlen (elem->get_name ()) < strlen (elem->get_prev ()->get_name ()));
}

int compare10 (node *curr)
{
  node *prev = curr->get_prev (), *next = curr->get_next ();
  size_t curr_len = strlen (curr->get_name ());
  return (next && strlen (prev->get_name ()) > curr_len &&
          strlen (next->get_name ()) > curr_len);
}

list *solve8 (list *list_head, int (*cmp) (node *))
{
  node *next, *curr = list_head->get_head ();
  int need_delete_curr = 0, need_delete_next = 0;
  if (!curr)
    {
      return list_head;
    }
  curr = curr->get_next ();
  if (!curr)
    {
      return list_head;
    }
  need_delete_curr = (*cmp) (curr);
  next = curr->get_next ();
  while (next)
    {
      need_delete_next = (*cmp) (next);
      if (need_delete_curr)
        {
          list_head->delete_curr (curr);
        }
      curr = next;
      next = next->get_next ();
      need_delete_curr = need_delete_next;
    }
  if (need_delete_curr)
    {
      list_head->delete_curr (curr);
    }
  return list_head;
}

int compare12 (node *elem)
{
  node *next = elem->get_next ();
  return next && !strcmp (elem->get_name (), next->get_name ());
}

int compare14 (node *elem)
{
  node *next = elem->get_next ();
  return next && strlen (elem->get_name ()) == strlen (next->get_name ());
}

list *solve12 (list *list_head, int (*cmp) (node *))
{
  node *curr = list_head->get_head (), *last;
  while (curr)
    {
      for (last = curr; last && (*cmp) (last); last = last->get_next ());
      if (curr != last)
        {
          list_head->delete_segment (curr->get_next (), last);
        }
      curr = curr->get_next ();
    }
  return list_head;
}

list *solve16 (list *list_head, const char *string, int (*cmp) (node *, const char *))
{
  node *curr = list_head->get_head (), *last;
  while (curr)
    {
      for (last = curr; last && (*cmp) (last, string); last = last->get_next ());
      if (curr != last)
        {
          list_head->delete_segment_without_last (curr->get_next (), last);
        }
      curr = curr->get_next ();
    }
  return list_head;
}

int compare22 (node *elem)
{
  node *next = elem->get_next ();
  return next && (strcmp (elem->get_name (), next->get_name ()) < 0);
}

int compare24 (node *elem)
{
  node *next = elem->get_next ();
  return next && (strlen (elem->get_name ()) > strlen (next->get_name ()));
}

list *solve22 (list *list_head, int (*cmp) (node *))
{
  node *curr = list_head->get_head (), *last;
  while (curr)
    {
      for (last = curr; last && (*cmp) (last); last = last->get_next ());
      if (curr != last)
        {
          list_head->delete_segment_without_last (curr->get_next (), last);
        }
      curr = curr->get_next ();
    }
  return list_head;
}

int compare26 (node *elem, const char *string)
{
  return !strcmp (elem->get_name (), string);
}

list *solve26 (list *list_head, const char *string, int (*cmp) (node *, const char *))
{
  node *curr = list_head->get_head(), *next;
  int delete_curr = 0, delete_next = 0;

  while (curr && (next = curr->get_next ()))
    {
      delete_next = (*cmp) (curr, string);
      if (delete_curr || (*cmp) (next, string))
        {
          list_head->delete_curr (curr);
        }
      curr = next;
      delete_curr = delete_next;
    }
  if (delete_curr)
    {
      list_head->delete_curr (curr);
    }

  return list_head;
}
