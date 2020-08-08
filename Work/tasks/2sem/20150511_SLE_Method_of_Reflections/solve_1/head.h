double norm2(double *matrix, int n);
double norm_matrix(double *matrix1, double *matrix2, int n);

void product_VN(double *vector,
                int n,
                double tau,
                double *result_vector);
void dif_V(double *vector1,
           double *vector2,
           double *result_vector,
           int n);
double dot_product(double *vector1,
                   double *vector2,
                   int n);
void product_UV(double *vectorX,
                double *vectorY,
                double *result_vector,
                int n);
void product_UM(double *vectorX,
                double *matrix,
                double *buffer_vector,
                int n,
                int current_n,
                int num_clolumns);
int return_matrix(double *matrix, double *addition, double *x, int n);
int reverse_move(double *matrix, double *addition, int n, double *buffer);
void print_vector(double *vector, int n);
void transposition(double *matrix, int n);
