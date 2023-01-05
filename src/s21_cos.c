#include "s21_math.h"

long double s21_cos(double x) {
  long double ret = 0;
  if (x != x || x == S21_INF || x == S21_N_INF) {
    ret = S21_NAN;
  } else {
    if (x < S21_PI && x > S21_N_PI) {
      long double factorial = 1, xpow = 1;
      int sign = 1, i;
      for (i = 1; i < 100; ++i) {
        ret += sign * xpow / factorial;
        factorial *= (2 * i) * (2 * i - 1);
        sign *= -1;
        xpow *= x * x;
      }
    } else {
      ret = decomp(x, s21_cos);
    }
  }
  return ret;
}
