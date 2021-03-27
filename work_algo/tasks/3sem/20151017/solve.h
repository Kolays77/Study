#include "student_list.h"

student_list *make_new_list1 (student_list *, student *);

student_list *make_shift2 (student_list *, int);

student_list *delete_less (student_list *, int *);

student_list *delete_more (student_list *head, int *n);

student_list *delete_more_k (student_list *head, int k, int *n);

student_list *delete_dicreasing (student_list *head, int *n);

student_list *delete_increasing (student_list *head, int *n);

student_list *delete_monotonic (student_list *head, int k, int *n);

student_list *delete_sublist (student_list *list, student_list *sublist, int *len_list, int *len_sublist);
void delete_segment (student_list *list, student_node *start, student_node *curr, int *len_list, int *len_sublist);
