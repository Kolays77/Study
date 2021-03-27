#include <stdio.h>
#include <stdlib.h>

int read (const char *name, double *array, int n);
void init_array (double *array, int n);
double init_element (int idx);

void print_array (double *, int);

void return_error (int result, const char *name);
int count_subsections (double *array, const char *file_name, int n);

#define MAX_PRINTABLE_NUMBER 7
