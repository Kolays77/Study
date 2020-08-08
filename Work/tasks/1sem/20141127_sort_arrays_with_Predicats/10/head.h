int read_array(const char *, double *, int);
void init_array(double *, int, int);
void print_array(double *, int);
int comparator(double, double);
void heapsorted(double *,
                int,
                int (*cmp) (double, double));
void sift_up(double *,
             int,
             int (*cmp) (double, double));
void sift_down(double *,
               int,
               int,
               int (*cmp) (double, double));
void swap(double *, double *);
