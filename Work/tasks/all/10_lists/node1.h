#ifndef NODE_H
#define NODE_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

class node
{
private:
  char *name;
  node *next;
public:
  node (const char *initial_name = 0);
  node (const node &initial_node);
  ~node ();

  int init (const char *initial_name = 0);

  node &operator= (const node &right_hand_side);

  const char *get_name () const
  {
    return (const char *) name;
  }
  node *get_next ()
  {
    return next;
  }

  int set_name (const char *new_name)
  {
    if (new_name)
      {
        name = new char [strlen (new_name) + 1];
        if (name)
          {
            strcpy (name, new_name);
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

  void set_next (node *new_next)
  {
    next = new_next;
  }

  int operator< (const node &right_hand_side) const;
  int operator> (const node &right_hand_side) const;
  int operator== (const node &right_hand_side) const;
  int operator!= (const node &right_hand_side) const;

};

#endif
