#include <math.h>  // ВРЕМЕННО

#include "s21_math.h"
long double s21_pow(double base, double exp) {
  long double result = 0;
  if (base != base)
    result = S21_NAN;
  else if (base == S21_N_INF)
    result = S21_INF;
  else if (base == 0. && exp == 0.)
    result = 1;
  else
    result = s21_exp((long double)exp * s21_log(fabs(base))); // FABS?
  return result;
}