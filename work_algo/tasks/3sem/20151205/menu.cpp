#include "stack.h"
#include "stack_of_tree_node.h"

#define MAX_LENGTH 200

static stack *global_struct = 0;
static tree_node *cur_root = 0;
static stack_of_tree_node *parents = 0;

int string_to_int (char *string)
{
  if (!strcmp (string, "-1"))
    {
      return -1;
    }
  else if (!strcmp (string, "0"))
    {
      return 0;
    }
  else if (!strcmp (string, "1"))
    {
      return 1;
    }
  else if (!strcmp (string, "2"))
    {
      return 2;
    }
  else if (!strcmp (string, "3"))
    {
      return 3;
    }
  else if (!strcmp (string, "4"))
    {
      return 4;
    }
  else if (!strcmp (string, "5"))
    {
      return 5;
    }
  else if (!strcmp (string, "6"))
    {
      return 6;
    }
  else if (!strcmp (string, "7"))
    {
      return 7;
    }
  else if (!strcmp (string, "8"))
    {
      return 8;
    }
  else if (!strcmp (string, "9"))
    {
      return 9;
    }
  else if (!strcmp (string, "10"))
    {
      return 10;
    }
  else
    {
      return -100;
    }
}

void stack::menu ()
{
  char string_key[MAX_LENGTH];
  int key;
  char cur_name[MAX_LENGTH];
  int cur_value = 0;
  global_struct = this;
  parents = new stack_of_tree_node ();
  while (true)
    {
      fprintf (stdout, "Input key: ([0] - show menu; [-1] - exit)\n");
      if (scanf ("%s", string_key) != 1)
        {
          fprintf (stdout, "Cannot read key! Try again!\n");
          key = 0;
        }
      else
        {
          key = string_to_int (string_key);
        }
      switch (key)
        {
        case (-1):
          {
            delete parents;
            return;
          }
        case (0):
          {
            fprintf (stdout, "[0] - show menu;\n");
            fprintf (stdout, "[1] - print all;\n");
            fprintf (stdout, "[2] - print curr structure;\n");
            fprintf (stdout, "[3] - go into structure;\n");
            fprintf (stdout, "[4] - add;\n");
            fprintf (stdout, "[5] - delete;\n");

            fprintf (stdout, "[-1] - exit;\n");
            break;
          }
        case (1):
          {
            print ();
            break;
          }
        case (2):
          {
            print ();
            break;
          }
        case (3):
          {
            get_last()->menu ();
            break;
          }
        case (4):
          {
            fprintf (stdout, "Input student:\n");
            if (scanf ("%s", cur_name) != 1)
              {
                fprintf (stdout, "Cannot read name!\n");
                break;
              }
            if (scanf ("%d", &cur_value) != 1)
              {
                fprintf (stdout, "Cannot read value!\n");
                break;
              }
            stack_node *new_node = new stack_node ();
            queue_node *new_queue_node = new queue_node ();
            tree_node *new_tree_node = new tree_node ();
            new_tree_node->init (cur_name, cur_value);
            new_queue_node->set_root (new_tree_node);
            new_node->add (new_queue_node);
            add (new_node);
            break;
          }
        case (5):
          {
            if (!empty ())
              {
                pop ();
              }
            else
              {
                fprintf (stdout, "Stack is empty!\n");
              }
            break;
          }
        default:
          {
            fprintf (stdout, "No command for [key] = \'%s\'!\nTry agagin:\n", string_key);
          }
        }
      fprintf (stdout, "\n");
    }
}

void queue::menu ()//stack *global_structure)
{
  int key = 0;
  char cur_name[MAX_LENGTH];
  int cur_value = 0;
  char string_key[MAX_LENGTH];
  while (true)
    {
      fprintf (stdout, "Input key: ([0] - show menu; [-1] - exit)\n");
      if (scanf ("%s", string_key) != 1)
        {
          fprintf (stdout, "Cannot read key! Try again!\n");
          key = 0;
        }
      else
        {
          key = string_to_int (string_key);
        }
      switch (key)
        {
        case (-1):
          {
            return;
          }
        case (0):
          {
            fprintf (stdout, "[0] - show menu;\n");
            fprintf (stdout, "[1] - print all;\n");
            fprintf (stdout, "[2] - print curr structure;\n");
            fprintf (stdout, "[3] - go into structure;\n");
            fprintf (stdout, "[4] - add;\n");
            fprintf (stdout, "[5] - delete;\n");

            fprintf (stdout, "[-1] - exit;\n");
            break;
          }
        case (1):
          {
            global_struct->print();
            break;
          }
        case (2):
          {
            fprintf (stdout, "QUEUE OF TREES:\n");
            print ("");
            break;
          }
        case (3):
          {
            cur_root = get_top()->get_root();
            get_top()->menu ();
            break;
          }
        case (4):
          {
            fprintf (stdout, "Input student:\n");
            if (scanf ("%s", cur_name) != 1)
              {
                fprintf (stdout, "Cannot read name!\n");
                break;
              }
            if (scanf ("%d", &cur_value) != 1)
              {
                fprintf (stdout, "Cannot read value!\n");
                break;
              }
            queue_node *new_node = new queue_node ();
            tree_node *new_tree_node = new tree_node ();
            new_tree_node->init (cur_name, cur_value);
            new_node->set_root (new_tree_node);
            add (new_node);
            break;
          }
        case (5):
          {
            if (!empty ())
              {
                pop_left ();
              }
            else
              {
                fprintf (stdout, "Queue is empty!\n");
              }
            break;
          }
        default:
          {
            fprintf (stdout, "No command for [key] = \'%s\'!\nTry agagin:\n", string_key);
          }
        }
      fprintf (stdout, "\n");
    }
}

void tree::menu ()
{
  int key = 0;
  char cur_name[MAX_LENGTH];
  int cur_value = 0;
  tree_node *new_node = 0;
  char string_key[MAX_LENGTH];
  while (true)
    {
      if (!cur_root)
        {
          fprintf (stdout, "Tree is empty!\n");
          fprintf (stdout, "[4] - add;\n");
          fprintf (stdout, "[-1] - exit;\n");
          fprintf (stdout, "Input key:\n");

          if (scanf ("%s", string_key) != 1)
            {
              fprintf (stdout, "Cannot read key! Try again!\n");
              key = 0;
            }
          else
            {
              key = string_to_int (string_key);
              if (key != 4 && key != -1)
                {
                  fprintf (stdout, "No command for [key] = \'%s\'!\n\n", string_key);
                  continue;
                }
            }
        }
      else
        {
          if (cur_root->get_child())
            {
              cur_root->set_child (cur_root->get_child()->get_first());
            }
          fprintf (stdout, "Input key: ([0] - show menu; [-1] - exit)\n");
          if (scanf ("%s", string_key) != 1)
            {
              fprintf (stdout, "Cannot read key! Try again!\n");
              key = 0;
            }
          else
            {
              key = string_to_int (string_key);
            }
        }
      switch (key)
        {
        case (-1):
          {
            parents->clean();
            return;
          }
        case (0):
          {
            fprintf (stdout, "[0] - show menu;\n");
            fprintf (stdout, "[1] - print all;\n");
            fprintf (stdout, "[2] - print curr structure;\n");
            fprintf (stdout, "[4] - add;\n");
            fprintf (stdout, "[5] - delete all tree;\n");
            fprintf (stdout, "[6] - delete subtree;\n");
            fprintf (stdout, "[7] - goto child;\n");
            fprintf (stdout, "[8] - goto root;\n");
            fprintf (stdout, "[9] - goto brother;\n");
            fprintf (stdout, "[10] - goto parent;\n");
            fprintf (stdout, "[-1] - exit;\n");
            break;
          }
        case (1):
          {
            global_struct->print();
            break;
          }
        case (2):
          {
            fprintf (stdout, "TREE OF STUDENTS:\n");
            if (!cur_root)
              {
                printf ("No elements\n");
                break;
              }
            print (cur_root, 0, "");
            break;
          }
        case (4):
          {
            int add_to = 0, number_of_child = 0;
            if (!get_root())
              {
                fprintf (stdout, "Input student:\n");
                if (scanf ("%s", cur_name) != 1)
                  {
                    fprintf (stdout, "Cannot read name!\n");
                    break;
                  }
                if (scanf ("%d", &cur_value) != 1)
                  {
                    fprintf (stdout, "Cannot read value!\n");
                    break;
                  }
                new_node = new tree_node ();
                new_node->init (cur_name, cur_value);
                fprintf (stdout, "Input number:\n");
                if (scanf ("%d", &number_of_child) != 1)
                  {
                    fprintf (stdout, "Cannot read number!\n");
                    break;
                  }
                new_node->set_idx_of_child (number_of_child);
                set_root (new_node);
                cur_root = new_node;
                break;
              }
            fprintf (stdout, "Input to: ([0] - add child; [1] - add brother)\n");
            if (scanf ("%d", &add_to) != 1)
              {
                fprintf (stdout, "Cannot read!\n");
                break;
              }
            if (add_to != 0 && add_to != 1)
              {
                fprintf (stdout, "Value must be [0] or [1]!\n");
                break;
              }
            if (add_to == 0)
              {
                tree_node *cur_child = cur_root->get_child(), *prev_child = 0;

                fprintf (stdout, "Input number:\n");
                if (scanf ("%d", &number_of_child) != 1)
                  {
                    fprintf (stdout, "Cannot read number!\n");
                    break;
                  }

                fprintf (stdout, "Input student:\n");
                if (scanf ("%s", cur_name) != 1)
                  {
                    fprintf (stdout, "Cannot read name!\n");
                    break;
                  }
                if (scanf ("%d", &cur_value) != 1)
                  {
                    fprintf (stdout, "Cannot read value!\n");
                    break;
                  }
                new_node = new tree_node ();
                new_node->init (cur_name, cur_value);
                new_node->set_idx_of_child (number_of_child);
                if (!cur_child)
                  {
                    cur_root->set_child (new_node);
                    new_node->set_first (new_node);
                    break;
                  }
                for (; cur_child && cur_child->get_idx_of_child () <= number_of_child; prev_child = cur_child, cur_child = cur_child->get_next())
                  {}
                if (!prev_child)
                  {
                    cur_root->set_child (new_node);
                    new_node->set_first (new_node);
                    new_node->set_next (cur_child);
                    if (cur_child)
                      {
                        cur_child->set_prev (new_node);
                      }
                    else
                      {
                        new_node->set_next (0);
                      }
                    for (; cur_child; cur_child = cur_child->get_next())
                      {
                        cur_child->set_first (new_node);
                      }
                    break;
                  }
                if (number_of_child == prev_child->get_idx_of_child())
                  {
                    fprintf (stdout, "Child with this number is already exist!\n");
                    break;
                  }
                else
                  {
                    prev_child->set_next (new_node);
                    new_node->set_prev (prev_child);
                    new_node->set_next (cur_child);
                    if (cur_child)
                      {
                        cur_child->set_prev (new_node);
                      }
                    else
                      {
                        new_node->set_next (0);
                      }
                    new_node->set_first(prev_child->get_first());
                  }
              }
            else
              {
                tree_node *cur_brother = cur_root->get_first(), *prev_brother = 0;
                if (cur_root == get_root())
                  {
                    fprintf (stdout, "Cannot add brother to the root!\n");
                    break;
                  }
                fprintf (stdout, "Input number:\n");
                if (scanf ("%d", &number_of_child) != 1)
                  {
                    fprintf (stdout, "Cannot read number!\n");
                    break;
                  }
                fprintf (stdout, "Input student:\n");
                if (scanf ("%s", cur_name) != 1)
                  {
                    fprintf (stdout, "Cannot read name!\n");
                    break;
                  }
                if (scanf ("%d", &cur_value) != 1)
                  {
                    fprintf (stdout, "Cannot read value!\n");
                    break;
                  }
                new_node = new tree_node ();
                new_node->init (cur_name, cur_value);
                new_node->set_idx_of_child (number_of_child);
                for (; cur_brother && cur_brother->get_idx_of_child () <= number_of_child; prev_brother = cur_brother, cur_brother = cur_brother->get_next())
                  {}
                if (!prev_brother)
                  {
                    cur_brother->set_prev (new_node);
                    new_node->set_next (cur_root);
                    cur_brother->set_first (new_node);
                    new_node->set_first (new_node);
                    for (; cur_brother; cur_brother = cur_brother->get_next())
                      {
                        cur_brother->set_first (new_node);
                      }
                    break;
                  }
                if (number_of_child == prev_brother->get_idx_of_child())
                  {
                    fprintf (stdout, "Brother with this number is already exist!\n");
                    break;
                  }
                else
                  {
                    prev_brother->set_next (new_node);
                    new_node->set_prev (prev_brother);
                    new_node->set_next (cur_brother);
                    if (cur_brother)
                      {
                        cur_brother->set_prev (new_node);
                      }
                    else
                      {
                        new_node->set_next (0);
                      }
                    new_node->set_first(prev_brother->get_first());
                  }
              }
            break;
          }
        case (5):
          {
            this->tree::~tree();
            fprintf (stdout, "Tree has been deleted\n");
            this->set_root (0);
            return;
          }
        case (6):
          {
            if (!(cur_root->get_child ()))
              {
                fprintf (stdout, "There are no children!\n");
              }
            else
              {
                int num = 0;
                fprintf (stdout, "Input number:\n");
                if (scanf ("%d", &num) != 1)
                  {
                    fprintf (stdout, "Cannot read number!\n");
                    break;
                  }
                else
                  {
                    tree_node *cur_child = cur_root->get_child();
                    int idx = 0;
                    for (idx = cur_child->get_idx_of_child();
                         cur_child && idx <= num;
                         cur_child = cur_child->get_next())
                      {
                        idx = cur_child->get_idx_of_child();
                        if (idx == num)
                          {
                            break;
                          }
                      }
                    if (idx > num || !cur_child)
                      {
                        fprintf (stdout, "There is no children with [num] = %d\n", num);
                        break;
                      }
                    fprintf (stdout, "Tree with root [%s %d] has been deleted\n", cur_child->get_name(), cur_child->get_value());

                    if (cur_child->get_prev())
                      {
                        if (cur_child->get_next())
                          {
                            cur_child->get_prev()->set_next(cur_child->get_next());
                            cur_child->get_next()->set_prev(cur_child->get_prev());
                          }
                        else
                          {
                            cur_child->get_prev()->set_next(0);
                          }
                      }
                    else
                      {
                        for (tree_node *curr = cur_child->get_next(); curr; curr = curr->get_next())
                          {
                            curr->set_first (cur_child->get_next());
                          }
                        if (cur_child->get_next())
                          {
                            cur_root->set_child(cur_child->get_next());
                          }
                        else
                          {
                            cur_root->set_child(0);
                          }
                      }
                    delete_tree (cur_child);
                  }
              }
            break;
          }
        case (7):
          {
            if (!(cur_root->get_child ()))
              {
                fprintf (stdout, "There are no children!\n");
              }
            else
              {
                int num = 0;
                fprintf (stdout, "Input number:\n");
                if (scanf ("%d", &num) != 1)
                  {
                    fprintf (stdout, "Cannot read number!\n");
                    break;
                  }
                else
                  {
                    tree_node *cur_child = cur_root->get_child();
                    int idx = 0;
                    for (idx = cur_child->get_idx_of_child();
                         cur_child && idx <= num;
                         cur_child = cur_child->get_next())
                      {
                        idx = cur_child->get_idx_of_child();
                        if (idx == num)
                          {
                            fprintf (stdout, "TREE OF STUDENTS:\n");
                            print (cur_child, 0, "");
                            parents->add (cur_root);
                            cur_root = cur_child;
                            break;
                          }
                      }
                    if (idx > num || !cur_child)
                      {
                        fprintf (stdout, "There is no children with [num] = %d\n", num);
                        break;
                      }
                  }
              }
            break;
          }
        case (8):
          {
            cur_root = get_root();
            parents->clean ();
            break;
          }
        case (9):
          {
            if (!(cur_root->get_prev()) && !(cur_root->get_next()))
              {
                fprintf (stdout, "There are no brothers!\n");
              }
            else
              {
                int num = 0;
                fprintf (stdout, "Input number:\n");
                if (scanf ("%d", &num) != 1)
                  {
                    fprintf (stdout, "Cannot read number!\n");
                    break;
                  }
                else
                  {
                    tree_node *cur_child = cur_root->get_first();
                    int idx = 0;
                    for (idx = cur_child->get_idx_of_child();
                         cur_child && idx <= num;
                         cur_child = cur_child->get_next())
                      {
                        idx = cur_child->get_idx_of_child();
                        if (idx == num)
                          {
                            fprintf (stdout, "TREE OF STUDENTS:\n");
                            print (cur_child, 0, "");
                            cur_root = cur_child;
                            break;
                          }
                      }
                    if (idx > num || !cur_child)
                      {
                        fprintf (stdout, "There is no brother with [num] = %d\n", num);
                        break;
                      }
                  }
              }
            break;
          }
        case (10):
          {
            if (!parents->empty())
              {
                cur_root = parents->get_last();
                parents->pop();
              }
            else
              {
                fprintf (stdout, "There is no parent!\n");
              }
            break;
          }

        default:
          {
            fprintf (stdout, "No command for [key] = \'%s\'!\nTry agagin:\n", string_key);
          }
        }
      fprintf (stdout, "\n");
    }
}
