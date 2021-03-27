#include "list2.h"

int compare2 (node *elem, const char *string);
int compare4 (node *elem, const char *string);
int compare6 (node *elem, const char *string);
list *solve2 (list *list_head, const char *string, int (*cmp)(node *, const char *));

int compare8 (node *elem);
int compare10 (node *curr);
list *solve8 (list *list_head, int (*cmp) (node *));

int compare12 (node *elem);
int compare14 (node *elem);
list *solve12 (list *list_head, int (*cmp) (node *));

list *solve16 (list *list_head, const char *string, int (*cmp) (node *, const char *));

int compare22 (node *elem);
int compare24 (node *elem);
list *solve22 (list *list_head, int (*cmp) (node *));

int compare26 (node *elem, const char *string);
list *solve26 (list *list_head, const char *string, int (*cmp) (node *, const char *));

/*
list *solve26 (list *list_head, char *string, int *number_of_elements);
list *solve27 (list *list_head, char *string, int *number_of_elements);
*/
