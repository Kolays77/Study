#include "head.h"

void swap (double *a, double *b)
{
  double tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
  return;
}

int is_increasing (double *array, int length)
{
  double prev_element = array[0], curr_element;

  for (int idx = 1; idx < length; idx++)
    {
      curr_element = array[idx];
      if (prev_element >= curr_element)
        {
          return 0;
        }
      prev_element = curr_element;
    }
  return 1;
}


int binsearch (double *array, int length, double new_element)
{
  int left = 0, right = length, middle;

  while (right != left)
    {
      middle = (left + right) / 2;
      if (array[middle] < new_element)
        {
          left = middle + 1;
        }
      else
        {
          right = middle;
        }
    }
  return left;
}


void merge (double *a,
            double *b,
            int len_a,
            int len_b,
            double *result)
{
  int idx_a = 0, idx_b = 0;
  double element_a = 0, element_b = 0;

  while (idx_a != len_a && idx_b != len_b)
    {
      element_a = a[idx_a];
      element_b = b[idx_b];
      if (element_a < element_b)
        {
          result[idx_a + idx_b] = element_a;
          idx_a++;
        }
      else
        {
          result[idx_a + idx_b] = element_b;
          idx_b++;
        }
    }
  for (; idx_a < len_a; idx_a++)
    {
      result[idx_a + idx_b] = a[idx_a];
    }
  for (; idx_b < len_b; idx_b++)
    {
      result[idx_a + idx_b] = b[idx_b];
    }
  return;
}

int merge_union (double *a,
                 double *b,
                 int len_a,
                 int len_b,
                 double *result)
{
  int idx_a = 0, idx_b = 0, count_equal = 0;
  double element_a = 0, element_b = 0;
  while (idx_a != len_a && idx_b != len_b)
    {
      element_a = a[idx_a];
      element_b = b[idx_b];
      if (element_a < element_b)
        {
          result[idx_a + idx_b - count_equal] = element_a;
          idx_a++;
          continue;
        }
      if (element_a > element_b)
        {
          result[idx_a + idx_b - count_equal] = element_b;
          idx_b++;
          continue;
        }
      result[idx_a + idx_b - count_equal] = element_b;
      idx_b++;
      idx_a++;
      count_equal++;
    }
  for (; idx_a < len_a; idx_a++)
    {
      result[idx_a + idx_b - count_equal] = a[idx_a];
    }
  for (; idx_b < len_b; idx_b++)
    {
      result[idx_a + idx_b - count_equal] = b[idx_b];
    }
  return len_a + len_b - count_equal;
}


void bubble_sort (double *array, int length)
{
  int idx, cur_length, max_length = length - 1;

  for (cur_length = max_length; cur_length > 0; cur_length--)
    {
      for (idx = 0; idx < cur_length; idx++)
        {
          if (array[idx] > array[idx + 1])
            {
              swap (&array[idx], &array[idx + 1]);
            }
        }
    }
  return;
}

void find_sort (double *array, int length)
{
  int idx_of_current_min;
  double current_min;

  for (int start_idx = 0; start_idx < length; start_idx++)
    {
      current_min = array[start_idx];
      idx_of_current_min = start_idx;
      for (int idx = start_idx + 1; idx < length; idx++)
        {
          if (array[idx] < current_min)
            {
              current_min = array[idx];
              idx_of_current_min = idx;
            }
        }
      swap (&array[start_idx], &array[idx_of_current_min]);
    }
  return;
}


void insertion_sort (double *array, int length)
{
  int idx_insert;
  double tmp;

  for (int finish_idx = 1; finish_idx < length; finish_idx++)
    {
      idx_insert = finish_idx;
      for (int idx = 0; idx < finish_idx; idx++)
        {
          if (array[idx] > array[finish_idx])
            {
              idx_insert = idx;
              break;
            }
        }
      tmp = array[finish_idx];
      for (int idx = finish_idx; idx > idx_insert; idx--)
        {
          array[idx] = array[idx - 1];
        }
      array[idx_insert] = tmp;
    }
  return;
}

void binary_insertion_sort (double *array, int length)
{
  int insert_idx;
  double tmp;

  for (int current_length = 1; current_length < length; current_length++)
    {
      tmp = array[current_length];
      insert_idx = binsearch (array, current_length, tmp);
      for (int idx = current_length; idx > insert_idx; idx--)
        {
          array[idx] = array[idx - 1];
        }
      array[insert_idx] = tmp;
    }
  return;
}


void merge_sort (double *a, double *b, int length)
{
  int current_length2;
  int parity = 1;
  for (int current_length = 1; current_length < length; current_length *= 2)
    {
      for (int idx = 0; idx + current_length <= length; idx += (2 * current_length))
        {
          current_length2 = current_length;
          if (current_length * 2 + idx > length)
            {
              current_length2 = length - idx - current_length;
            }
          if (parity == 1)
            {
              merge (a + idx,
                     a + (idx + current_length),
                     current_length,
                     current_length2,
                     b + idx);
            }
          else
            {
              merge (b + idx,
                     b + (idx + current_length),
                     current_length,
                     current_length2,
                     a + idx);
            }
        }
      parity *= (-1);
    }
  if (parity == -1)
    {
      for (int idx = 0; idx < length; idx++)
        {
          a[idx] = b[idx];
        }
    }
  return;
}

void quick_sort (double *array, int length)
{
  double barrier;
  int left_idx = 0, right_idx = length - 1;

  if (length <= 1)
    {
      return;
    }
  while (length > 1)
    {
      left_idx = 0;
      right_idx = length - 1;
      barrier = array[length / 2];
      while (left_idx <= right_idx)
        {
          while (left_idx < length && array[left_idx] < barrier)
            {
              left_idx++;
            }
          while (right_idx >= 0 && array[right_idx] > barrier)
            {
              right_idx--;
            }
          if (left_idx <= right_idx)
            {
              swap (&array[left_idx], &array[right_idx]);
              left_idx++;
              right_idx--;
            }
        }
      if (left_idx < length - left_idx)
        {
          if (left_idx == 0)
            {
              return;
            }
          quick_sort (array, left_idx);
          array = array + left_idx;
          length = length - left_idx;
        }
      else
        {
          if (length - left_idx == 0)
            {
              return;
            }
          quick_sort (array + left_idx, length - left_idx);
          length = left_idx;
        }
    }
  return;
}


void sift_up (double *binary_tree, int position)
{
  double parent, tmp = binary_tree[position];
  while (position != 0)
    {
      parent = binary_tree[(position - 1) / 2];
      if (tmp > parent)
        {
          binary_tree[position] = parent;
          position--;
          position /= 2;
        }
      else
        {
          break;
        }
    }
  binary_tree[position] = tmp;
  return;
}

void sift_down (double *binary_tree, int position, int length)
{
  double tmp = binary_tree[position];
  int idx1, idx2;
  while ((idx1 = position * 2 + 1) < length)
    {
      idx2 = idx1 + 1;
      if (idx2 < length &&
          binary_tree[idx2] > binary_tree[idx1] &&
          binary_tree[idx2] > tmp)
        {
          binary_tree[position] = binary_tree[idx2];
          position *= 2;
          position += 2;
          continue;
        }
      if (binary_tree[idx1] > tmp)
        {
          binary_tree[position] = binary_tree[idx1];
          position *= 2;
          position += 1;
          continue;
        }
      binary_tree[position] = tmp;
      return;
    }
  return;
}

void heap_sort (double *array, int length)
{
  int idx, current_length;
  for (idx = 1; idx < length; idx++)
    {
      sift_up (array, idx);
    }
  for (current_length = length - 1; current_length > 0; current_length--)
    {
      swap (&array[0], &array[current_length]);
      sift_down (array, 0, current_length);\
    }
}
