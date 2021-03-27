#include "student_list.h"

void merge_sort (student_list *head);
student_node *merge (student_node *first, student_node *second, student_node *last);
student_node *get_cur_next (student_node *curr, int step);
