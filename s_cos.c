#include "s_math.h"

long double s_cos(double x) {
  long double ret = 0;
  if (x != x || x == s_INF || x == s_N_INF) {
    ret = s_NAN;
  } else {
    if (x < s_PI && x > s_N_PI) {
      long double factorial = 1, xpow = 1;
      int sign = 1, i;
      for (i = 1; i < 100; ++i) {
        ret += sign * xpow / factorial;
        factorial *= (2 * i) * (2 * i - 1);
        sign *= -1;
        xpow *= x * x;
      }
    } else {
      ret = decomp(x, s_cos);
    }
  }
  return ret;
}
