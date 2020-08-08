#include <cstdio>
#include <cstdlib>
#include <cmath>


#define EPS 1e-16
#define MAX_TASK_NUMBER 6

void replace_by_average (double *array, int n); //task1

void swap_elements_for_qsort (double *array, int n, double barrier); //task2

void shift_right (double *array, int n); //task3

int gcd (int a, int b);
void cyclic_shift (double *array, int n, int shift); //task4

int find_shift (double *array, int curr_length, double element);
int count_subsections (double *array, const char *file_name, int n); //task5

int delete_little_elememts (double *array, int length, double barrier); //task6
