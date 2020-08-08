#include "tree.h"

void make_balance (TreeNode *v)
{
  if (!v->left && !v->right)
    {
      v->balance = 0;
      return;
    }
  if (!v->right)
    {
      make_balance (v->left);
      if (v->value > 0) v->balance = v->left->balance +1;
      if (v->value < 0) v->balance = v->left->balance -1;
      return;
    }
  if (!v->left)
    {
      make_balance (v->right);
      if (v->value > 0) v->balance = v->right->balance +1;
      if (v->value < 0) v->balance = v->right->balance -1;
      return;
    }
  make_balance (v->left);
  make_balance (v->right);
  if (v->value > 0) v->balance = v->left->balance
      + v->right->balance +1;
  if (v->value < 0) v->balance = v->left->balance
      + v->right->balance -1;
  return;
}

int was[100];
void what_we_must_print (TreeNode *v)
{
  was[v->balance]++;
  if (!v->left && !v->right)
    {
      return;
    }
  if (!v->right)
    {
      what_we_must_print (v->left);
      return;
    }
}

void solve (TreeNode *v)
{
  make_balance (v);
  T_Print (stdout, v);
  what_we_must_print(v);
  int j;
  for (j = 0; j < 100; j++)
    if (was[j] ==1) printf("%d ", j);
  return;
}
















