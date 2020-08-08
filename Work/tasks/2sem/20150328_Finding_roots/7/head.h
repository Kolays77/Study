double function(double x0);
double differential(double x);
int find_root(double x0,
              double (*f)(double),
              double eps,
              double *answer);
