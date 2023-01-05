#include "s21_math.h"

long double s21_tan(double x) {
  long double ret = 0;
  if (x == S21_INF || x == S21_N_INF || x != x)
    ret = S21_NAN;
  else
    ret = s21_sin(x) / s21_cos(x);
  return ret;
}
