int check_M(double *matrix,
             int n);
void product_MV(double *matrix,
               double *vector,
               double *product_vector,
               int n);
void product_VN(double *vector1,
                int n,
                double tau);
void product_DV(double *diagonal,
                double *vector,
                int n);
void product_DM(double *diagonal,
                double *matrix,
                double *product,
                int n);
double dot_product_sqr(double *vector,
                       int n);
double dot_product(double *vector1,
                   double *vector2,
                   int n);
void sum_V(double *vector1,
           double *vector2,
           double *vector3,
           int n);
void dif_V(double *vector1,
           double *vector2,
           double *vector3,
           int n);
int solve(double *matrix,
             double *vector,
             double *vector2,
             int n,
             int m,
             double tau,
             double *vector_answer);
