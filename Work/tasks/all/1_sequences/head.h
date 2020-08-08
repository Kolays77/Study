#include <cstdio>
#include <cstdlib>
#include <cmath>


#define EPS 1e-16
#define MAX 1e6

void return_error (int result, const char *name);

int count_maximums (const char *file_name); //task1
int count_local_maximums (const char *file_name); //task2
int characterize_sequence (const char *file_name); //task3
int is_fibonachi (const char* name); //task4
int is_reverse_fibonachi (const char* name); //task5
int check_two_sequences (const char *name1, const char *name2); //task6
int standard_deviation (const char *filename, double *deviation); //task7
int type_of_progression (const char *file_name); //task8
int get_indeces_of_maximums (const char *file_name, double *max, int *first, int *last); //task9
int get_indeces_of_barrier (const char *file_name, double barrier, int *first, int *last); //task10
