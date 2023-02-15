#include "s_math.h"

long double s_exp(double x) {
  long double ret = 1.0L, z = 1.0L;
  if (x == 0) {
    ret = 1.;
  } else if (x == -s_INF) {
    ret = +0.;
  } else if (x == s_INF) {
    ret = x;
  } else if (x < 0) {
    ret = 1. / s_exp(-x);
  } else {
    for (int i = 1; z > 1e-17 && ret < LDBL_MAX; i++) {
      z = z * x / i;
      ret += z;
    }
    if (ret >= DBL_MAX) ret = s_INF;
  }
  return ret;
}