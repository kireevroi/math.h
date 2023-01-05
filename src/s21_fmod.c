#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (x != x || y != y || y == 0 || x == S21_INF || x == S21_N_INF) {
    res = S21_NAN;
  } else if (y == S21_INF || y == S21_N_INF) {
    res = x;
  } else {
    res = x;
    y = s21_fabs(y);
    if (res > 0) {
      while (res >= y) {
        res -= y;
      }
    } else {
      while (res <= -y) {
        res += y;
      }
    }
  }
  return res;
}
