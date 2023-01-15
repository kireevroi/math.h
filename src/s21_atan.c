#include "s21_math.h"

long double s21_atan(double x) {
  long double ret = 0;
  long double tmp = s21_fabs(x);
  int sign = (x < 0) ? -1 : 1;
  if (x != x) {
    ret = x;
  } else if (x == S21_INF || x == S21_N_INF) {
    ret = S21_PI / 2;
  } else {
    long double z = tmp < 1 ? tmp : 1. / tmp;
    long double d = 1.;
    int k_sign = 1;
    ret = z;
    long double pow2k = z * z;
    for (int i = 0; s21_fabs(k_sign * z / d) > S21_EPS / 10; i++) {
      k_sign *= -1;
      d += 2.;
      z *= pow2k;
      ret += k_sign * z / d;
    }
    ret = tmp < 1 ? ret : S21_PI / 2 - ret;
  }
  return ret * sign;
}