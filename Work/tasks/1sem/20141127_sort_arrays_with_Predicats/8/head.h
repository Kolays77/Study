int read_array(const char *, double *, int);
void init_array(double *, int, int);
void print_array(double *, int);
int comparator(double, double);
void merge(double *,
           double *,
           int,
           int,
           double *,
           int (*)(double, double));
int merge_sort(double *,
               double *,
               int,
               int (*)(double, double));
