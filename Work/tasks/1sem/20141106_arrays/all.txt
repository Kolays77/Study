#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

int main(void)
{
  int n, key;
  int result;
  double *array;
  double counter_of_time;
  const char *name = "a.txt";

  printf("Input n: ");
  if (!(scanf("%d", &n) == 1))
    {
      printf("Input Error\n");
      return -2;
    }
  if (n <= 0)
    {
      printf("n must be more than 0!\n");
      return 1;
    }
  printf("Input key: ");
  if (!(scanf("%d", &key) == 1))
    {
      printf("Input Error\n");
      return -2;
    }

  if (!(array = (double *) malloc(n * sizeof(double))))
    {
      printf("Not enough memory\n");
      return -5;
    }

  if (key == 0)
    {
      result = read_array(name, array, n);
      if (result < 0)
        {
          switch (result)
            {
            case (-1):
              {
                printf("Cannot open %s\n", name);
                break;
              }
            case (-2):
              {
                printf("Cannot read %s\n", name);
                break;
              }
            case (-3):
              {
                printf("%s is empty\n", name);
                break;
              }
            default:
              {
                printf("Unknown error %d in %s\n", result, name);
              }
            }
          free(array);
          return -1;
        }
      n = result;
    }
  else
    {
      init_array(array, n, key);
    }

  print_array(array, n);
  counter_of_time = clock();
  rewrite_array(array, n);
  counter_of_time = (clock() - counter_of_time) / CLOCKS_PER_SEC;
  printf("NEW "); print_array(array, n);
  printf("Elapsed = %.4lf\n", counter_of_time);
  free(array);
  return 0;
}



int read_array(const char *name, double *array, int max_n)
{
  FILE *fp;
  int idx;
  if (!(fp = fopen(name, "r")))
    {
      return -1;
    }
  for (idx = 0; idx < max_n; idx++)
    {
      if (fscanf(fp, "%lf", array + idx) != 1)
        {
          if (!feof(fp))
            {
              fclose(fp);
              return -2;
            }
          fclose(fp);
          if (idx == 0)
            {
              return -3;
            }
          printf("The number of elements in %s is less than n\nNumber of elements is %d\n", name, idx);
          return idx;
        }
    }
  fclose(fp);
  return idx;
}

void print_array(double *array, int n)
{
  int idx, m = (n > MAX_PRINTABLE_NUMBER ? MAX_PRINTABLE_NUMBER : n);
  printf("ARRAY:\n");
  for (idx = 0; idx < m; idx++)
    {
      printf("array[%2d] = %lf\n", idx, array[idx]);
    }
  return;
}

void init_array(double *array, int length, int key)
{
  int idx;
  srand(key);
  for (idx = 0; idx < length; idx++)
    {
      array[idx] = rand();
    }
  return;
}



//TASK 1
int check_array(double *array, int length)
{
  int idx, middle = length / 2;
  for (idx = 0; idx < middle; idx++)
    {
      if (fabs(array[idx] - array[length - 1 - idx]) > EPS)
        {
          return 0;
        }
    }
  return 1;
}

//TASK 2
void rewrite_array(double *array, int length)
{
  int idx, middle = length / 2;
  double elem;
  for (idx = 0; idx < middle; idx++)
    {
      elem = array[idx];
      array[idx] = array[length - 1 - idx];
      array[length - 1 - idx] = elem;
    }
  return;
}

//TASK 3
void rewrite_array(double *array, int length)
{
  int idx, max_idx = length - 1;
  double prev_elem1 = array[0], prev_elem2 = array[0];
  for (idx = 1; idx < max_idx; idx++)
    {
      prev_elem1 = array[idx];
      array[idx] = (prev_elem2 + array[idx + 1]) / 2;
      prev_elem2 = prev_elem1;
    }
  return;
}

//TASK 4
void search_a_in_b(double *a, double *b, int n, int m)
{
  int idx_a, idx_b;
  for (idx_a = 0; idx_a < n; idx_a++)
    {
      for (idx_b = 0; idx_b < m; idx_b++)
        {
          if (fabs(a[idx_a] - b[idx_b]) < EPS)
            {
              a[idx_a] = 0;
              break;
            }
        }
    }
  return;
}

//TASK 5
void rewrite_array(double *array, int length, double x)
{
  int idx,
      idx_first_more = length,
      idx_first_less;
  double elem;

  for (idx = 0; idx < length; idx++)
    {
      if (array[idx] > x)
        {
          idx_first_more = idx;
          break;
        }
    }

  for (idx_first_less = idx_first_more; idx_first_less < length; idx_first_less++)
    {
      if (array[idx_first_less] > x)
        {
          continue;
        }
      elem = array[idx_first_less];
      array[idx_first_less] = array[idx_first_more];
      array[idx_first_more] = elem;
      idx_first_more++;
    }
  return;
}
//TASK 5
void swap_elements_for_qsort (double *array, int n, double barrier)
{
  int idx1 = 0, idx2 = n - 1;
  double tmp;
  while (idx1 <= idx2)
    {
      while (idx1 < n && array[idx1] < barrier)
        {
          idx1++;
        }
      while (idx2 >= 0 && array[idx2] > barrier)
        {
          idx2--;
        }
      if (idx1 <= idx2)
        {
          tmp = array[idx1];
          array[idx1] = array[idx2];
          array[idx2] = tmp;
          idx1++;
          idx2--;
        }
    }
  return;
}

//TASK 6
void rewrite_array(double *array, int length)
{
  int idx, max_idx = length - 1;
  double element = array[max_idx];
  for (idx = max_idx; idx > 0; idx--)
    {
      array[idx] = array[idx - 1];
    }
  array[0] = element;
  return;
}

//TASK 7
int rewrite_array(double *array, int length, int k)
{
  int idx, max_idx = length - 1;
  double *copy;
  k = k % length;
  if (k < 0)
    {
      k += length;
    }
  if (!(copy = (double *) malloc(k * sizeof(double))))
    {
      return -1;
    }
  for (idx = 0; idx < k; idx++)
    {
      copy[idx] = array[length - k + idx];
    }
  for (idx = max_idx; idx >= k; idx--)
    {
      array[idx] = array[idx - k];
    }
  for (idx = 0; idx < k; idx++)
    {
      array[idx] = copy[idx];
    }
  free(copy);
  return 0;
}

//TASK 7
void cyclic_shift(double *array, int length)
{
  int idx, max_idx = length - 1;
  double element = array[max_idx];
  for (idx = max_idx; idx > 0; idx--)
    {
      array[idx] = array[idx - 1];
    }
  array[0] = element;
  return;
}

void rewrite_array(double *array, int n, int k)
{
  int cnt;
  k = k % n;
  if (k < 0)
    {
      k += n;
    }
  for (cnt = 0; cnt < k; cnt++)
    {
      cyclic_shift(array, n);
    }
  return;
}


//TASK 7
int gcd (int a, int b)
{
  int tmp;
  if (a > b)
    {
      tmp = a; a = b; b = tmp;
    }
  while (a > 0)
    {
      tmp = b % a;
      b = a; a = tmp;
    }
  return b;
}

void cyclic_shift (double *array, int n, int shift)
{
  int len_of_circles, cnt_circles;
  shift = shift % n;
  if (shift < 0)
    {
      shift += n;
    }
  if (shift == 0)
    {
      return;
    }

  cnt_circles = gcd (n, shift);
  len_of_circles = n / cnt_circles;

  for (int num_of_circle = 0; num_of_circle < cnt_circles; num_of_circle++)
    {
      int curr_idx = num_of_circle, prev_idx = curr_idx;
      double start_element = array[curr_idx];
      for (int cnt = 1; cnt < len_of_circles; cnt++)
        {
          prev_idx = (curr_idx - shift) % n;
          if (prev_idx < 0)
            {
              prev_idx += n;
            }
          array[curr_idx] = array[prev_idx];
          curr_idx = prev_idx;
        }
      array[curr_idx] = start_element;
    }
}


//TASK 8
int count(double *array, const char *name, int n)
{
  FILE *fp;
  int cnt = 0, idx = 0;
  double elem;
  if (!(fp = fopen(name, "r")))
    {
      return -1;
    }
  while (fscanf(fp, "%lf", &elem) == 1)
    {
      if (fabs(elem - array[idx]) < EPS)
        {
          idx++;
          if (idx == n)
            {
              cnt++;
              idx = 0;
            }
        }
      else
        {
          idx = 0;
        }
    }
  if (!feof(fp))
    {
      fclose(fp);
      return -2;
    }
  fclose(fp);
  return cnt;
}

//TASK 8
int count_subsections (double *array, const char *file_name, int n)
{
  FILE *fp;
  int cnt_subsections = 0, curr_length = 0;
  double curr_element;
  if (!(fp = fopen (file_name, "r")))
    {
      return -1;
    }

  while (fscanf (fp, "%lf", &curr_element) == 1)
    {
      if (fabs (curr_element - array[curr_length]) > EPS)
        {
          curr_length = find_shift (array, curr_length, curr_element);
        }
      else
        {
          curr_length++;
          while (curr_length == n)
            {
              cnt_subsections++;
              if (fscanf (fp, "%lf", &curr_element) != 1)
                {
                  if (feof (fp))
                    {
                      fclose (fp);
                      return cnt_subsections;
                    }
                  fclose (fp);
                  return -2;
                }
              curr_length = find_shift (array, curr_length, curr_element);
            }
        }
    }
  if (!feof(fp))
    {
      fclose(fp);
      return -2;
    }
  fclose(fp);
  return cnt_subsections;
}

int find_shift (double *array, int curr_length, double element)
{
  int shift, idx = 0, was_change = 0;
  for (shift = 1; shift <= curr_length; shift++)
    {
      for (idx = 0; shift + idx < curr_length; idx++)
        {
          if (fabs (array[idx] - array[idx + shift]) > EPS)
            {
              break;
            }
        }
      if (idx + shift == curr_length && fabs (array[idx] - element) < EPS)
        {
          was_change = 1;
          curr_length -= (shift - 1);
          break;
        }
    }
  if (!was_change)
    {
      return 0;
    }
  return curr_length;
}

//TASK 9
int count(double *a, double *b, const char *name, int n)
{
  FILE *fp;
  int cnt = 0, idx = 0;
  double elem;
  if (!(fp = fopen(name, "r")))
    {
      return -1;
    }
  while (idx < n - 1 && fscanf(fp, "%lf", &elem) == 1)
    {
      b[idx] = elem;
      idx++;
    }
  while (fscanf(fp, "%lf", &elem) == 1)
    {
      b[n - 1] = elem;
      for (idx = 0; idx < n; idx++)
        {
          if (fabs(a[idx] - b[idx]) > EPS)
            {
              break;
            }
        }
      if (idx == n)
        {
          cnt++;
        }

      for (idx = 1; idx < n; idx++)
        {
          b[idx - 1] = b[idx];
        }
    }
  if (!feof(fp))
    {
      fclose(fp);
      return -2;
    }
  fclose(fp);
  return cnt;
}

//TASK 10
int rewrite_array(double *array, int length, double x)
{
  int idx, number_of_less = 0;
  for (idx = 0; idx < length; idx++)
    {
      if (array[idx] < x)
        {
          number_of_less++;
          continue;
        }
      array[idx - number_of_less] = array[idx];
    }
  for (idx = length - number_of_less; idx < length; idx++)
    {
      array[idx] = 0;
    }
  return length - number_of_less;
}
