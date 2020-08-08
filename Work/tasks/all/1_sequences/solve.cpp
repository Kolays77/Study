#include "head.h"

int count_maximums (const char *file_name)
{
  FILE *fp;
  double curr_element = 0, curr_maximum = 0;
  int cnt_maximums = 0;

  if (!(fp = fopen (file_name, "r")))
    {
      return -1;
    }
  if (fscanf (fp, "%lf", &curr_element) == 1)
    {
      curr_maximum = curr_element;
      cnt_maximums = 1;
    }
  else if (!feof (fp))
    {
      fclose (fp);
      return -2;
    }
  else
    {
      fclose (fp);
      return -3;
    }

  while (fscanf (fp, "%lf", &curr_element) == 1)
    {
      if (curr_element > curr_maximum)
        {
          curr_maximum = curr_element;
          cnt_maximums = 1;
        }
      else if (curr_element < curr_maximum)
        {
          ;
        }
      else
        {
          cnt_maximums++;
        }
    }

  if (!feof (fp))
    {
      fclose (fp);
      return -2;
    }
  fclose (fp);
  return cnt_maximums;
}


int count_local_maximums (const char *file_name)
{
  FILE *fp;
  double curr_element = 0, prev_element = 0, next_element = 0;
  int cnt_local_maximums = 0;

  if (!(fp = fopen (file_name, "r")))
    {
      return -1;
    }

  if (fscanf (fp, "%lf", &prev_element) != 1)
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      fclose (fp);
      return -3;
    }

  if (fscanf (fp, "%lf", &curr_element) != 1)
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      else
        {
          fclose (fp);
          cnt_local_maximums = 1;
          return cnt_local_maximums;
        }
    }
  else if (prev_element >= curr_element)
    {
      cnt_local_maximums++;
    }

  while (fscanf (fp, "%lf", &next_element) == 1)
    {
      if (curr_element >= prev_element && curr_element >= next_element)
        {
          cnt_local_maximums++;
        }

      prev_element = curr_element;
      curr_element = next_element;
    }

  if (!feof (fp))
    {
      fclose (fp);
      return -2;
    }
  fclose (fp);
  if (curr_element >= prev_element)
    {
      cnt_local_maximums++;
    }
  return cnt_local_maximums;
}


int characterize_sequence (const char *file_name)
{
  FILE *fp;
  double curr_element = 0, prev_element = 0;

  int decreasing = 1,
      increasing = 1;

  if (!(fp = fopen (file_name, "r")))
    {
      return -1;
    }

  if (fscanf (fp, "%lf", &prev_element) != 1)
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      fclose (fp);
      return -3;
    }
  if (fscanf (fp, "%lf", &curr_element) != 1)
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      fclose (fp);
      return 4;
    }
  if (prev_element > curr_element)
    {
      increasing = 0;
    }
  else if (prev_element < curr_element)
    {
      decreasing = 0;
    }
  curr_element = prev_element;

  while (fscanf (fp, "%lf", &curr_element) == 1)
    {
      if (!increasing && !decreasing)
        {
          fclose (fp);
          return 0;
        }
      if (prev_element > curr_element)
        {
          increasing = 0;
        }
      else if (prev_element < curr_element)
        {
          decreasing = 0;
        }
      prev_element = curr_element;
    }

  if (!feof (fp))
    {
      fclose (fp);
      return -2;
    }
  fclose (fp);

  if (increasing && decreasing)
    {
      return 3;
    }
  else if (decreasing)
    {
      return 2;
    }
  else if (increasing)
    {
      return 1;
    }
  return 0;
}


int is_fibonachi (const char *name)
{
  FILE *fp;
  int fib1 = 1, fib2 = 2, tmp, curr_element = -1;
  if (!(fp = fopen (name, "r")))
    {
      return -1;
    }

  if (fscanf (fp, "%d", &curr_element) != 1)
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      else
        {
          fclose (fp);
          return -3;
        }
    }
  else if (curr_element != fib1)
    {
      fclose (fp);
      return 0;
    }

  while (fscanf (fp, "%d", &curr_element) == 1)
    {
      if (curr_element != fib1)
        {
          fclose (fp);
          return 0;
        }
      else
        {
          tmp = fib2;
          fib2 = fib1 + fib2;
          fib1 = tmp;
        }
    }

  if (!feof (fp))
    {
      fclose (fp);
      return -2;
    }
  fclose (fp);
  return 1;
}


int is_reverse_fibonachi (const char *name)
{
  FILE *fp;
  int prev_element = 0,
      curr_element = 0,
      next_element = 0,
      fib = 1;

  if (!(fp = fopen (name, "r")))
    {
      return -1;
    }
  if (fscanf (fp, "%d", &curr_element) != 1)
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      fclose (fp);
      return -3;
    }
  if (fscanf (fp, "%d", &next_element) != 1)
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      fclose (fp);
      if (curr_element != 1)
        {
          return 0;
        }
      return 1;
    }
  fib = curr_element - next_element;
  prev_element = curr_element;
  curr_element = next_element;
  while (fscanf (fp, "%d", &next_element) == 1)
    {
      if (next_element != fib || next_element <= 0)
        {
          fclose (fp);
          return 0;
        }
      fib = curr_element - next_element;
      prev_element = curr_element;
      curr_element = next_element;
    }
  if (!feof(fp))
    {
      fclose(fp);
      return -2;
    }
  fclose(fp);
  if (curr_element != 1 || prev_element != 1)
    {
      return 0;
    }
  return 1;
}


int check_two_sequences (const char *name1, const char *name2)
{
  FILE *fp_a, *fp_b;
  double a_prev, a_curr, a_next, b_curr, b_next;
  int answer = 1, enough_in_fp_a = 1;

  if (!(fp_a = fopen (name1, "r")))
    {
      return -11;
    }
  if (!(fp_b = fopen (name2, "r")))
    {
      fclose (fp_a);
      return -12;
    }

  if (fscanf (fp_a, "%lf", &a_prev) != 1)
    {
      if (feof (fp_a))
        {
          fclose (fp_a); fclose (fp_b);
          return -31;
        }
      fclose (fp_a); fclose (fp_b);
      return -21;
    }
  if (fscanf (fp_b, "%lf", &b_curr) != 1)
    {
      if (feof (fp_b))
        {
          fclose (fp_a); fclose (fp_b);
          return -32;
        }
      fclose (fp_a); fclose (fp_b);
      return -22;
    } //check empty

  if (fscanf (fp_b, "%lf%lf", &b_curr, &b_next) != 2)
    {
      if (feof (fp_b))
        {
          fclose (fp_a); fclose (fp_b);
          return 1; //if there are less then 3 elements in fp_b then TRUE
        }
      fclose (fp_a); fclose (fp_b);
      return -22;
    }
  if (fscanf (fp_a, "%lf%lf", &a_curr, &a_next) != 2)
    {
      if (feof (fp_a)) //not enough elements in fp_a
        {
          fclose (fp_a); fclose (fp_b);
          return 2;
        }
      fclose (fp_a); fclose (fp_b);
      return -21;
    }

  if (fabs (2 * b_curr - a_prev - a_next) > EPS)
    {
      answer = 0;
    }
  b_curr = b_next;
  a_prev = a_curr; a_curr = a_next;
  while (fscanf (fp_b, "%lf", &b_next) == 1)
    {
      if (fscanf (fp_a, "%lf", &a_next) != 1)
        {
          if (!feof (fp_a))
            {
              fclose (fp_a); fclose (fp_b);
              return -21;
            }
          enough_in_fp_a = 0;
          break;
        }
      else if (fabs (2 * b_curr - a_prev - a_next) > EPS)
        {
          answer = 0;
        }

      b_curr = b_next;
      a_prev = a_curr; a_curr = a_next;
    }

  if (!enough_in_fp_a)
    {
      fclose (fp_a); fclose (fp_b);
      return 2;
    }
  if (!feof (fp_b))
    {
      fclose (fp_a); fclose (fp_b);
      return -22;
    }
  fclose (fp_a); fclose (fp_b);
  return answer;
}


int standard_deviation (const char *filename, double *deviation)
{
  FILE *fp;
  double curr_element,
      sum_elements = 0, sum_squares = 0;
  int cnt_elements = 0;

  if (!(fp = fopen (filename, "r")))
    {
      return -1;
    }

  while (fscanf (fp, "%lf", &curr_element) == 1)
    {
      cnt_elements++;
      sum_elements += curr_element;
      sum_squares += curr_element * curr_element;
    }
  if (cnt_elements == 0)
    {
      fclose (fp);
      return -3;
    }
  *deviation = sqrt ((sum_squares - (sum_elements * sum_elements / cnt_elements)) / cnt_elements);

  if (!feof (fp))
    {
      fclose (fp);
      return -2;
    }
  fclose (fp);
  return cnt_elements;
}


int type_of_progression (const char *file_name)
{
  FILE *fp;
  double prev_element, curr_element, next_element;
  bool arithmetic = 1, geometric = 1;

  double d = 0, q = 0;

  if (!(fp = fopen (file_name, "r")))
    {
      return -1;
    }

  if (fscanf (fp, "%lf", &prev_element) != 1)
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      fclose (fp);
      return -3;
    }

  if (fscanf (fp, "%lf", &curr_element) != 1)
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      fclose (fp);
      return 4;
    }
  if (fscanf (fp, "%lf", &next_element) != 1)
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      fclose (fp);
      if (fabs (curr_element - prev_element) < EPS)
        {
          return 3;
        }
      if (fabs (curr_element) < EPS || fabs (prev_element) < EPS)
        {
          return 1;
        }
      return 4;
    }

  d = curr_element - prev_element;
  if (fabs (prev_element) > 0)
    {
      q = curr_element / prev_element;
    }
  else
    {
      if (fabs (curr_element) > 0)
        {
          geometric = 0;
        }
      else
        {
          q = 0;
        }
    }
  if (fabs (next_element - curr_element - d) > EPS)
    {
      arithmetic = 0;
    }
  if (fabs (q * curr_element - next_element) > EPS)
    {
      geometric = 0;
    }
  curr_element = next_element;

  while (fscanf (fp, "%lf", &next_element) == 1)
    {
      if (arithmetic && fabs (next_element - curr_element - d) > EPS)
        {
          arithmetic = 0;
        }
      if (geometric && fabs (q * curr_element - next_element) > EPS)
        {
          geometric = 0;
        }
      curr_element = next_element;
    }

  if (!feof (fp))
    {
      fclose (fp);
      return -2;
    }
  fclose(fp);
  if (!arithmetic && !geometric)
    {
      return 0;
    }
  if (arithmetic && !geometric)
    {
      return 1;
    }
  if (geometric && !arithmetic)
    {
      return 2;
    }
  return 3;
}


int get_indeces_of_maximums (const char *file_name, double *answer_max, int *answer_first, int *answer_last)
{
  FILE *fp;
  double curr_element;
  int current_idx = 0;
  double max;
  int first, last;

  if (!(fp = fopen (file_name, "r")))
    {
      return -1;
    }

  if (fscanf (fp, "%lf", &curr_element) != 1)
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      fclose (fp);
      return -3;
    }
  max = curr_element;
  first = current_idx;
  last = current_idx;

  while (fscanf (fp, "%lf", &curr_element) == 1)
    {
      current_idx++;
      if (curr_element > max)
        {
          max = curr_element;
          first = current_idx;
          last = current_idx;
        }
      else if (curr_element < max)
        {
          ;
        }
      else
        {
          last = current_idx;
        }
    }

  if (!feof (fp))
    {
      fclose (fp);
      return -2;
    }
  fclose (fp);
  *answer_max = max;
  *answer_first = first;
  *answer_last = last;
  return 0;
}


int get_indeces_of_barrier (const char *file_name, double barrier, int *answer_first, int *answer_last)
{
  FILE *fp;
  double curr_element;
  int current_idx = 0;
  int was_found = 0;
  int first, last;

  if (!(fp = fopen (file_name, "r")))
    {
      return -1;
    }

  if (fscanf (fp, "%lf", &curr_element) != 1)
    {
      if (!feof (fp))
        {
          fclose (fp);
          return -2;
        }
      fclose (fp);
      return -3;
    }
  if (fabs (curr_element - barrier) < EPS)
    {
      was_found = 1;
      first = current_idx;
      last = current_idx;
    }

  while (fscanf (fp, "%lf", &curr_element) == 1)
    {
      current_idx++;
      if (fabs (curr_element - barrier) < EPS)
        {
          if (!was_found)
            {
              was_found = 1;
              first = current_idx;
            }
          last = current_idx;
        }
    }

  if (!feof (fp))
    {
      fclose (fp);
      return -2;
    }
  fclose (fp);

  if (was_found)
    {
      *answer_first = first;
      *answer_last = last;
    }
  return was_found;
}
