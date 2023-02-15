#include "s_math.h"

long double s_sin(double x) {
  long double ret = 0;
  if (x != x || x == s_INF || x == s_N_INF) {
    ret = s_NAN;
  } else {
    if (x < s_PI && x > s_N_PI) {
      long double factorial = 1, xpow = x;
      int sign = 1, i;
      for (i = 1; i < 100; ++i) {
        ret += sign * xpow / factorial;
        factorial *= (2 * i) * (2 * i + 1);
        sign *= -1;
        xpow *= x * x;
      }
    } else {
      ret = decomp(x, s_sin);
    }
  }
  return ret;
}

long double decomp(double x, long double function(double)) {
  long double tmp = function(x / 9);
  long double tmp2 = tmp * tmp;
  long double tmp3 = tmp2 * tmp;
  long double tmp5 = tmp2 * tmp3;
  long double tmp7 = tmp2 * tmp5;
  long double tmp9 = tmp2 * tmp7;
  long double ret = 256 * tmp9 - 576 * tmp7 + 432 * tmp5 - 120 * tmp3 + 9 * tmp;
  return ret;
}
