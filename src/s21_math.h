#ifndef SRC_S21_MATH_H
#define SRC_S21_MATH_H

#include <float.h>
#include <stdio.h>

#define S21_E 2.71828182845904523536028747135266250
#define S21_PI 3.14159265358979324
#define S21_N_PI -3.14159265358979324
#define S21_EPS 1e-6
#define S21_N_EPS -1e-6
#define S21_INF 1.0 / 0.0
#define S21_N_INF -1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_N_NAN -0.0 / 0.0

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double decomp(double x, long double function(double));
long double ln_taylor(long double x);
long double s21_ln(long double x);

#endif  // SRC_S21_MATH_H
