#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "solve.h"
#include "matrix.h"

int main(int argc, char **argv)
{
    int n, m;
    double *A;
    double *x0, *x, *b, *r;
    double t;
    char *fname1 = 0, *fname2 = 0, *fname3 = 0;
    double res;
    if ((argc != 3 && argc != 6) || ((n = atoi(argv[1])) <= 0) || ((m = atoi(argv[2])) <= 0))
    {
        printf("Usage %s n m <file1 file2 file3>.\n", argv[0]);
        return 1;
    }
    if (argc == 6)
    {
        fname1 = argv[3];
        fname2 = argv[4];
        fname3 = argv[5];
    }
    if (!(A = (double*)malloc(n * n * sizeof(double))))
    {
        printf("Not enough memory.\n");
        return 2;
    }
    if (!(x0 = (double*)malloc(n * 1 * sizeof(double))))
    {
        printf("Not enough memory.\n");
        free(A);
        return 2;
    }
    if (!(b = (double*)malloc(n * 1 * sizeof(double))))
    {
        printf("Not enough memory.\n");
        free(A);
        free(x0);
        return 2;
    }
    if (!(x = (double*)malloc(n * 1 * sizeof(double))))
    {
        printf("Not enough memory.\n");
        free(A);
        free(x0);
        free(b);
        return 2;
    }
    if (!(r = (double*)malloc(n * 1 * sizeof(double))))
    {
        printf("Not enough memory.\n");
        free(A);
        free(x0);
        free(b);
        free(x);
        return 2;
    }
    if (fname1)
    {
        int ret;
        ret = read_matrix(fname1, A, n, n);
        if (ret < 0)
        {
            switch(ret)
            {
                case -1: printf("Cannot open %s.\n", fname1); break;
                case -2: printf("Cannot read %s.\n", fname1); break;
                default: printf("Unknown error %d in %s", ret, fname1);
            }
            free(A);
            free(x0);
            free(b);
            free(x);
            free(r);
            return 3;
        }
        ret = read_matrix(fname2, x0, n, 1);
        if (ret < 0)
        {
            switch(ret)
            {
                case -1: printf("Cannot open %s.\n", fname2); break;
                case -2: printf("Cannot read %s.\n", fname2); break;
                default: printf("Unknown error %d in %s", ret, fname2);
            }
            free(A);
            free(x0);
            free(b);
            free(x);
            free(r);
            return 3;
        }
        ret = read_matrix(fname3, b, n, 1);
        if (ret < 0)
        {
            switch(ret)
            {
                case -1: printf("Cannot open %s.\n", fname3); break;
                case -2: printf("Cannot read %s.\n", fname3); break;
                default: printf("Unknown error %d in %s", ret, fname3);
            }
            free(A);
            free(x0);
            free(b);
            free(x);
            free(r);
            return 3;
        }
    }
    else
    {
        init_matrix(A, n, n);
        init_matrix(x0, n, 1);
        init_matrix(b, n, 1);
    }
    print_matrix(A, n, n);
    print_matrix(x0, n, 1);
    t = clock();
    solve4(A, x0, b, x, r, n, m);
    t = (clock() - t) / CLOCKS_PER_SEC;
    print_matrix(x, n, 1);
    printf("Elapsed time: %.2f.\n", t);
    free(A);
    free(x0);
    free(b);
    free(x);
    free(r);
    return 0;
}
