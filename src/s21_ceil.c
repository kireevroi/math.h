#include "s21_math.h"

long double s21_ceil(double a) {
  long double res = 0;
  if (a != a)
    res = a;
  else if (a == S21_INF || a == S21_N_INF)
    res = a;
  else {
    double b = (int)a;
    long double comp_a = a * 10e18;
    long double comp_b = b * 10e18;
    if (comp_a - comp_b > 0) {
      res = (int)(comp_b / 10e18);
      res += 1.;
    } else {
      res = (int)(comp_a / 10e18);
    }
  }
  return res;
}
