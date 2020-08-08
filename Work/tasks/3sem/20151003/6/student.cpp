#include <string.h>
#include "student.h"

student::student (const char *initial_name,
                  int initial_value)
{
  init (initial_name, initial_value);
}

student::student (const student &initial_student)
{
  init (initial_student.name, initial_student.value);
}

student::~student ()
{
  if (name)
    {
      delete [] name;
    }
  name = 0;
  value = 0;
}

int student::init (const char *initial_name,
                   int initial_value)
{
  value = initial_value;
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
  return 0;
}

student &student::operator= (const student &right_hand_side)
{
  this->student::~student ();
  init (right_hand_side.name, right_hand_side.value);
  return *this;
}

int student::operator< (const student &right_hand_side) const
{
  if (value < right_hand_side.value)
    {
      return 1;
    }
  return 0;
}

int student::operator> (const student &right_hand_side) const
{
  if (value > right_hand_side.value)
    {
      return 1;
    }
  return 0;
}

void student::swap (student &student2)
{
  char *buffer_name;
  int buffer_value;
  buffer_name = student2.name;
  buffer_value = student2.value;
  student2.name = name;
  student2.value = value;
  name = buffer_name;
  value = buffer_value;
}
