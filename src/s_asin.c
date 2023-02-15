#include "s_math.h"

long double s_asin(double x) {
  long double ret = 0;
  if (s_fabs(x) <= 1) {
    if (s_fabs(x) > 1. - 1e-16) {
      ret = x * s_PI / 2;
    } else {
      if (s_fabs(x) < 0.9999) {
        long double k = x;
        int i;
        for (i = 1; s_fabs(k / (2 * i - 1.)) > s_EPS / 10000.; ++i) {
          ret += k / (2 * i - 1.);
          k *= (2 * i) * (2 * i - 1.) / 4.0 / (i * i) * x * x;
        }
      } else {
        int sign = x < 0 ? -1 : 1;
        x = s_fabs(x);
        ret = s_PI / 2 -
              s_sqrt(1 - x) * (1.5707288 + -0.2121144 * x +
                                 0.0742610 * x * x + -0.0187293 * x * x * x);
        // Milton Abramowitz and Irene Stegun
        //"Handbook of Mathematical Functions", p.81
        ret *= sign;
      }
    }
  } else {
    ret = s_NAN;
  }
  return ret;
}