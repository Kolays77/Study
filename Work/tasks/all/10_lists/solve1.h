#include "list1.h"

int compare1 (node *elem, const char *string);
int compare3 (node *elem, const char *string);
int compare5 (node *elem, const char *string);
list *solve1 (list *list_head, const char *string, int (*cmp) (node *, const char *));

int compare7 (node *elem);
int compare9 (node *elem);
list *solve7 (list *list_head, int (*cmp)(node *));

int compare11 (node *elem);
int compare13 (node *elem);
list *solve11 (list *list_head, int (*cmp)(node *));

list *solve15 (list *list_head, const char *string, int (*cmp) (node *, const char *));

int compare21 (node *elem);
list *solve21 (list *list_head, int (*cmp) (node *));

int compare25 (node *elem, const char *string);
list *solve25 (list *list_head, const char *string, int (*cmp) (node *, const char *));
