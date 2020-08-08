#include "head.h"
#include "read.h"

void transponation1 (double *matrix, int n)
{
  double buffer;
  double *pointer1, *pointer2;
  for (int idx1 = 1; idx1 < n; idx1++)
    {
      pointer1 = matrix + idx1 * n;
      pointer2 = matrix + idx1;
      for (int idx2 = 0; idx2 < idx1; idx2++)
        {
          int idx_ = idx2 * n;
          buffer = pointer1[idx2];
          pointer1[idx2] = pointer2[idx_];
          pointer2[idx_] = buffer;
        }
    }
  return;
}

void sum_matrix_with_trans2 (double *matrix, int n)
{
  int idx_;
  double *pointer1, *pointer2;
  for (int idx1 = 1; idx1 < n; idx1++)
    {
      pointer1 = matrix + idx1 * n;
      pointer2 = matrix + idx1;
      for (int idx2 = 0; idx2 < idx1; idx2++)
        {
          idx_ = idx2 * n;
          pointer2[idx_] = pointer1[idx2] = (pointer1[idx2] + pointer2[idx_]) / 2;
        }
    }
  return;
}

void dif_matrix_with_trans3 (double *matrix, int n)
{
  double *pointer1, *pointer2;
  for (int idx1 = 1; idx1 < n; idx1++)
    {
      pointer1 = matrix + idx1 * n;
      pointer2 = matrix + idx1;
      for (int idx2 = 0; idx2 < idx1; idx2++)
        {
          int idx_ = idx2 * n;
          pointer2[idx_] = -(pointer1[idx2] = (pointer1[idx2] - pointer2[idx_]) / 2);
        }
      pointer1[idx1] = 0;
    }
  return;
}

int swap_rows4 (double *matrix, int rows, int columns, int first_row, int second_row)
{
  double buffer;
  double *pointer1 = matrix + columns * first_row,
      *pointer2 = matrix + columns * second_row;

  if (first_row >= rows || second_row >= rows
      || first_row < 0 || second_row < 0)
    {
      return -1;
    }
  for (int idx = 0; idx < columns; idx++)
    {
      buffer = pointer1[idx];
      pointer1[idx] = pointer2[idx];
      pointer2[idx] = buffer;
    }
  return 0;
}

int swap_coloumns5 (double *matrix, int rows, int columns, int first_column, int second_column)
{
  int cur_idx = 0;
  double *pointer1 = matrix + first_column,
      *pointer2 = matrix + second_column,
      buffer;
  if (first_column >= columns || second_column >= columns
      || first_column < 0 || second_column < 0)
    {
      return -1;
    }
  for (int idx = 0; idx < rows; idx++)
    {
      buffer = pointer1[cur_idx];
      pointer1[cur_idx] = pointer2[cur_idx];
      pointer2[cur_idx] = buffer;
      cur_idx += columns;
    }
  return 0;
}

int solve6 (double *matrix, int rows, int columns, int first_row, int second_row, double factor)
{
  double *pointer1 = matrix + columns * first_row,
      *pointer2 = matrix + columns * second_row;

  if (first_row >= rows || second_row >= rows
      || first_row < 0 || second_row < 0)
    {
      return -1;
    }
  for (int idx = 0; idx < columns; idx++)
    {
      pointer2[idx] += pointer1[idx] * factor;
    }
  return 0;
}


void product_MV7 (double *matrix, double *vector, int rows, int columns)
{
  double buffer;
  double *pointer_M = matrix;

  for (int idx1 = 0; idx1 < rows; idx1++)
    {
      buffer = 0;
      for (int idx2 = 0; idx2 < columns; idx2++)
        {
          buffer += (pointer_M[idx2] * vector[idx2]);
        }
      matrix[idx1] = buffer;
      pointer_M += columns;
    }
  return;
}

void product_MM8 (double *matrix1, double *matrix2, double *matrix_answer, int rows, int columns, int columns2)
{
  double buffer;
  double *pointer1 = matrix1,
      *pointer2 = matrix2,
      *pointer_answer = matrix_answer;

  for (int idx_ = 0; idx_ < rows; idx_++)
    {
      for (int idx1 = 0; idx1 < columns2; idx1++)
        {
          buffer = 0;
          for (int idx2 = 0; idx2 < columns; idx2++)
            {
              buffer += (pointer1[idx2] * pointer2[idx2 * columns2]);
            }
          (pointer_answer++)[0] = buffer;
          pointer2++;
        }
      pointer1 += columns;
      pointer2 = matrix2;
    }
  return;
}


double dot_product (double *vector1,
                    double *vector2,
                    int size_of_vector)
{
  double result = 0;
  for (int idx = 0; idx < size_of_vector; idx++)
    {
      result += vector1[idx] * vector2[idx];
    }
  return result;
}

void product_MV (double *matrix, double *vector, double *vector_answer,
                 int rows, int columns)
{
  double buffer;
  double *pointer_M = matrix;

  for (int idx1 = 0; idx1 < rows; idx1++)
    {
      buffer = 0;
      for (int idx2 = 0; idx2 < columns; idx2++)
        {
          buffer += (pointer_M[idx2] * vector[idx2]);
        }
      vector_answer[idx1] = buffer;
      pointer_M += columns;
    }
  return;
}

int solve9 (double *matrix,
            double *vector,
            double *vector2,
            int size,
            int idx_of_member,
            double *lambda)
{
  double *tmp;
  for (int idx = 0; idx < idx_of_member; idx++)
    {
      if (idx % 2 == 0)
        {
          product_MV (matrix, vector, vector2, size, size);
        }
      else
        {
          product_MV (matrix, vector2, vector, size, size);
        }
    }
  if (idx_of_member % 2 == 0)
    {
      tmp = vector;
      vector = vector2;
      vector2 = tmp;
    }
  *lambda = dot_product (vector, vector, size);
  if (fabs (*lambda) < EPS)
    {
      return -1;
    }
  *lambda = dot_product (vector2, vector, size) / *lambda;
  return 0;
}


void sum_V (double *vector1,
            double *vector2,
            double *vector_sum,
            int size)
{
  for (int idx = 0; idx < size; idx++)
    {
      vector_sum[idx] = vector2[idx] + vector1[idx];
    }
  return;
}

void dif_V (double *vector1,
            double *vector2,
            double *vector_dif,
            int size)
{
  int idx;
  for (idx = 0; idx < size; idx++)
    {
      vector_dif[idx] = vector1[idx] - vector2[idx];
    }
  return;
}

void product_VN (double *vector,
                 int size,
                 double tau)
{
  for (int idx = 0; idx < size; idx++)
    {
      vector[idx] *= tau;
    }
  return;
}

void dif_VN (double *vector1, double *vector2, double *vector_answer, int size, double tau)
{
  for (int idx = 0; idx < size; idx++)
    {
      vector_answer[idx] = vector1[idx] - tau * vector2[idx];
    }
}

void solve10 (double *matrix,
              double *vector,
              double *vector2,
              int size,
              int idx_of_member,
              double tau,
              double *vector_answer)
{
  double *tmp;
  for (int idx = 0; idx < idx_of_member; idx++)
    {
      product_MV (matrix, vector, vector_answer, size, size);   // vector_answer = matrix * vector            = A * x_{k-1}
      dif_V (vector2, vector_answer, vector_answer, size);      // vector_answer = vector2 - vector_answer    = b - A * x_{k-1}
      product_VN (vector_answer, size, tau);                    // vector_answer = vector_answer * tau        *= tau
      sum_V (vector_answer, vector, vector_answer, size);       // vector_answer = vector_answer + vector     += x_{k-1}

      tmp = vector_answer;
      vector_answer = vector;
      vector = tmp;
    }
  if (idx_of_member % 2 == 0)
    {
      for (int idx = 0; idx < size; idx++)
        {
          vector_answer[idx] = vector[idx];
        }
    }
  return;
}


int solve11 (double *matrix,
             double *vector,
             double *vector2,
             int size,
             int idx_of_member,
             double *vector_answer)
{
  double tau, dot_prod = 0, *buffer;

  if (!(buffer = new double [size]))
    {
      return -2;
    }

  for (int idx = 0; idx < size; idx++)
    {
      vector_answer[idx] = vector[idx];
    }

  product_MV (matrix, vector, buffer, size, size);      // buffer = matrix * vector         = A * x_0
  dif_V (buffer, vector2, buffer, size);                // buffer = buffer - vector2    r_0 = A * x_0 - b

  for (int idx = 0; idx < idx_of_member; idx++)
    {
      product_MV (matrix, buffer, vector, size, size);              // vector = matrix * buffer     = A * r_{k-1}
      dot_prod = dot_product (vector, vector, size);                //                    tau       = (Ar_{k-1}, Ar_{k-1})
      if (fabs (dot_prod) < EPS)
        {
          return -1;
        }
      tau = dot_product (buffer, buffer, size) / dot_prod;          // tau = (r_{k-1}, r_{k-1}) / (Ar_{k-1}, Ar_{k-1})
      dif_VN (vector_answer, buffer, vector_answer, size, tau);     /* vector_answer = vector_answer - buffer * tau
                                                                               x_{k} = x_{k-1} - tau * r_{k-1}      */
      dif_VN (buffer, vector, buffer, size, tau);                   /* buffer = buffer - vector
                                                                               r_{k} = r_{k-1} - tau * Ar_{k-1}     */
    }
  delete [] buffer;
  return 0;
}

int solve12 (double *matrix,
             double *vector,
             double *vector2,
             int size,
             int idx_of_member,
             double *vector_answer)
{
  double tau, dot_prod = 0, *buffer;

  if (!(buffer = new double [size]))
    {
      return -2;
    }

  for (int idx = 0; idx < size; idx++)
    {
      vector_answer[idx] = vector[idx];
    }

  product_MV (matrix, vector, buffer, size, size);      // buffer = matrix * vector         = A * x_0
  dif_V (buffer, vector2, buffer, size);                // buffer = buffer - vector2    r_0 = A * x_0 - b


  for (int idx = 0; idx < idx_of_member; idx++)
    {
      product_MV (matrix, buffer, vector, size, size);              // vector = matrix * buffer     = A * r_{k-1}
      dot_prod = dot_product (vector, vector, size);                //                    tau       = (Ar_{k-1}, Ar_{k-1})
      if (fabs (dot_prod) < EPS)
        {
          return -1;
        }
      tau = dot_product (vector, buffer, size) / dot_prod;          // tau = (Ar_{k-1}, r_{k-1}) / (Ar_{k-1}, Ar_{k-1})
      dif_VN (vector_answer, buffer, vector_answer, size, tau);     /* vector_answer = vector_answer - buffer * tau
                                                                               x_{k} = x_{k-1} - tau * r_{k-1}      */
      dif_VN (buffer, vector, buffer, size, tau);                   /* buffer = buffer - vector
                                                                               r_{k} = r_{k-1} - tau * Ar_{k-1}     */
    }
  delete [] buffer;
  return 0;
}

int check_M (double *matrix,
             int size)
{
  int square_size = size * size, diag_shift = size + 1;
  for (int idx = 0; idx < square_size; idx += diag_shift)
    {
      if (fabs (matrix[idx]) < EPS)
        {
          return 0;
        }
    }
  return 1;
}

void product_invDV (double *matrix_diag,
                    double *vector,
                    int size)
{
  double *diag = matrix_diag;
  int diag_shift = size + 1;
  for (int idx = 0; idx < size; idx++)
    {
      vector[idx] /= diag[0];
      diag += diag_shift;
    }
  return;
}

int solve13 (double *matrix,
             double *vector,
             double *vector2,
             int size,
             int idx_of_member,
             double tau,
             double *vector_answer)
{
  double *tmp, *buffer;
  if (!(buffer = new double [size]))
    {
      return -2;
    }
  if (!check_M (matrix, size))
    {
      return -3;
    }
  for (int idx = 0; idx < idx_of_member; idx++)
    {
      product_MV (matrix, vector, vector_answer, size, size); // vector_answer = matrix * vector            = A * x_{k-1}
      dif_V (vector2, vector_answer, vector_answer, size);    // vector_answer = vector2 - vector_answer    = b - Ax_{k-1}
      product_VN (vector_answer, size, tau);                  // vector_answer = vector_answer * tau        *= tau
      product_invDV (matrix, vector_answer, size);            // vector_answer                              = D^{-1} * vector_answer
      sum_V (vector_answer, vector, vector_answer, size);     // vector_answer                              += x_{k-1}      => x_k
      tmp = vector_answer;
      vector_answer = vector;
      vector = tmp;
    }
  if (idx_of_member % 2 == 0)
    {
      for (int idx = 0; idx < size; idx++)
        {
          vector_answer[idx] = vector[idx];
        }
    }
  return 0;
}

int solve14 (double *matrix,
             double *vector,
             double *vector2,
             int size,
             int idx_of_member,
             double tau,
             double *vector_answer)
{
  double *pointer, cur_sum;
  for (int idx = 0; idx < size; idx++)
    {
      vector_answer[idx] = vector[idx];
    }
  for (int idx = 0; idx < idx_of_member; idx++)
    {
      product_MV (matrix, vector_answer, vector, size, size); // vector = matrix * vector_answer          = A * x_{k-1}
      dif_V (vector2, vector, vector, size);                  // vector = vector2 - vector                = b - Ax_{k-1}
      product_VN (vector, size, tau);                         // vector = tau * vector                    *= tau

      for (int idx_row = 0; idx_row < size; idx_row++)        // vector = L^{-1} * vector
        {
          pointer = matrix + idx_row * size;
          cur_sum = vector[idx_row];
          for (int idx_col = 0; idx_col < idx_row; idx_col++)
            {
              cur_sum -= pointer[idx_col] * vector[idx_col];
            }
          if (fabs (pointer[idx_row]) < EPS)
            {
              return -1;
            }
          vector[idx_row] = cur_sum / pointer[idx_row];
        }
      sum_V (vector, vector_answer, vector_answer, size);     // vector_answer = vector + vector_answer   x_{k} = vector + x_{k-1}
    }
  return 0;
}


int solve15 (double *matrix,
             double *vector,
             double *vector2,
             int size,
             int idx_of_member,
             double tau,
             double *vector_answer)
{
  double *pointer, cur_sum;
  for (int idx = 0; idx < size; idx++)
    {
      vector_answer[idx] = vector[idx];
    }
  for (int idx = 0; idx < idx_of_member; idx++)
    {
      product_MV (matrix, vector_answer, vector, size, size); // vector = matrix * vector_answer          = A * x_{k-1}
      dif_V (vector2, vector, vector, size);                  // vector = vector2 - vector                = b - Ax_{k-1}
      product_VN (vector, size, tau);                         // vector = tau * vector                    *= tau

      for (int idx_row = size - 1; idx_row >= 0; idx_row--)   // vector = U^{-1} * vector
        {
          pointer = matrix + idx_row * size;
          cur_sum = vector[idx_row];
          for (int idx_col = size - 1; idx_col > idx_row; idx_col--)
            {
              cur_sum -= pointer[idx_col] * vector[idx_col];
            }
          if (fabs (pointer[idx_row]) < EPS)
            {
              return -1;
            }
          vector[idx_row] = cur_sum / pointer[idx_row];
        }
      sum_V (vector, vector_answer, vector_answer, size);     // vector_answer = vector + vector_answer   x_{k} = vector + x_{k-1}
    }
  return 0;
}

double solve16 (double *matrix, int rows, int columns)
{
  double max = 0, cur_sum = 0;
  double *pointer = matrix;

  for (int idx_row = 0; idx_row < rows; idx_row++)
    {
      cur_sum = 0;
      for (int idx_col = 0; idx_col < columns; idx_col++)
        {
          cur_sum += fabs (pointer[idx_col]);
        }
      if (cur_sum > max)
        {
          max = cur_sum;
        }
      pointer += columns;
    }
  return max;
}

double solve17 (double *matrix, int rows, int columns)
{
  double max = 0, cur_sum = 0;
  double *pointer = matrix;

  for (int idx_col = 0; idx_col < columns; idx_col++)
    {
      cur_sum = 0;
      pointer = matrix;
      for (int idx_row = 0; idx_row < rows; idx_row++)
        {
          cur_sum += fabs (pointer[idx_col]);
          pointer += columns;
        }
      if (cur_sum > max)
        {
          max = cur_sum;
        }
    }
  return max;
}

double solve18 (double *matrix, double *vector_b, double *vector_x, int rows, int columns)
{
  double cur_sum = 0, res = 0;
  double *pointer = matrix;

  for (int idx_row = 0; idx_row < rows; idx_row++)
    {
      cur_sum = 0;
      for (int idx_col = 0; idx_col < columns; idx_col++)
        {
          cur_sum += pointer[idx_col] * vector_x[idx_col];
        }
      res += fabs (cur_sum - vector_b[idx_row]);
      pointer += columns;
    }
  return res;
}

double solve19 (double *matrix, double *vector_b, double *vector_x, int rows, int columns)
{
  double cur_sum = 0, max = 0, res;
  double *pointer = matrix;

  for (int idx_row = 0; idx_row < rows; idx_row++)
    {
      cur_sum = 0;
      for (int idx_col = 0; idx_col < columns; idx_col++)
        {
          cur_sum += pointer[idx_col] * vector_x[idx_col];
        }
      res = fabs (cur_sum - vector_b[idx_row]);
      if (res > max)
        {
          max = res;
        }
      pointer += columns;
    }
  return max;
}

double solve20 (double *matrix1, double *matrix2, int rows, int columns)
{
  double cur_sum = 0, res = 0, max = 0;
  double *pointer1 = matrix1,
      *pointer2 = matrix2;
  for (int idx_row = 0; idx_row < rows; idx_row++)
    {
      res = 0;
      for (int idx_col = 0; idx_col < rows; idx_col++)
        {
          cur_sum = 0;
          pointer2 = matrix2;
          for (int idx_mid = 0; idx_mid < columns; idx_mid++)
            {
              cur_sum += pointer1[idx_mid] * pointer2[idx_col];
              pointer2 += columns;
            }
          if (idx_col == idx_row)
            {
              cur_sum--;
            }
          res += fabs (cur_sum);
        }
      if (res > max)
        {
          max = res;
        }
      pointer1 += columns;
    }
  return max;
}

double solve21 (double *matrix1, double *matrix2, int rows, int columns)
{
  double cur_sum = 0, res = 0, max = 0;
  double *pointer1 = matrix1,
      *pointer2 = matrix2;

  for (int idx_col = 0; idx_col < rows; idx_col++)
    {
      res = 0;
      pointer1 = matrix1;
      for (int idx_row = 0; idx_row < rows; idx_row++)
        {
          cur_sum = 0;
          pointer2 = matrix2;
          for (int idx_mid = 0; idx_mid < columns; idx_mid++)
            {
              cur_sum += pointer1[idx_mid] * pointer2[idx_col];
              pointer2 += rows;
            }
          if (idx_col == idx_row)
            {
              cur_sum--;
            }
          res += fabs (cur_sum);
          pointer1 += columns;
        }
      if (res > max)
        {
          max = res;
        }
    }
  return max;
}



/*
int solve15 (double *matrix,
             double *vector,
             double *vector2,
             int size,
             int idx_of_member,
             double tau,
             double *vector_answer)
{
  double *pointer, cur_sum;
  for (int idx = 0; idx < size; idx++)
    {
      vector_answer[idx] = vector[idx];
    }
  for (int idx = 0; idx < idx_of_member; idx++)
    {
      product_MV (matrix, vector_answer, vector, size, size);
      dif_V (vector2, vector, vector, size);
      product_VN (vector, size, tau);
      for (int idx_row = 0; idx_row < size; idx_row++)
        {
          cur_sum = 0;
          pointer = matrix + idx_row * size;
          for (int idx_col = idx_row; idx_col < size; idx_col++)
            {
              cur_sum += pointer[idx_col] * vector_answer[idx_col];
            }
          vector[idx_row] += cur_sum;
        }

      for (int idx_row = size - 1; idx_row >= 0; idx_row--)
        {
          pointer = matrix + idx_row * size;
          cur_sum = vector[idx_row];
          for (int idx_col = size - 1; idx_col > idx_row; idx_col--)
            {
              cur_sum -= pointer[idx_col] * vector_answer[idx_col];
            }
          if (fabs (pointer[idx_row]) < EPS)
            {
              return -1;
            }
          vector_answer[idx_row] = cur_sum / pointer[idx_row];
        }
    }
  return 0;
}
*/


/*
int solve14 (double *matrix,
             double *vector,
             double *vector2,
             int size,
             int idx_of_member,
             double tau,
             double *vector_answer)
{
  double *pointer, cur_sum;
  for (int idx = 0; idx < size; idx++)
    {
      vector_answer[idx] = vector[idx];
    }
  for (int idx = 0; idx < idx_of_member; idx++)
    {
      product_MV (matrix, vector_answer, vector, size, size); // vector = matrix * vector_answer          = A * x_{k-1}
      dif_V (vector2, vector, vector, size);                  // vector = vector2 - vector                = b - Ax_{k-1}
      product_VN (vector, size, tau);                         // vector = tau * vector                    *= tau
      for (int idx_row = 0; idx_row < size; idx_row++)  // vector += L * x_{k-1}
        {
          cur_sum = 0;
          pointer = matrix + idx_row * size;
          for (int idx_col = 0; idx_col <= idx_row; idx_col++)
            {
              cur_sum += pointer[idx_col] * vector_answer[idx_col];
            }
          vector[idx_row] += cur_sum;
        }

      for (int idx_row = 0; idx_row < size; idx_row++) // vector_answer = L^{-1} * vector  => x_{k}
        {
          pointer = matrix + idx_row * size;
          cur_sum = vector[idx_row];
          for (int idx_col = 0; idx_col < idx_row; idx_col++)
            {
              cur_sum -= pointer[idx_col] * vector_answer[idx_col];
            }
          if (fabs (pointer[idx_row]) < EPS)
            {
              return -1;
            }
          vector_answer[idx_row] = cur_sum / pointer[idx_row];
        }
    }
  return 0;
}
*/
