#include "tree.h"
#define MAX_LEVEL 5
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

int b_tree_node::create_student (student *initial_student)
{
  int i, j;

  for (i = 0; i < num_of_elements; i++)
    if (initial_student < students[i])
      break;

  for (j = num_of_elements; j > i; j--)
    students[j] = students[j - 1];

  students[i] = initial_student;
  num_of_elements++;

  return i;
}

void b_tree_node::attach_student (student *attach)
{
  int i, j;

  for (i = 0; i < num_of_elements; i++)
    if (attach < students[i])
      break;

  for (j = num_of_elements; j > i; j--)
    students[j] = students[j - 1];

  students[i] = attach;
  num_of_elements++;
}

int b_tree_node::get_num_of_node()
{
  int i;

  for (i = 0; i <= parent->num_of_elements; i++)
    if (parent->child[i] == this)
      return i;

  return 0;
}

b_tree::b_tree()
{
  root = 0;
}

//void b_tree::delete_tree( b_tree_node **root )
//{
//  int i;

//  while ((*root) && (*root)->child[0])
//    for (i = 0; i <= (*root)->num_of_elements; i++)
//      delete_tree(&((*root)->child[i]));

//  delete *root;
//  *root = 0;
//}

b_tree::~b_tree()
{
  //  delete_tree(&root);
  root = 0;
}

int b_tree::read( const char *filename )
{
  FILE *fp;
  char name[BUF_LEN];
  int value;
  student *new_student;

  if (!(fp = fopen(filename, "r")))
    return 0;

  while (fscanf(fp, "%s %d", name, &value) == 2)
    {
      new_student = new student (name, value);
      insert_student (new_student);
    }

  if(!feof(fp))
    return 0;

  fclose(fp);
  return 1;
}

b_tree_node *b_tree::search_node (student *searching_student)
{
  int i;//, old_num_of_node = -1;
  b_tree_node *curr = root;

  while (1)
    {
      for (i = 0; i < curr->get_num_of_elements (); i++)
        if (searching_student < curr->get_student (i))
          {
            if (curr->get_child (i))
              {
                //                old_num_of_node = i;
                curr = curr->get_child (i);
                i--;
                break;
              }
            else
              {
                return curr;
              }
          }

      if (i == curr->get_num_of_elements ())
        {
          if (curr->get_child (curr->get_num_of_elements ()))
            {
              curr = curr->get_child (curr->get_num_of_elements ());
            }
          else
            {
              return curr;
            }
        }
    }

  return 0;
}

void b_tree::insert_student (student *new_student)
{
  int i;

  if (!root)
    {
      root = new b_tree_node;
      root->create_student (new_student);
      root->set_student (0, new_student);
      return;
    }
  else
    {
      int num_of_node = 0;
      b_tree_node *found = search_node (new_student);

      for (i = 0; i < found->get_num_of_elements (); i++)
        {
          if (found->get_student (i) == new_student)
            {
              //add to group
              found->set_student (i, new_student);
              return;
            }
        }

      //create new group
      if (found->get_num_of_elements () < 2 * MAX_NUM - 1)
        {
          found->set_student (found->create_student (new_student), new_student);
        }
      else
        {
          int need_attach_child = 0, is_first = 1;
          //rebalance
          b_tree_node *curr = found, *new_node, *child = 0;
          student *curr_student, *tmp;

          curr_student = new student (new_student->get_name(), new_student->get_value());
          //inserted_node = curr_student->insert_student (new_student);

          while (1)
            {
              if (curr->get_num_of_elements () >= 2 * MAX_NUM - 1)
                {
                  new_node = new b_tree_node;

                  for (i = MAX_NUM; i < 2 * MAX_NUM - 1; i++)
                    new_node->set_student (i - MAX_NUM, curr->get_student (i));
                  new_node->set_num_of_elements (MAX_NUM - 1);
                  curr->set_num_of_elements (MAX_NUM - 1);

                  for (i = MAX_NUM; i < 2 * MAX_NUM + 1; i++)
                    {
                      new_node->set_child (i - MAX_NUM, curr->get_child (i));
                      if (curr->get_child (i))
                        curr->get_child (i)->set_parent (new_node);
                    }

                  tmp = curr->get_student (MAX_NUM - 1);

                  if (curr_student > curr->get_student (MAX_NUM - 1))
                    {
                      new_node->attach_student (new_student);
                      if (need_attach_child)
                        {
                          int j = 0;
                          while (j < new_node->get_num_of_elements () && new_node->get_child (j)->get_num_of_elements () && child->get_student (0) &&
                                 child->get_student (0) > new_node->get_child (j)->get_student (new_node->get_child (j)->get_num_of_elements () - 1))
                            j++;

                          for (i = new_node->get_num_of_elements (); i > j; i--)
                            new_node->set_child (i, new_node->get_child (i - 1));

                          new_node->set_child (j, child);
                          child->set_parent (new_node);
                          need_attach_child = 0;
                        }
                    }
                  else
                    {
                      curr->attach_student (curr_student);
                      if (need_attach_child)
                        {
                          int j = 0;
                          while (j < curr->get_num_of_elements () && curr->get_child (j)->get_num_of_elements () != 0 && child->get_student (0) &&
                                 child->get_student (0) > curr->get_child (j)->get_student (curr->get_child (j)->get_num_of_elements () - 1))
                            j++;

                          for (i = curr->get_num_of_elements (); i > j; i--)
                            curr->set_child (i, curr->get_child (i - 1));

                          curr->set_child (j, child);
                          child->set_parent (curr);
                          need_attach_child = 0;
                        }
                    }

                  curr_student = tmp;

                  if (curr->get_parent ())
                    {
                      new_node->set_parent (curr->get_parent ());

                      //evaluate new num_of_node
                      if (is_first)
                        is_first = 0;
                      else
                        num_of_node = curr->get_num_of_node();

                      if (curr->get_parent ()->get_num_of_elements () == 2 * MAX_NUM - 1)
                        {
                          child = new_node;
                          need_attach_child = 1;
                          curr = curr->get_parent ();
                          continue;
                        }

                      //shift kids
                      for (i = curr->get_parent ()->get_num_of_elements (); i > num_of_node; i--)
                        curr->get_parent ()->set_child (i + 1, curr->get_parent ()->get_child (i));

                      curr->get_parent ()->set_child (num_of_node + 1, new_node);
                      curr = curr->get_parent ();
                    }
                  else
                    {
                      b_tree_node *new_head;
                      new_head = new b_tree_node;
                      new_head->set_child (0, curr);
                      curr->set_parent (new_head);
                      new_head->set_child (1, new_node);
                      new_node->set_parent (new_head);

                      root = curr = new_head;
                    }
                }
              else
                {
                  curr->attach_student (curr_student);
                  break;
                }
            }
        }
    }
}

void b_tree::print (b_tree_node *root, int level)
{
  if (level > MAX_LEVEL)
    {
      return;
    }
  if (root)
    {

      for (int idx = 0; idx < root->get_num_of_elements(); idx++)
        {
          for (int i = 0; i < level; i++)
            {
              printf ("      ");
            }
          printf ("[%s %d]\n", root->get_student (idx)->get_name(), root->get_student (idx)->get_value());
        }
      for (int idx = 0; idx < root->get_num_of_elements() + 1; idx++)
        {
          print(root->get_child (idx), level + 1);
        }
    }
}

//void b_tree::print (int regularity, FILE *fp, b_tree_node *curr_root)
//{
//  int i;

//  if (!curr_root)
//    return;

//  for (i = 0; i < curr_root->get_num_of_elements (); i++)
//    curr_root->groups[i]->print (regularity, fp); //print_student

//  for (i = 0; i <= curr_root->get_num_of_elements (); i++)
//    print(regularity, fp, curr_root->child[i]);
//}
