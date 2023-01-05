#include "s21_math.h"

long double s21_sqrt(double x) {
  long double ret = 0;
  if (x == S21_INF) ret = S21_INF;
  if (x == S21_N_INF) ret = S21_NAN;
  if (x != x) ret = S21_NAN;
  if (x < 0) ret = S21_NAN;
  if (x > S21_EPS) ret = s21_pow(x, 1. / 2.);
  return ret;
}
