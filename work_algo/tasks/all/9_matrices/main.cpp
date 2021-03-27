#include "head.h"
#include "read.h"

int main (int argc, char *argv[])
{
  char *file_name = 0, *file_name2 = 0, *file_name3 = 0;
  int task_number;
  int row = 0, column = 0, column2 = 0,
      size = 0, idx_of_member = 0;
  int result = 0;
  double *matrix = 0;

  if (argc < 2 || (task_number = atoi (argv[1])) < 0)
    {
      fprintf (stdout, "Cannot read [#]!\n");
      return 1;
    }

  if (task_number < 4)
    {
      if (argc != 3 && argc != 4)
        {
          fprintf (stdout, "Usage: %s [#] [n] [<file_name>]\n", argv[0]);
          return -1;
        }
      if ((row = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          return 1;
        }
      if (argc > 3)
        {
          file_name = argv[3];
        }
      column = row;
    }
  else if (task_number < 7)
    {
      if (argc != 4 && argc != 5)
        {
          fprintf (stdout, "Usage: %s [#] [n] [m] [<file_name>]\n", argv[0]);
          return -1;
        }
      if ((row = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          return 1;
        }
      if ((column = atoi (argv[3])) <= 0)
        {
          fprintf (stdout, "Cannot read [m]!\n");
          return 1;
        }
      if (argc > 4)
        {
          file_name = argv[4];
        }
    }
  else if (task_number == 7)
    {
      if (argc != 4 && argc != 6)
        {
          fprintf (stdout, "Usage: %s [#] [n] [m] [<file_matrix>] [<file_vector>]\n", argv[0]);
          return -1;
        }
      if ((row = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          return 1;
        }
      if ((column = atoi (argv[3])) <= 0)
        {
          fprintf (stdout, "Cannot read [m]!\n");
          return 1;
        }
      if (argc > 4)
        {
          file_name = argv[4];
          file_name2 = argv[5];
        }
    }
  else if (task_number == 8)
    {
      if (argc != 5 && argc != 7)
        {
          fprintf (stdout, "Usage: %s [#] [m] [n] [k] [<file_matrix1>] [<file_matrix2>]\n", argv[0]);
          return -1;
        }
      if ((row = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [m]!\n");
          return 1;
        }
      if ((column = atoi (argv[3])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          return 1;
        }
      if ((column2 = atoi (argv[4])) <= 0)
        {
          fprintf (stdout, "Cannot read [k]!\n");
          return 1;
        }
      if (argc > 5)
        {
          file_name = argv[5];
          file_name2 = argv[6];
        }
    }
  else if (task_number == 9)
    {
      if (argc != 6 && argc!= 4)
        {
          fprintf (stdout, "Usage: %s [#] [n] [m] [<file_matrix>] [<file_vector>]\n", argv[0]);
          return -1;
        }
      if ((size = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          return 1;
        }
      if ((idx_of_member = atoi (argv[3])) <= 0)
        {
          fprintf (stdout, "Cannot read [m]!\n");
          return 1;
        }
      if (argc == 6)
        {
          file_name = argv[4];
          file_name2 = argv[5];
        }
      row = column = size;
    }
  else if (task_number <= 15)
    {
      if (argc != 7 && argc!= 4)
        {
          fprintf (stdout, "Usage: %s [#] [n] [m] [<file_matrix>] [<file_vector>] [<file_vector2>]\n", argv[0]);
          return -1;
        }
      if ((size = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          return 1;
        }
      if ((idx_of_member = atoi (argv[3])) <= 0)
        {
          fprintf (stdout, "Cannot read [m]!\n");
          return 1;
        }
      if (argc == 7)
        {
          file_name = argv[4];
          file_name2 = argv[5];
          file_name3 = argv[6];
        }
      row = column = size;
    }
  else if (task_number <= 17)
    {
      if (argc != 5 && argc != 4)
        {
          fprintf (stdout, "Usage: %s [#] [n] [m] [<file_matrix>]\n", argv[0]);
          return -1;
        }
      if ((row = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [m]!\n");
          return 1;
        }
      if ((column = atoi (argv[3])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          return 1;
        }
      if (argc == 5)
        {
          file_name = argv[4];
        }
    }
  else if (task_number <= 19)
    {
      if (argc != 7 && argc!= 4)
        {
          fprintf (stdout, "Usage: %s [#] [m] [n] [<file_matrix>] [<file_vector_B>] [<file_vector_X>]\n", argv[0]);
          return -1;
        }
      if ((row = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [m]!\n");
          return 1;
        }
      if ((column = atoi (argv[3])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          return 1;
        }
      if (argc == 7)
        {
          file_name = argv[4];
          file_name2 = argv[5];
          file_name3 = argv[6];
        }
    }
  else
    {
      if (argc != 6 && argc!= 4)
        {
          fprintf (stdout, "Usage: %s [#] [m] [n] [<file_matrix>] [<file_matrix2>]\n", argv[0]);
          return -1;
        }
      if ((row = atoi (argv[2])) <= 0)
        {
          fprintf (stdout, "Cannot read [m]!\n");
          return 1;
        }
      if ((column = atoi (argv[3])) <= 0)
        {
          fprintf (stdout, "Cannot read [n]!\n");
          return 1;
        }
      if (argc == 6)
        {
          file_name = argv[4];
          file_name2 = argv[5];
        }
    }

  matrix = new double [row * column];
  if (!matrix)
    {
      fprintf (stdout, "Not enough memory!\n");
      return 2;
    }
  if (file_name)
    {
      result = read_matrix (file_name, matrix, row, column);
      if (result < 0)
        {
          return_error (result, file_name);
          delete [] matrix;
          return 3;
        }
    }
  else
    {
      init_matrix (matrix, row, column);
    }
  print_matrix (matrix, row, column);

  switch (task_number)
    {
    case 1:
      {
        transponation1 (matrix, row);
        print_matrix (matrix, row, column);
        break;
      }

    case 2:
      {
        sum_matrix_with_trans2 (matrix, row);
        print_matrix (matrix, row, column);
        break;
      }

    case 3:
      {
        dif_matrix_with_trans3 (matrix, row);
        print_matrix (matrix, row, column);
        break;
      }

    case 4:
      {
        int idx1, idx2;
        fprintf (stdout, "Input [idx1] and [idx2]:  ");
        if (fscanf (stdin, "%d%d", &idx1, &idx2) != 2)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        if (swap_rows4 (matrix, row, column, idx1, idx2) != 0)
          {
            fprintf (stdout, "[idx1] and [idx2] must be less than [n] and more than 0!\n");
            break;
          }
        print_matrix (matrix, row, column);
        break;
      }

    case 5:
      {
        int idx1, idx2;
        fprintf (stdout, "Input [idx1] and [idx2]:  ");
        if (fscanf (stdin, "%d%d", &idx1, &idx2) != 2)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        if (swap_coloumns5 (matrix, row, column, idx1, idx2) != 0)
          {
            fprintf (stdout, "[idx1] and [idx2] must be less than [m] and more than 0!\n");
            break;
          }
        print_matrix (matrix, row, column);
        break;
      }

    case 6:
      {
        int idx1, idx2;
        double factor;
        fprintf (stdout, "Input [idx1] and [idx2]:  ");
        if (fscanf (stdin, "%d%d", &idx1, &idx2) != 2)
          {
            fprintf (stdout, "Cannot read!\n");
            return 1;
          }
        fprintf (stdout, "Input [b]:  ");
        if (fscanf (stdin, "%lf", &factor) != 1)
          {
            fprintf (stdout, "Cannot read [b]!\n");
            return 1;
          }
        if (solve6 (matrix, row, column, idx1, idx2, factor) != 0)
          {
            fprintf (stdout, "[idx1] and [idx2] must be less than [n] and more than 0!\n");
            break;
          }
        print_matrix (matrix, row, column);
        break;
      }

    case 7:
      {
        double *vector;
        vector = new double [column];
        if (!vector)
          {
            fprintf (stdout, "Not enough memory!\n");
            return 1;
          }
        if (file_name2)
          {
            result = read_vector (file_name2, vector, column);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                return_error (result, file_name2);
                return 1;
              }
          }
        else
          {
            init_vector (vector, column);
          }

        print_vector (vector, column);
        product_MV7 (matrix, vector, row, column);
        print_vector (matrix, row);
        delete [] vector;
        break;
      }

    case 8:
      {
        double *matrix2, *matrix_answer;
        matrix2 = new double [column * column2];
        matrix_answer = new double [row * column2];
        if (!matrix2)
          {
            fprintf (stdout, "Not enough memory!\n");
            return 1;
          }
        if (file_name2)
          {
            result = read_matrix (file_name2, matrix2, column, column2);
            if (result < 0)
              {
                delete [] matrix;
                delete [] matrix2;
                delete [] matrix_answer;
                return_error (result, file_name2);
                return 1;
              }
          }
        else
          {
            init_matrix (matrix2, column, column2);
          }

        print_matrix (matrix2, column, column2);
        product_MM8 (matrix, matrix2, matrix_answer, row, column, column2);
        print_matrix (matrix_answer, row, column2);

        delete [] matrix2;
        delete [] matrix_answer;
        break;
      }

    case 9:
      {
        double *vector, *vector_answer = 0;
        double lambda;
        vector = new double [size];
        if (!vector)
          {
            fprintf (stdout, "Not enough memory!\n");
            return 1;
          }
        vector_answer = new double [size];
        if (!vector_answer)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            return 1;
          }
        if (file_name2)
          {
            result = read_vector (file_name2, vector, column);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector_answer;
                return_error (result, file_name2);
                return 1;
              }
          }
        else
          {
            init_vector (vector, column);
          }

        print_vector (vector, column);

        if (solve9 (matrix, vector, vector_answer,
                    size, idx_of_member, &lambda) < 0)
          {
            fprintf (stdout, "Cannot divide by 0!\n");
            return 1;
          }
        fprintf (stdout, "Lambda = %.3f\n", lambda);
        delete [] vector;
        delete [] vector_answer;
        break;
      }

    case 10:
      {
        double *vector, *vector2, *vector_answer = 0;
        double tau;
        fprintf (stdout, "Input [tau]: ");
        if (fscanf (stdin, "%lf", &tau) != 1)
          {
            fprintf (stdout, "Cannot read [tau]!\n");
            return -1;
          }
        if (fabs (tau) < EPS)
          {
            fprintf (stdout, "[tau] = 0!\n");
            return -1;
          }
        vector = new double [size];
        if (!vector)
          {
            fprintf (stdout, "Not enough memory!\n");
            return 1;
          }
        vector_answer = new double [size];
        if (!vector_answer)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            return 1;
          }
        vector2 = new double [size];
        if (!vector2)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            delete [] vector_answer;
            return 1;
          }
        if (argc == 7)
          {
            result = read_vector (file_name2, vector, size);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector2;
                delete [] vector_answer;
                return_error (result, file_name2);
                return 1;
              }

            result = read_vector (file_name3, vector2, size);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector2;
                delete [] vector_answer;
                return_error (result, file_name3);
                return 1;
              }
          }
        else
          {
            init_vector (vector, size);
            init_vector (vector2, size);
          }

        print_vector (vector, size);
        print_vector (vector2, size);

        solve10 (matrix, vector, vector2, size, idx_of_member, tau, vector_answer);
        fprintf (stdout, "ANSWER ");
        print_vector (vector_answer, size);
        delete [] vector;
        delete [] vector2;
        delete [] vector_answer;
        break;
      }

    case 11:
      {
        double *vector, *vector2, *vector_answer = 0;

        vector = new double [size];
        if (!vector)
          {
            fprintf (stdout, "Not enough memory!\n");
            return 1;
          }
        vector_answer = new double [size];
        if (!vector_answer)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            return 1;
          }
        vector2 = new double [size];
        if (!vector2)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            delete [] vector_answer;
            return 1;
          }
        if (argc == 7)
          {
            result = read_vector (file_name2, vector, size);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector2;
                delete [] vector_answer;
                return_error (result, file_name2);
                return 1;
              }

            result = read_vector (file_name3, vector2, size);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector2;
                delete [] vector_answer;
                return_error (result, file_name3);
                return 1;
              }
          }
        else
          {
            init_vector (vector, size);
            init_vector (vector2, size);
          }

        print_vector (vector, size);
        print_vector (vector2, size);

        if (solve11 (matrix, vector, vector2, size, idx_of_member, vector_answer) < 0)
          {
            fprintf (stdout, "Cannot solve!\n");
            delete [] vector;
            delete [] vector2;
            delete [] vector_answer;
            return 1;
          }
        fprintf (stdout, "ANSWER ");
        print_vector (vector_answer, size);
        delete [] vector;
        delete [] vector2;
        delete [] vector_answer;
        break;
      }

    case 12:
      {
        double *vector, *vector2, *vector_answer = 0;

        vector = new double [size];
        if (!vector)
          {
            fprintf (stdout, "Not enough memory!\n");
            return 1;
          }
        vector_answer = new double [size];
        if (!vector_answer)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            return 1;
          }
        vector2 = new double [size];
        if (!vector2)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            delete [] vector_answer;
            return 1;
          }
        if (argc == 7)
          {
            result = read_vector (file_name2, vector, size);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector2;
                delete [] vector_answer;
                return_error (result, file_name2);
                return 1;
              }

            result = read_vector (file_name3, vector2, size);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector2;
                delete [] vector_answer;
                return_error (result, file_name3);
                return 1;
              }
          }
        else
          {
            init_vector (vector, size);
            init_vector (vector2, size);
          }

        print_vector (vector, size);
        print_vector (vector2, size);

        if (solve12 (matrix, vector, vector2, size, idx_of_member, vector_answer) < 0)
          {
            fprintf (stdout, "Cannot solve!\n");
            delete [] vector;
            delete [] vector2;
            delete [] vector_answer;
            return 1;
          }
        fprintf (stdout, "ANSWER ");
        print_vector (vector_answer, size);
        delete [] vector;
        delete [] vector2;
        delete [] vector_answer;
        break;
      }

    case 13:
      {

        double *vector, *vector2, *vector_answer = 0;
        double tau;
        fprintf (stdout, "Input [tau]: ");
        if (fscanf (stdin, "%lf", &tau) != 1)
          {
            fprintf (stdout, "Cannot read [tau]!\n");
            return -1;
          }
        if (fabs (tau) < EPS)
          {
            fprintf (stdout, "[tau] = 0!\n");
            return -1;
          }
        vector = new double [size];
        if (!vector)
          {
            fprintf (stdout, "Not enough memory!\n");
            return 1;
          }
        vector_answer = new double [size];
        if (!vector_answer)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            return 1;
          }
        vector2 = new double [size];
        if (!vector2)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            delete [] vector_answer;
            return 1;
          }
        if (argc == 7)
          {
            result = read_vector (file_name2, vector, size);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector2;
                delete [] vector_answer;
                return_error (result, file_name2);
                return 1;
              }

            result = read_vector (file_name3, vector2, size);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector2;
                delete [] vector_answer;
                return_error (result, file_name3);
                return 1;
              }
          }
        else
          {
            init_vector (vector, size);
            init_vector (vector2, size);
          }

        print_vector (vector, size);
        print_vector (vector2, size);

        if (solve13 (matrix, vector, vector2, size, idx_of_member, tau, vector_answer) < 0)
          {
            fprintf (stdout, "Cannot solve!\n");
            delete [] vector;
            delete [] vector2;
            delete [] vector_answer;
            return 1;
          }
        fprintf (stdout, "ANSWER ");
        print_vector (vector_answer, size);
        delete [] vector;
        delete [] vector2;
        delete [] vector_answer;
        break;
      }

    case 14:
      {
        double *vector, *vector2, *vector_answer = 0;
        double tau;
        fprintf (stdout, "Input [tau]: ");
        if (fscanf (stdin, "%lf", &tau) != 1)
          {
            fprintf (stdout, "Cannot read [tau]!\n");
            return -1;
          }
        if (fabs (tau) < EPS)
          {
            fprintf (stdout, "[tau] = 0!\n");
            return -1;
          }
        vector = new double [size];
        if (!vector)
          {
            fprintf (stdout, "Not enough memory!\n");
            return 1;
          }
        vector_answer = new double [size];
        if (!vector_answer)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            return 1;
          }
        vector2 = new double [size];
        if (!vector2)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            delete [] vector_answer;
            return 1;
          }
        if (argc == 7)
          {
            result = read_vector (file_name2, vector, size);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector2;
                delete [] vector_answer;
                return_error (result, file_name2);
                return 1;
              }

            result = read_vector (file_name3, vector2, size);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector2;
                delete [] vector_answer;
                return_error (result, file_name3);
                return 1;
              }
          }
        else
          {
            init_vector (vector, size);
            init_vector (vector2, size);
          }

        print_vector (vector, size);
        print_vector (vector2, size);

        if (solve14 (matrix, vector, vector2, size, idx_of_member, tau, vector_answer) < 0)
          {
            fprintf (stdout, "Cannot solve!\n");
            delete [] vector;
            delete [] vector2;
            delete [] vector_answer;
            return 1;
          }
        fprintf (stdout, "ANSWER ");
        print_vector (vector_answer, size);
        delete [] vector;
        delete [] vector2;
        delete [] vector_answer;
        break;
      }

    case 15:
      {
        double *vector, *vector2, *vector_answer = 0;
        double tau;
        fprintf (stdout, "Input [tau]: ");
        if (fscanf (stdin, "%lf", &tau) != 1)
          {
            fprintf (stdout, "Cannot read [tau]!\n");
            return -1;
          }
        if (fabs (tau) < EPS)
          {
            fprintf (stdout, "[tau] = 0!\n");
            return -1;
          }
        vector = new double [size];
        if (!vector)
          {
            fprintf (stdout, "Not enough memory!\n");
            return 1;
          }
        vector_answer = new double [size];
        if (!vector_answer)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            return 1;
          }
        vector2 = new double [size];
        if (!vector2)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector;
            delete [] vector_answer;
            return 1;
          }
        if (argc == 7)
          {
            result = read_vector (file_name2, vector, size);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector2;
                delete [] vector_answer;
                return_error (result, file_name2);
                return 1;
              }

            result = read_vector (file_name3, vector2, size);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector;
                delete [] vector2;
                delete [] vector_answer;
                return_error (result, file_name3);
                return 1;
              }
          }
        else
          {
            init_vector (vector, size);
            init_vector (vector2, size);
          }

        print_vector (vector, size);
        print_vector (vector2, size);

        if (solve15 (matrix, vector, vector2, size, idx_of_member, tau, vector_answer) < 0)
          {
            fprintf (stdout, "Cannot solve!\n");
            delete [] vector;
            delete [] vector2;
            delete [] vector_answer;
            return 1;
          }
        fprintf (stdout, "ANSWER ");
        print_vector (vector_answer, size);
        delete [] vector;
        delete [] vector2;
        delete [] vector_answer;
        break;
      }

    case 16:
      {
        fprintf (stdout, "Answer = %.3f\n", solve16 (matrix, row, column));
        break;
      }

    case 17:
      {
        fprintf (stdout, "Answer = %.3f\n", solve17 (matrix, row, column));
        break;
      }

    case 18:
      {
        double *vector_b, *vector_x;

        vector_b = new double [row];
        if (!vector_b)
          {
            fprintf (stdout, "Not enough memory!\n");
            return 1;
          }
        vector_x = new double [column];
        if (!vector_x)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector_b;
            return 1;
          }

        if (argc == 7)
          {
            result = read_vector (file_name2, vector_b, row);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector_b;
                delete [] vector_x;
                return_error (result, file_name2);
                return 1;
              }

            result = read_vector (file_name3, vector_x, column);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector_b;
                delete [] vector_x;
                return_error (result, file_name3);
                return 1;
              }
          }
        else
          {
            init_vector (vector_b, row);
            init_vector (vector_x, column);
          }

        print_vector (vector_b, row);
        print_vector (vector_x, column);

        fprintf (stdout, "Answer = %.3f\n", solve18 (matrix, vector_b, vector_x, row, column));
        delete [] vector_b;
        delete [] vector_x;
        break;
      }

    case 19:
      {
        double *vector_b, *vector_x;

        vector_b = new double [row];
        if (!vector_b)
          {
            fprintf (stdout, "Not enough memory!\n");
            return 1;
          }
        vector_x = new double [column];
        if (!vector_x)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] vector_b;
            return 1;
          }

        if (argc == 7)
          {
            result = read_vector (file_name2, vector_b, row);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector_b;
                delete [] vector_x;
                return_error (result, file_name2);
                return 1;
              }

            result = read_vector (file_name3, vector_x, column);
            if (result < 0)
              {
                delete [] matrix;
                delete [] vector_b;
                delete [] vector_x;
                return_error (result, file_name3);
                return 1;
              }
          }
        else
          {
            init_vector (vector_b, row);
            init_vector (vector_x, column);
          }

        print_vector (vector_b, row);
        print_vector (vector_x, column);

        fprintf (stdout, "Answer = %.3f\n", solve19 (matrix, vector_b, vector_x, row, column));
        delete [] vector_b;
        delete [] vector_x;
        break;
      }

    case 20:
      {
        double *matrix2;
        matrix2 = new double [row * column];
        if (!matrix2)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] matrix;
            return 2;
          }
        if (file_name)
          {
            result = read_matrix (file_name, matrix2, column, row);
            if (result < 0)
              {
                return_error (result, file_name);
                delete [] matrix;
                delete [] matrix2;
                return 3;
              }
          }
        else
          {
            init_matrix (matrix2, column, row);
          }
        print_matrix (matrix2, column, row);
        fprintf (stdout, "Answer = %.3f\n", solve20 (matrix, matrix2, row, column));
        delete [] matrix2;
        break;
      }

    case 21:
      {
        double *matrix2;
        matrix2 = new double [row * column];
        if (!matrix2)
          {
            fprintf (stdout, "Not enough memory!\n");
            delete [] matrix;
            return 2;
          }
        if (file_name)
          {
            result = read_matrix (file_name, matrix2, column, row);
            if (result < 0)
              {
                return_error (result, file_name);
                delete [] matrix;
                delete [] matrix2;
                return 3;
              }
          }
        else
          {
            init_matrix (matrix2, column, row);
          }
        print_matrix (matrix2, column, row);
        fprintf (stdout, "Answer = %.3f\n", solve21 (matrix, matrix2, row, column));
        delete [] matrix2;
        break;
      }

    default:
      {
        fprintf (stdout, "There is no task with number [%d]!\n", task_number);
        break;
      }
    }

  delete [] matrix;
  return 0;
}
