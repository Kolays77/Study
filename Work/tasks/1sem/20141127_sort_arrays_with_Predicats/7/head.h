int read_array(const char *, double *, int);
void init_array(double *, int, int);
void print_array(double *, int);
int comparator(double, double);
int binsearch(double *,
              int,
              double,
              int (*)(double, double));
void binary_insertion_sort(double *,
                           int,
                           int (*)(double, double)); 
