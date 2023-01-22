#include "s21_math.h"

long double s21_acos(double x) {
  long double ret = 0;
  if (x != x)
    ret = S21_NAN;
  else if (x == 1.)
    ret = 0.;
  else if (x == S21_INF || x == S21_N_INF)
    ret = S21_NAN;
  else if (x > 1. || x < -1.)
    ret = S21_NAN;
  else
    ret = (long double)S21_PI / 2 - s21_asin(x);
  return ret;
}