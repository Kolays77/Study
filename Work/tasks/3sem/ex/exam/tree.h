#ifndef TREE_H
#define TREE_H

#endif // TREE_H

#ifndef _TREE_H_
#define _TREE_H_
#include <stdio.h>
class TreeNode
{
    public:
        int  value;
        int  balance;
        TreeNode *left,*right;
        TreeNode() { value = balance = 0; left = right = NULL; }
};

class  Tree
{
    public:
        TreeNode *root;

        Tree () { root = NULL; }

        ~Tree ();

        Tree (FILE *f);

};

void  T_Print (FILE *f, TreeNode *pos);
void solve (TreeNode *v);
void what_we_must_print (TreeNode *v);
void make_balance (TreeNode *v);

#endif



