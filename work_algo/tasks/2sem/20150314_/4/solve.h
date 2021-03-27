double dot_prod(double* x, double* y, int n);
void matrixbycolumn_nn(double* A, double* x, double* x_ans, int n);
void add_col(double* x, double* y, int n);
void mult_by_const(double* x, double c, int n);
void add_constbycol(double* x, double* y, double c, int n);
double dotprod_Ax_Ax(double* A, double* x, int n);
double dotprod_Ax_x(double* A, double* x, int n);
void solve4(double* A, double* x0, double* b, double* x, double* r, int n, int m);