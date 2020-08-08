#ifndef TREE_NODE_H
#define TREE_NODE_H

#include "student.h"

class tree_node
{
private:
  student *students;
  tree_node *descendants;
  int m;
  int number_of_students;
  tree_node *parent;
public:
  tree_node (const int new_m = 0)
  {
    m = 0;
    number_of_students = 0;
    descendants = 0;
    students = 0;
    parent = 0;
    if (new_m)
      {
        m = new_m;
        number_of_students = 0;
        descendants = new tree_node [2 *  m + 1];
        students = new student [2 * m];
      }
  }
  tree_node (student *new_student,  tree_node *new_descedants, int new_m, int new_number)
  {
    m = new_m;
    number_of_students = new_number;
    parent = 0;
    if (number_of_students)
      {
        students = new student [2 * m];
        descendants = new tree_node [2 * m + 1];
        students = new_student;
        descendants = new_descedants;
      }
    else
      {
        students = 0;
        descendants = 0;
      }
  }

  ~tree_node ()
  {
    if (!m)
      {
        delete [] descendants;
        delete [] students;
      }
    m = 0;
    number_of_students = 0;
    descendants = 0;
    students = 0;
  }

  student *get_students ()
  {
    if (number_of_students > 0)
      {
        return students;
      }
    else
      {
        return 0;
      }
  }
  student get_student (int idx)
  {
    if (number_of_students > idx)
      {
        return students[idx];
      }
    else
      {
        return 0;
      }
  }

  tree_node *get_descedants ()
  {
    if (number_of_students > 0)
      {
        return descendants;
      }
    else
      {
        return 0;
      }
  }

  tree_node *get_descedant (int idx)
  {
    if (number_of_students >= idx)
      {
        return descendants + idx;
      }
  }

  int get_m ()
  {
    return m;
  }

  int get_number_of_students ()
  {
    return number_of_students;
  }

  tree_node *get_parent ()
  {
    return parent;
  }

  void set_parent (tree_node *new_parent)
  {
    parent = new_parent;
  }

  void set_students (student *new_students)
  {
    students = new_students;
  }
  void set_student (student new_student, int idx)
  {
    students[idx] = new_student;
  }
  void set_descedant (tree_node new_descedant, int idx)
  {
    descendants[idx] = new_descedant;
  }
};

#endif
