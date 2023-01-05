#include "s21_math.h"

long double s21_asin(double x) {
  long double ret = 0;
  if (-1 <= x && x <= 1) {
    if (x == -1 || x == 1) {
      ret = x * S21_PI / 2;
    } else {
      long double k = x;
      int i;
      for (i = 1; i <= 10000; ++i) {
        ret += k / (2 * i - 1.);
        k *= (2 * i) * (2 * i - 1.) / 4.0 / (i * i) * x * x;
      }
    }
  } else {
    ret = S21_NAN;
  }
  return ret;
}