#include "head.h"

double interpolation_lagrange (double *x, double *y, int n, double x0)
{
  double y0 = 0, current;
  for (int i = 0; i < n; i++)
    {
      current = 1;
      for (int j = 0; j < n; j++)
        {
          if (i == j)
            {
              continue;
            }
          if (fabs(x[i] - x[j]) < EPS)
            {
              fprintf (stdout, "Error data: x[%d] = x[%d]!\n", i, j);
              break;
            }
          current *= ((x0 - x[j]) / (x[i] - x[j]));
        }
      y0 += y[i] * current;
    }
  return y0;
}

int make_function (double *x, double *f, int n)
{
  for (int counter = 1; counter < n; counter++)
    {
      for (int i = n - 1, j = i - counter; i >= counter; i--, j--)
        {
          if (fabs (x[i] - x[j]) < EPS)
            {
              fprintf (stdout, "Error data: x[%d] = x[%d]\n", j, i);
              return 0;
            }
          f[i] = (f[i] - f[i - 1]) / (x[i] - x[j]);
        }
    }
  return 1;
}

double interpolation_newton (double *x, double *f, int n, double x0)
{
  double answer = 0;
  for (int idx = n - 1; idx >= 1; idx--)
    {
      answer += f[idx];
      answer *= (x0 - x[idx - 1]);
    }
  answer += f[0];
  return answer;
}

int interpolation_eitken (double *x, double *f, int n, double x0)
{
  for (int counter = 1; counter < n; counter++)
    {
      for (int i = n - 1, j = i - counter; i >= counter; i--, j--)
        {
          if (fabs (x[i] - x[j]) < EPS)
            {
              fprintf (stdout, "Error data: x[%d] = x[%d]\n", j, i);
              return 0;
            }
          f[i] = (f[i] * (x0 - x[j]) - f[i - 1] * (x0 - x[i])) / (x[i] - x[j]);
        }
    }
  return 1;
}

int make_function (double *x, double *f, double *dif, int n)
{
  for (int i = n - 1; i >= 1; i--)
    {
      if (fabs(x[i] - x[i - 1]) < EPS)
        {
          fprintf (stdout, "Error data: x[%d] = x[%d]\n", i - 1, i);
          return 0;
        }
      f[i] = (f[i] - f[i - 1]) / (x[i] - x[i - 1]);
    }
  for (int counter = 2; counter <= 2 * n - 1; counter++)
    {
      int counter_div_2 = counter / 2;
      for (int i = n - 1, j = n - 1 - counter_div_2; i >= counter_div_2; i--, j--)
        {
          if (fabs(x[i] - x[j]) < EPS)
            {
              fprintf (stdout, "Error data: x[%d] = x[%d]\n", j, i);
              return 0;
            }
          dif[i] = (dif[i] - f[i]) / (x[i] - x[j]);
          if (i - (counter + 1) / 2 < 0)
            {
              continue;
            }
          if (fabs(x[i] - x[i - j / 2]) < EPS)
            {
              fprintf (stdout, "Error data: x[%d] = x[%d]\n", j, i);
              return 0;
            }
          f[i]  = (f[i] - dif[i - 1]) / (x[i] - x[i - (counter + 1) / 2]);
        }
    }
  return 1;
}

double interpolation_lagrange (double *x, double *func, double *dif, int n, double x0)
{
  double answer = 0;
  for (int idx = n - 1; idx >= 1; idx--)
    {
      answer += dif[idx];
      answer *= (x0 - x[idx]);
      answer += func[idx];
      answer *= (x0 - x[idx - 1]);
    }
  answer += dif[0];
  answer *= (x0 - x[0]);
  answer += func[0];
  return answer;
}

double get_sin (double x, double eps)
{
  double n = floor (x / (2 * M_PI)), sin_x;
  int sign = 1;

  x -= (2 * M_PI * n);
  if (x > M_PI)
    {
      x -= M_PI;
      sign *= -1;
    }
  if (x > M_PI / 2)
    {
      x = M_PI - x;
    }
  if (x > 1 - EPS)
    {
      x /= 2;
      sin_x = taylor_sin (x, eps);
      sin_x = 2 * sin_x * sqrt (1 - sin_x * sin_x);
    }
  else
    {
      sin_x = taylor_sin (x, eps);
    }
  return sin_x * sign;
}

double taylor_sin (double x, double eps)
{
  double o = fabs (x), sin_x = x, cur_add = x;

  for (int cur_factor = 3; o > eps && fabs (cur_add) > EPS; cur_factor += 2)
    {
      cur_add *= (-x * x / (cur_factor * (cur_factor - 1)));
      sin_x += cur_add;
      o *= x;
    }
  return sin_x;
}

double get_cos (double x, double eps)
{
  double n = floor (x / (2 * M_PI)), cos_x;
  int sign = 1;

  x -= (2 * M_PI * n);
  if (x > M_PI)
    {
      x -= M_PI;
      sign *= -1;
    }
  if (x > M_PI / 2)
    {
      x = M_PI - x;
      sign *= -1;
    }
  if (x > 1 - EPS)
    {
      x /= 2;
      cos_x = taylor_cos (x, eps);
      cos_x = 2 * cos_x * cos_x - 1;
    }
  else
    {
      cos_x = taylor_cos (x, eps);
    }
  return cos_x *= sign;
}

double taylor_cos (double x, double eps)
{
  double o = fabs (x), cos_x = 1, cur_add = 1;

  for (int cur_factor = 2; o > eps && fabs (cur_add) > EPS; cur_factor += 2)
    {
      cur_add *= (-x * x / (cur_factor * (cur_factor - 1)));
      cos_x += cur_add;
      o *= x;
    }
  return cos_x;
}

double get_exp (double x, double eps)
{
  double exp_x = 1, cur_e;
  int count = 0, sign = 1;
  int trunc_x = (int) x;
  x -= trunc_x;
  if (x < 0)
    {
      x++;
      trunc_x--;
    }
  if (trunc_x < 0)
    {
      trunc_x = -trunc_x;
      sign = -1;
    }

  while (trunc_x > 0)
    {
      cur_e = M_E;
      count = 2;
      while (trunc_x > count)
        {
          cur_e *= cur_e;
          count *= 2;
        }
      exp_x *= cur_e;
      trunc_x -= (count / 2);
      if (count == 1)
        {
          break;
        }
    }
  if (sign == -1)
    {
      exp_x = 1 / exp_x;
    }
  return exp_x * taylor_exp (x, eps);
}

double taylor_exp (double x, double eps)
{
  double o = fabs (x), exp = 1, cur_add = 1, factor = 1;

  for (factor = 1; o > eps && fabs (cur_add) > EPS; factor++)
    {
      cur_add *= (x / factor);
      exp += cur_add;
      o *= x;
    }
  return exp;
}

double get_log (double x, double eps)
{
  int cnt_deg2 = 0, cur_cnt;
  double cur_deg2 = 2;
  while (x >= 1)
    {
      cur_deg2 = 2;
      cur_cnt = 1;
      while (x > cur_deg2 * cur_deg2)
        {
          cur_deg2 *= cur_deg2;
          cur_cnt *= 2;
        }
      x /= cur_deg2;
      cnt_deg2 += cur_cnt;
    }
  while (x <= 0.5)
    {
      cur_deg2 = 2;
      cur_cnt = 1;
      while (x * cur_deg2 * cur_deg2 < 1)
        {
          cur_deg2 *= cur_deg2;
          cur_cnt *= 2;
        }
      x *= cur_deg2;
      cnt_deg2 -= cur_cnt;
    }
  return M_LN2 * cnt_deg2 + taylor_log (x, eps);
}

double taylor_log (double x, double eps)
{
  double o = fabs (x), cur_log = 0, cur_add = --x;
  int divider = 1;
  for (divider = 1; fabs (o) > eps; divider++)
    {
      cur_log += cur_add / divider;
      cur_add *= (-x);
      o *= x;
    }
  return cur_log;
}
