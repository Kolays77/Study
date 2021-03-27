#include "tree.h"

/*void delete_tree (tree_node *root)
{
  if (root->get_left())
    {
      delete_tree (root->get_left());
    }
  if (root->get_right())
    {
      delete_tree (root->get_right());
    }
  delete root;
  root = 0;
  return;
}*/



void add_new_student (tree_node *root, student *new_student)
{
  tree_node *curr_node = root;
  int idx = 0;
  while (1)
    {
      idx = binsearch (curr_node->get_students (), curr_node->get_number_of_students (), new_student);
      if (!curr_node->get_descedants ())
        {
          insert_new_student ();
          break;
        }
      else
        {
          curr_node = curr_node->get_descedant(idx);
        }
    }
}

void insert_new_student (student new_student, tree_node *curr_node)
{
  student new_parent;
  tree_node *old_curr_node;
  student *right_students = 0, *left_students = 0, *new_right_students = 0, *new_left_students = 0;
  int m = curr_node->get_m ();
  int was_student = 0, was_student_right = 0, i;
  right_students = new student [2 * m];
  left_students = new student [2 * m];
  new_right_students = new student [2 * m];
  new_left_students = new student [2 * m];
  int number_of_students_in_curr_node = 0;
  while (true)
    {
      idx = binsearch (curr_node->get_students(), curr_node->get_number_of_students(), new_student);
      if (curr_node->get_number_of_students() != 2 * m)
        {
          number_of_students_in_curr_node = curr_node->get_number_of_students ();
          for (int i = number_of_students_in_curr_node - 1; i >= idx; i++)
            {
              curr_node->set_student (curr_node->get_student (i), i + 1);
            }
          curr_node->set_student (new_student, idx);

          if (curr_node->get_descedants())
            {
              tree_node *new_left = 0, *new_right = 0;
              new_left = tree_node (left_students, old_curr_node->get_descedants(), m);
              new_right = tree_node (right_students, old_curr_node->get_descedant (m), m);
              for (i = curr_node->get_number_of_students(); i > idx + 1; i++)
                {
                  curr_node->set_descedant (curr_node->get_descedant (i - 1), i);
                }
              curr_node->set_descedant (new_left, idx);
              curr_node->set_descedant (new_right, idx + 1);
            }
          break;
        }
      else
        {
          was_student = 0;
          for (i = 0; i < number_of_students_in_curr_node; i++)
            {
              if (i + was_student < m)
                {
                  if (i == idx)
                    {
                      new_left_students[i] = new_student;
                      was_student = 1;
                    }
                  if (i + was_student == m)
                    {
                      new_parent = curr_node->get_student (i);
                      was_student = 1;
                    }
                  else
                    {
                      new_left_students[i + was_student] = curr_node->get_student (i);
                    }
                }
              else if (i + was_student > m)
                {
                  if (i == idx)
                    {
                      new_right_students[i - m - 1] = new_student;
                      was_student = 1;
                      was_student_right = 1;
                    }
                  new_right_students[i - m - 1 + was_student_right] = curr_node->get_student (i);
                }
              else
                {
                  if (!was_student)
                    {
                      if (i == idx)
                        {
                          new_parent = new_student;
                          was_student = 1;
                          new_right_students[0] = curr_node->get_student (i);
                        }
                      else
                        {
                          new_parent = curr_node->get_student (i);
                        }
                    }
                  else
                    {
                      new_parent = curr_node->get_student (i);
                    }
                }
            }
          for (i = 0; i < m; i++)
            {
              curr_node->set_student (new_left_students[i], i);
            }
          for (i = 0; i < m; i++)
            {
              curr_node->set_student (new_right_students[i], i + m);
            }

          right_students = new_right_students;
          left_students = new_left_students;
          old_curr_node = curr_node;
          curr_node = curr_node->get_parent ();
          new_student = parent;
        }
    }
}

int binsearch (student *array, int length, student *new_element)
{
  int left = 0, right = length, middle;
  while (right != left)
    {
      middle = (left + right) / 2;
      if (array[middle] < new_element)
        {
          left = middle + 1;
        }
      else
        {
          right = middle;
        }
    }
  return left;
}

//          if (idx < m)
//            {
//              i = 0;
//              left_students[idx]= new_student;
//              for (i = 0; i < idx; i++)
//                {
//                  left_students[i] = curr_node->get_student (i);
//                }
//              for (i = idx + 1; i < m; i++)
//                {
//                  left_students[i] = curr_node->get_student (i - 1);
//                }
//              for (i = m + 1; i < number_of_students_in_curr_node; i++)
//                {
//                  right_students[i - m - 1] = curr_node->get_student (i);
//                }
//              new_parent = curr_node->get_student (m);
//            }
//          else if (idx > m)
//            {
//              right_students[idx - m - 1]= new_student;
//              for (i = 0; i < m; i++)
//                {
//                  left_students[i] = curr_node->get_student (i);
//                }
//              for (i = m + 1; i < idx; i++)
//                {
//                  right_students[i - m] = curr_node->get_student (i);
//                }
//              for (i = idx; i < number_of_students_in_curr_node && i != idx; i++)
//                {
//                  right_students[i - m - 1] = curr_node->get_student (i - 1);
//                }
//              new_parent = curr_node->get_student (m);
//            }
//          else
//            {
//              for (i = 0; i < m; i++)
//                {
//                  left_students[i] = curr_node->get_student (i);
//                }
//              for (i = m; i < number_of_students_in_curr_node; i++)
//                {
//                  right_students[i - m - 1] = curr_node->get_student (i);
//                }
//              new_parent = new_student;
//            }
//          tree_node *new_left_node = new tree_node (left_student, 0, m, m);
//          tree_node *new_right_node = new tree_node (right_student, 0, m, m);

/*

int count_elements_in_tree (tree_node *root)
{
  int left = 0, right = 0;
  if (root->get_left())
    {
      left = count_elements_in_tree (root->get_left());
    }
  if (root->get_right())
    {
      right = count_elements_in_tree (root->get_right());
    }
  return left + right + 1;
}

int count_levels (tree_node *root)
{
  tree_node *left = root->get_left(), *right = root->get_right();
  int left_levels = 0, right_levels = 0;
  if (left)
    {
      left_levels = count_levels (left);
    }
  if (right)
    {
      right_levels = count_levels (right);
    }
  if (left_levels > right_levels)
    {
      return left_levels + 1;
    }
  return right_levels + 1;
}*/
