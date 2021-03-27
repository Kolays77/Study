#include "solve1.h"

int compare1 (node *elem, const char *string)
{
  return (strcmp (elem->get_name (), string) > 0);
}

int compare3 (node *elem, const char *string)
{
  return (strstr (elem->get_name (), string) != 0);
}

int compare5 (node *elem, const char *string)
{
  const char *name = elem->get_name ();
  return (strspn (name, string) == strlen (name));
}

list *solve1 (list *list_head, const char *string, int (*cmp) (node *, const char *))
{
  node *curr = list_head->get_head (), *prev;

  while (curr && (*cmp) (curr, string))
    {
      list_head->delete_first ();
      curr = list_head->get_head ();
    }
  prev = list_head->get_head ();
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  while (curr)
    {
      if ((*cmp) (curr, string))
        {
          list_head->delete_next (prev);
          curr = prev->get_next ();
        }
      else
        {
          prev = curr;
          curr = curr->get_next ();
        }
    }
  return list_head;
}

int compare7 (node *elem)
{
  return (strlen (elem->get_name ()) > strlen (elem->get_next ()->get_name ()));
}

int compare9 (node *elem)
{
  node *curr = elem->get_next (), *next = curr->get_next ();
  size_t curr_len = strlen (curr->get_name ());
  return (next && strlen (elem->get_name ()) > curr_len &&
          strlen (next->get_name ()) > curr_len);
}

list *solve7 (list *list_head, int (*cmp) (node *))
{
  node *next, *curr, *prev = list_head->get_head ();
  int need_delete_curr = 0, need_delete_next = 0;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  if (!curr)
    {
      return list_head;
    }
  next = curr->get_next ();
  need_delete_curr = (*cmp) (prev); //check curr
  while (next)
    {
      need_delete_next = (*cmp) (curr); //check next
      if (need_delete_curr)
        {
          list_head->delete_next (prev); //delete curr
        }
      else
        {
          prev = curr;
        }
      curr = next;
      next = next->get_next ();
      need_delete_curr = need_delete_next;
    }
  if (need_delete_curr)
    {
      list_head->delete_next (prev);
    }
  return list_head;
}

int compare11 (node *elem)
{
  return !strcmp (elem->get_name (), elem->get_next ()->get_name ());
}

int compare13 (node *elem)
{
  return strlen (elem->get_name ()) == strlen (elem->get_next ()->get_name ());
}

list *solve11 (list *list_head, int (*cmp) (node *))
{
  node *prev = list_head->get_head (), *curr;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  while (curr)
    {
      while ((*cmp) (prev))
        {
          list_head->delete_next (prev);
          curr = prev->get_next ();
          if (!curr)
            {
              return list_head;
            }
        }
      prev = curr;
      curr = curr->get_next ();
    }
  return list_head;
}

list *solve15 (list *list_head, const char *string, int (*cmp) (node *, const char *))
{
  node *prev = list_head->get_head (), *curr;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  while (curr)
    {
      if ((*cmp) (prev, string))
        {
          while ((*cmp) (curr, string))
            {
              list_head->delete_next (prev);
              curr = prev->get_next ();
              if (!curr)
                {
                  return list_head;
                }
            }
        }
      prev = curr;
      curr = curr->get_next ();
    }
  return list_head;
}

int compare21 (node *elem)
{
  return strcmp (elem->get_name (), elem->get_next ()->get_name ()) < 0;
}

list *solve21 (list *list_head, int (*cmp) (node *))
{
  node *prev = list_head->get_head (), *curr, *first;\
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  while (curr)
    {
      if ((*cmp) (prev))
        {
          first = prev;
          prev = curr;
          if (!(curr = curr->get_next ()))
            {
              return list_head;
            }
          while ((*cmp) (prev))
            {
              list_head->delete_next (first);
              prev = curr;
              if (!curr || !(curr = curr->get_next ()))
                {
                  return list_head;
                }
            }
        }
      prev = curr;
      curr = curr->get_next ();
    }
  return list_head;
}

int compare25 (node *elem, const char *string)
{
  return !strcmp (elem->get_name (), string);
}

list *solve25 (list *list_head, const char *string, int (*cmp) (node *, const char *))
{
  node *curr, *prev = list_head->get_head(), *next;
  int delete_curr, delete_next, delete_head = 0;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  if (!curr)
    {
      return list_head;
    }
  delete_head = (*cmp) (curr, string);
  delete_curr = (*cmp) (prev, string);

  while (curr)
    {
      next = curr->get_next();
      if (!next)
        {
          if (delete_curr)
            {
              list_head->delete_next (prev);
            }
          break;
        }
      delete_next = (*cmp) (curr, string);
      if (delete_curr || (*cmp) (next, string))
        {
          list_head->delete_next (prev);
        }
      else
        {
          prev = curr;
        }
      curr = next;
      delete_curr = delete_next;
    }
  if (delete_head)
    {
      list_head->delete_first ();
    }

  return list_head;
}
