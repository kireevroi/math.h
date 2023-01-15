#include "s21_math.h"

long double s21_asin(double x) {
  long double ret = 0;
  if (s21_fabs(x) <= 1) {
    if (s21_fabs(x) > 1. - 1e-16) {
      ret = x * S21_PI / 2;
    } else {
      if (s21_fabs(x) < 0.9999) {
        long double k = x;
        int i;
        for (i = 1; s21_fabs(k / (2 * i - 1.)) > S21_EPS / 1000; ++i) {
          ret += k / (2 * i - 1.);
          k *= (2 * i) * (2 * i - 1.) / 4.0 / (i * i) * x * x;
        }
      } else {
        int sign = x < 0 ? -1 : 1;
        x = s21_fabs(x);
        ret = S21_PI / 2 -
              s21_sqrt(1 - x) * (1.5707288 + -0.2121144 * x +
                                 0.0742610 * x * x + -0.0187293 * x * x * x);
        // Milton Abramowitz and Irene Stegun in their book "Handbook of
        // Mathematical Functions", p.81
        ret *= sign;
      }
    }
  } else {
    ret = S21_NAN;
  }
  return ret;
}