void product_MV(double *matrix,
             double *vector,
             double *product_vector,
             int n);
double dot_product(double *vector,
                   int n);
void sum_V(double *vector1,
           double *vector2,
           double *vector3,
           int n);
void dif_V(double *vector1,
           double *vector2,
           double *vector3,
           int n);
void product_VN(double *vector1,
                int n,
                double tau);
int solve(double *matrix,
             double *vector,
             double *vector2,
             int n,
             int m,
             double *vector_answer);
