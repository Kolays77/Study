double function(double x0);
int make_d(double *x, double *y, double *f, int n);
int find_root(double *d,
			  int m,
              double (*f)(double),
              double eps,
              double *answer);
