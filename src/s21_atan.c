#include "s21_math.h"

long double s21_atan(double x) {
  long double ret = 0;
  if (x == S21_INF || x == S21_N_INF)
    ret = x == S21_INF ? S21_PI / 2. : S21_N_PI / 2.;
  else
    ret = s21_acos(1. / s21_sqrt(1. + x * x)) * (x < 0 ? -1. : 1.);
  return ret;
}