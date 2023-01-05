#include "s21_math.h"

long double ln_taylor(long double x) {
  long double betta = 0;
  long double power = 1.0;
  for (int i = 1; i < 3000; i++) {
    long double sign = (i % 2 == 0) ? -1.0 : 1.0;
    power *= (x - 1);
    betta += sign * power / (long double)i;
  }
  return betta;
}

long double s21_ln(double x) {
  long double n = 0;
  while (x < 0.5) {
    x *= S21_E;
    n--;
  }
  while (x > 1.5) {
    x /= S21_E;
    n++;
  }
  n += ln_taylor(x);
  return n;
}

long double s21_log(double x) {
  long double res = 0;
  if (x != x || x < 0)
    res = S21_NAN;  // x == S21_N_INF
  else if (x == S21_INF)
    res = S21_INF;
  else if (x == 0)
    res = S21_N_INF;
  else if (x != 1)
    res = s21_ln(x);
  return res;
}