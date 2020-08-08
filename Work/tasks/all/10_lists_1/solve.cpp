#include "solve.h"

list *solve1 (list *list_head, char *string, int *number_of_elements)
{
  node *curr = list_head->get_head (), *prev;

  while (curr && strcmp (curr->get_name (), string) > 0)
    {
      list_head->delete_first ();
      (*number_of_elements)--;
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
      if (strcmp (curr->get_name (), string) > 0)
        {
          prev->delete_next ();
          (*number_of_elements)--;
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

list *solve3 (list *list_head, char *string, int *number_of_elements)
{
  node *curr = list_head->get_head (), *prev;

  while (curr && strstr (curr->get_name (), string))
    {
      list_head->delete_first ();
      (*number_of_elements)--;
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
      if (strstr (curr->get_name (), string))
        {
          prev->delete_next ();
          (*number_of_elements)--;
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


list *solve5 (list *list_head, char *string, int *number_of_elements)
{
  node *curr = list_head->get_head (), *prev;

  while (curr && strspn (curr->get_name (), string) == strlen (curr->get_name ()))
    {
      list_head->delete_first ();
      (*number_of_elements)--;
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
      if (strspn (curr->get_name (), string) == strlen (curr->get_name ()))
        {
          prev->delete_next ();
          (*number_of_elements)--;
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


list *solve7 (list *list_head, int *number_of_elements)
{
  node *curr, *prev = list_head->get_head ();
  size_t len_prev, len_curr;

  if (!prev)
    {
      return list_head;
    }
  len_prev = strlen (prev->get_name ());
  curr = prev->get_next ();
  while (curr)
    {
      len_curr = strlen (curr->get_name ());
      if (len_prev > len_curr)
        {
          prev->delete_next ();
          (*number_of_elements)--;
          curr = prev->get_next ();
        }
      else
        {
          prev = curr;
          curr = curr->get_next ();
        }
      len_prev = len_curr;
    }
  return list_head;
}

list *solve9 (list *list_head, int *number_of_elements)
{
  node *curr, *prev = list_head->get_head (), *next;
  size_t len_prev, len_curr, len_next;

  if (!prev)
    {
      return list_head;
    }
  len_prev = strlen (prev->get_name ());
  curr = prev->get_next ();
  if (!curr)
    {
      return list_head;
    }
  len_curr = strlen (curr->get_name ());
  next = curr->get_next ();
  while (next)
    {
      len_next = strlen (next->get_name ());
      if (len_prev > len_curr && len_curr < len_next)
        {
          prev->delete_next ();
          (*number_of_elements)--;
        }
      else
        {
          prev = curr;
        }
      curr = next;
      next = next->get_next ();
      len_prev = len_curr;
      len_curr = len_next;
    }
  return list_head;
}

list *solve11 (list *list_head, int *number_of_elements)
{
  node *prev = list_head->get_head (), *curr;
  const char *prev_string, *curr_string;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  prev_string = prev->get_name ();
  while (curr)
    {
      curr_string = curr->get_name ();
      while (!strcmp (prev_string, curr_string))
        {
          prev->delete_next ();
          (*number_of_elements)--;
          curr = prev->get_next ();
          if (curr)
            {
              curr_string = curr->get_name ();
            }
          else
            {
              return list_head;
            }
        }
      prev = curr;
      prev_string = curr_string;
      curr = curr->get_next ();
    }
  return list_head;
}

list *solve13 (list *list_head, int *number_of_elements)
{
  node *prev = list_head->get_head (), *curr;
  size_t len_prev, len_curr;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  len_prev = strlen (prev->get_name ());
  while (curr)
    {
      len_curr = strlen (curr->get_name ());
      while (len_prev == len_curr)
        {
          prev->delete_next ();
          (*number_of_elements)--;
          curr = prev->get_next ();
          if (curr)
            {
              len_curr = strlen (curr->get_name ());
            }
          else
            {
              return list_head;
            }
        }
      prev = curr;
      len_prev = len_curr;
      curr = curr->get_next ();
    }
  return list_head;
}

list *solve15 (list *list_head, char *string, int *number_of_elements)
{
  node *prev = list_head->get_head (), *curr;
  const char *prev_string, *curr_string;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  prev_string = prev->get_name ();
  while (curr)
    {
      curr_string = curr->get_name ();
      if (strcmp (prev_string, string) > 0)
        {
          while (strcmp (curr_string, string) > 0)
            {
              prev->delete_next ();
              (*number_of_elements)--;
              curr = prev->get_next ();
              if (curr)
                {
                  curr_string = curr->get_name ();
                }
              else
                {
                  return list_head;
                }
            }
        }
      prev = curr;
      prev_string = curr_string;
      curr = curr->get_next ();
    }
  return list_head;
}

list *solve17 (list *list_head, char *string, int *number_of_elements)
{
  node *prev = list_head->get_head (), *curr;
  const char *prev_string, *curr_string;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  prev_string = prev->get_name ();
  while (curr)
    {
      curr_string = curr->get_name ();
      if (strstr (prev_string, string))
        {
          while (strstr (curr_string, string))
            {
              prev->delete_next ();
              (*number_of_elements)--;
              curr = prev->get_next ();
              if (curr)
                {
                  curr_string = curr->get_name ();
                }
              else
                {
                  return list_head;
                }
            }
        }
      prev = curr;
      prev_string = curr_string;
      curr = curr->get_next ();
    }
  return list_head;
}

list *solve19 (list *list_head, char *string, int *number_of_elements)
{
  node *prev = list_head->get_head (), *curr;
  const char *prev_string, *curr_string;
  size_t prev_len, curr_len;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  prev_string = prev->get_name ();
  prev_len = strlen (prev_string);
  while (curr)
    {
      curr_string = curr->get_name ();
      curr_len = strlen (curr_string);
      if (strspn (prev_string, string) == prev_len)
        {
          while (strspn (curr_string, string) == curr_len)
            {
              prev->delete_next ();
              (*number_of_elements)--;
              curr = prev->get_next ();
              if (curr)
                {
                  curr_string = curr->get_name ();
                  curr_len = strlen (curr_string);
                }
              else
                {
                  return list_head;
                }
            }
        }
      prev = curr;
      prev_string = curr_string;
      prev_len = curr_len;
      curr = curr->get_next ();
    }
  return list_head;
}

list *solve21 (list *list_head, int *number_of_elements)
{
  node *prev = list_head->get_head (), *curr, *first;
  const char *prev_string, *curr_string;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  prev_string = prev->get_name ();
  while (curr)
    {
      first = prev;
      curr_string = curr->get_name ();
      if (strcmp (prev_string, curr_string) < 0)
        {
          prev_string = curr_string;
          if ((curr = curr->get_next ()) != 0)
            {
              curr_string = curr->get_name ();
            }
          else
            {
              return list_head;
            }
          while (strcmp (prev_string, curr_string) < 0)
            {
              first->delete_next ();
              (*number_of_elements)--;
              if (curr && (curr = curr->get_next ()) != 0)
                {
                  prev_string = curr_string;
                  curr_string = curr->get_name ();
                }
              else
                {
                  return list_head;
                }
            }
        }
      prev = curr;
      prev_string = curr_string;
      curr = curr->get_next ();
    }
  return list_head;
}

list *solve23 (list *list_head, int *number_of_elements)
{
  node *prev = list_head->get_head (), *curr, *first;
  size_t len_prev, len_curr;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  len_prev = strlen (prev->get_name ());
  while (curr)
    {
      first = prev;
      len_curr = strlen (curr->get_name ());
      if (len_prev >= len_curr)
        {
          len_prev = len_curr;
          if ((curr = curr->get_next ()) != 0)
            {
              len_curr = strlen (curr->get_name ());
            }
          else
            {
              return list_head;
            }
          while (len_prev >= len_curr)
            {
              first->delete_next ();
              (*number_of_elements)--;
              if (curr && (curr = curr->get_next ()) != 0)
                {
                  len_prev = len_curr;
                  len_curr = strlen (curr->get_name ());
                }
              else
                {
                  return list_head;
                }
            }
        }
      prev = curr;
      len_prev = len_curr;
      curr = curr->get_next ();
    }
  return list_head;
}

list *solve25 (list *list_head, char *string, int *number_of_elements)
{
  node *curr, *prev = list_head->get_head(), *next;
  int delete_curr, delete_next, delete_head = 0;
  const char *curr_string, *next_string;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  if (!curr)
    {
      return list_head;
    }
  curr_string = curr->get_name ();
  if (!strcmp (curr_string, string))
    {
      delete_head = 1;
    }
  if (!strcmp (prev->get_name (), string))
    {
      delete_curr = 1;
    }
  else
    {
      delete_curr = 0;
    }

  while (curr)
    {
      next = curr->get_next();
      if (next)
        {
          next_string = next->get_name ();
        }
      else
        {
          if (delete_curr)
            {
              prev->delete_next ();
              (*number_of_elements)--;
            }
          break;
        }
      if (!strcmp (curr_string, string))
        {
          delete_next = 1;
        }
      else
        {
          delete_next = 0;
        }
      if (delete_curr || !strcmp (next_string, string))
        {
          prev->delete_next ();
          (*number_of_elements)--;
        }
      else
        {
          prev = curr;
        }
      curr = next;
      curr_string = next_string;
      delete_curr = delete_next;
    }
  if (delete_head)
    {
      list_head->delete_first ();
      (*number_of_elements)--;
    }

  return list_head;
}

list *solve27_1 (list *list_head, char *string, int *number_of_elements)
{
  node *curr, *prev = list_head->get_head(), *next;
  int delete_curr, delete_next, delete_head = 0;
  const char *curr_string, *next_string;
  size_t len_curr, len_next;
  if (!prev)
    {
      return list_head;
    }
  curr = prev->get_next ();
  if (!curr)
    {
      return list_head;
    }
  curr_string = curr->get_name ();
  len_curr = strlen (curr_string);
  if (strspn (curr_string, string) == len_curr)
    {
      delete_head = 1;
    }
  if (strspn (prev->get_name (), string) == strlen (prev->get_name ()))
    {
      delete_curr = 1;
    }
  else
    {
      delete_curr = 0;
    }

  while (curr)
    {
      next = curr->get_next();
      if (next)
        {
          next_string = next->get_name ();
          len_next = strlen (next_string);
        }
      else
        {
          if (delete_curr)
            {
              prev->delete_next ();
              (*number_of_elements)--;
            }
          break;
        }
      if (strspn (curr_string, string) == len_curr)
        {
          delete_next = 1;
        }
      else
        {
          delete_next = 0;
        }
      if (delete_curr || strspn (next_string, string) == len_next)
        {
          prev->delete_next ();
          (*number_of_elements)--;
        }
      else
        {
          prev = curr;
        }
      curr = next;
      curr_string = next_string;
      len_curr = len_next;
      delete_curr = delete_next;
    }
  if (delete_head)
    {
      list_head->delete_first ();
      (*number_of_elements)--;
    }

  return list_head;
}
