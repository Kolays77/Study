#include <cstdio>
#include <cstdlib>
#include <cmath>

#define EPS 1e-32

void transponation1 (double *matrix, int n);
void sum_matrix_with_trans2 (double *matrix, int n);
void dif_matrix_with_trans3 (double *matrix, int n);


int swap_rows4 (double *matrix, int rows, int columns, int first_row, int second_row);
int swap_coloumns5 (double *matrix, int rows, int columns, int first_column, int second_column);
int solve6 (double *matrix, int rows, int columns, int first_row, int second_row, double factor);

void product_MV7 (double *matrix, double *vector, int rows, int columns);
void product_MM8 (double *matrix1, double *matrix2, double *matrix_answer, int rows, int columns, int columns2);


double dot_product (double *vector1,
                    double *vector2,
                    int size_of_vector);
void product_MV (double *matrix, double *vector, double *vector_answer,
                 int rows, int columns);

int solve9 (double *matrix,
            double *vector,
            double *vector2,
            int size,
            int idx_of_member,
            double *lambda);

void sum_V (double *vector1,
            double *vector2,
            double *vector_sum,
            int size);
void dif_V (double *vector1,
            double *vector2,
            double *vector_dif,
            int size);
void product_VN (double *vector,
                 int size,
                 double tau);

void solve10 (double *matrix,
              double *vector,
              double *vector2,
              int size,
              int idx_of_member,
              double tau,
              double *vector_answer);

void dif_VN (double *vector1, double *vector2, double *vector_answer, int size, double tau);


#define MAX_ITER 1000
int solve11 (double *matrix,
             double *vector,
             double *vector2,
             int size,
             int idx_of_member,
             double *vector_answer);

int solve12 (double *matrix,
             double *vector,
             double *vector2,
             int size,
             int idx_of_member,
             double *vector_answer);

int check_M (double *matrix,
             int size);

void product_invDV (double *matrix_diag,
                    double *vector,
                    int size);
int solve13 (double *matrix,
             double *vector,
             double *vector2,
             int size,
             int idx_of_member,
             double tau,
             double *vector_answer);

void find_V_from_lower (double *matrix,
                        double *vector,
                        int size);
int solve14 (double *matrix,
             double *vector,
             double *vector2,
             int size,
             int idx_of_member,
             double tau,
             double *vector_answer);

void find_V_from_upper (double *matrix,
                        double *vector,
                        int size);
int solve15 (double *matrix,
             double *vector,
             double *vector2,
             int size,
             int idx_of_member,
             double tau,
             double *vector_answer);

double solve16 (double *matrix, int rows, int columns);

double solve17 (double *matrix, int rows, int columns);

double solve18 (double *matrix, double *vector_b, double *vector_x, int rows, int columns);

double solve19 (double *matrix, double *vector_b, double *vector_x, int rows, int columns);

double solve20 (double *matrix1, double *matrix2, int rows, int columns);

double solve21 (double *matrix1, double *matrix2, int rows, int columns);
