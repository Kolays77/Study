#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>


#define EPS 1e-16
#define MAX_TASK_NUMBER 10

void swap (double *a, double *b);

int is_increasing (double *array, int length);
int binsearch (double *array, int length, double new_element); //task1


void merge (double *a,
            double *b,
            int len_a,
            int len_b,
            double *result); //task2

int merge_union (double *a,
                 double *b,
                 int len_a,
                 int len_b,
                 double *result); //task3

void bubble_sort (double *array, int length); //task4

void find_sort (double *array, int length); //task5

void insertion_sort (double *array, int length); // task6

void binary_insertion_sort (double *array, int length); //task7

void merge_sort (double *a, double *b, int length); //task8

void quick_sort (double *array, int length); //task9

void sift_up (double *binary_tree, int position);
void sift_down (double *binary_tree, int position, int length);
void heap_sort (double *array, int length); //task10
