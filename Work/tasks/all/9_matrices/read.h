#include <cstdio>
#include <cstdlib>
#include <cmath>

int read_matrix (const char *, double *, int row, int column);
double init_element (int, int);
void init_matrix (double *, int row, int column);
void print_matrix (double *, int row, int column);

int read_vector (const char *name, double *vector, int n);
void init_vector (double *vector, int length);
double init_element (int idx);
void print_vector (double *vector, int n);

void return_error (int result, const char *name);

#define MAX_PRINTABLE_NUMBER 7
