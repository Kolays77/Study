int read_array(const char *, double *, int);
void print_array(double *, int);
void return_error(const char *, int); 
int comparator(double, double);
int check_array(double *, int, int (*cmp) (double, double));
void merge(double *,
           double *,
           int,
           int,
           double *, 
           int (*) (double, double));
