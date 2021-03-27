#include "head.h"

void replace_by_average (double *array, int n)
{
  double prev_element = array[0], curr_element = array[1], next_element = 0;

  for (int idx = 2; idx < n; idx++)
    {
      next_element = array[idx];
      array[idx - 1] = (prev_element + next_element) / 2;
      prev_element = curr_element;
      curr_element = next_element;
    }
  return;
}


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


void shift_right (double *array, int n)
{
  double last = array[n - 1];

  for (int idx = n - 1; idx > 0; idx--)
    {
      array[idx] = array[idx - 1];
    }
  array[0] = last;
}

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

int delete_little_elememts (double *array, int length, double barrier)
{
  int idx, cnt_delete = 0;
  for (idx = 0; idx < length; idx++)
    {
      if (array[idx] < barrier)
        {
          cnt_delete++;
          continue;
        }
      array[idx - cnt_delete] = array[idx];
    }
  return length - cnt_delete;
}
