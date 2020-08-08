#include <stdio.h>
#include <stdlib.h>

int read (const char *name, double *x, double *y, int n);
int read (const char *name, double *x, double *y, double *dif, int n); //with differntials

void print_function (double *x, double *y, int n);

void return_error (int result, const char *name);

#define MAX_PRINTABLE_NUMBER 7
