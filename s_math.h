#ifndef SRC_s_MATH_H
#define SRC_s_MATH_H

#include <float.h>
#include <stdio.h>

#define s_E 2.71828182845904523536028747135266250
#define s_PI 3.14159265358979324
#define s_N_PI -3.14159265358979324
#define s_EPS 1e-6
#define s_INF 1.0 / 0.0
#define s_N_INF -1.0 / 0.0
#define s_NAN 0.0 / 0.0
#define s_N_NAN -0.0 / 0.0

int s_abs(int x);
long double s_acos(double x);
long double s_asin(double x);
long double s_atan(double x);
long double s_ceil(double x);
long double s_cos(double x);
long double s_exp(double x);
long double s_fabs(double x);
long double s_floor(double x);
long double s_fmod(double x, double y);
long double s_log(double x);
long double s_pow(double base, double exp);
long double s_sin(double x);
long double s_sqrt(double x);
long double s_tan(double x);

long double decomp(double x, long double function(double));
long double ln_taylor(long double x);
long double s_ln(long double x);

#endif  // SRC_s_MATH_H
