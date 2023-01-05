#include "s21_math.h"

long double s21_floor(double a) {
  long double res = 0;
  int sign = 0;
  if (a != a)
    res = a;
  else if (a == S21_INF || a == S21_N_INF)
    res = a;
  else {
    if (a < 0) {
      a *= -1;
      sign++;
      int b = (int)a;
      res = (a != b) ? (int)(a + 1.) : (int)a;
    } else
      res = (int)a;
  }
  if (sign) {
    res *= -1;
  }
  return res;
}