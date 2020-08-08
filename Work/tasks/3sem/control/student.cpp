#include <string.h>
#include <cstdio>
#include "student.h"

student::student (const char *initial_name)
{
  init (initial_name);
}

student::~student ()
{
  if (name)
    {
      delete [] name;
    }
  name = 0;
}

int student::init (const char *initial_name)
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

student &student::operator= (const student &right_hand_side)
{
  this->student::~student ();
  init (right_hand_side.name);
  return *this;
}

int student::operator< (const student &right_hand_side) const
{
  int cmp = strcmp (name, right_hand_side.name);
  if (cmp < 0)
    {
      return 1;
    }
  return 0;
}
