#include "node.h"

node::node (const char *initial_name)
{
  init (initial_name);
  next = 0;
}

node::node (const node &initial_node)
{
  init (initial_node.name);
  next = initial_node.next;
}

node::~node ()
{
  if (name)
    {
      delete [] name;
    }
  name = 0;
  next = 0;
}

int node::init (const char *initial_name)
{
  if (initial_name)
    {
      name = new char [strlen (initial_name) + 1];
      if (name)
        {
          strcpy (name, initial_name);
        }
      else
        {
          return 1;
        }
    }
  else
    {
      name = 0;
    }
  return 0;
}

node &node::operator= (const node &right_hand_side)
{
  this->node::~node ();
  init (right_hand_side.name);

  next = right_hand_side.next;
  return *this;
}

int node::operator< (const node &right_hand_side) const
{
  if (strcmp (name, right_hand_side.name) < 0)
    {
      return 1;
    }
  return 0;
}
int node::operator> (const node &right_hand_side) const
{
  if (strcmp (name, right_hand_side.name) > 0)
    {
      return 1;
    }
  return 0;
}

int node::operator== (const node &right_hand_side) const
{
  if (strcmp (name, right_hand_side.name) == 0)
    {
      return 1;
    }
  return 0;
}

int node::operator!= (const node &right_hand_side) const
{
  if (strcmp (name, right_hand_side.name))
    {
      return 1;
    }
  return 0;
}
