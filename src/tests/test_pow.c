#include "test_me.h"

START_TEST(s21_pow_0) {
  double a = 21.287287;
  double b = 7.453;
  printf("%.7Lf %.7lf\n", s21_exp((long double)b * s21_log(s21_fabs(a))),
         exp((long double)b * log(s21_fabs(a))));
  printf("%.7Lf %.7f\n", s21_pow(a, b), pow(a, b));
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

// START_TEST(s21_pow_1) {
//   double a = 0.;
//   double b = 5.;
//   ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
// }
// END_TEST

// START_TEST(s21_pow_2) {
//   double a = 3.46;
//   double b = -4.5;
//   ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
// }
// END_TEST

// START_TEST(s21_pow_3) {
//   double a = -6.;
//   double b = 2.;
//   ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
// }
// END_TEST

// START_TEST(s21_pow_4) {
//   double a = -5.;
//   double b = -3.5;
//   ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
// }
// END_TEST

// START_TEST(s21_pow_5) {
//   double a = 32.3;
//   double b = 3.;
//   ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
// }
// END_TEST

// START_TEST(s21_pow_6) {
//   double a = 0.321;
//   double b = 3.;
//   ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
// }
// END_TEST

// START_TEST(s21_pow_7) {
//   double a = 0.;
//   double b = 0.;
//   ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
// }
// END_TEST

// START_TEST(s21_pow_8) {
//   double a = INFINITY;
//   double b = -INFINITY;
//   ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
// }
// END_TEST

// START_TEST(s21_pow_9) {
//   double a = NAN;
//   double b = NAN;
//   ck_assert_ldouble_nan(s21_pow(a, b));
//   ck_assert_ldouble_nan(pow(a, b));
// }
// END_TEST

// START_TEST(s21_pow_10) {
//   double a = -NAN;
//   double b = 1.5;
//   ck_assert_ldouble_nan(s21_pow(a, b));
//   ck_assert_ldouble_nan(pow(a, b));
// }
// END_TEST

// START_TEST(s21_pow_11) {
//   double a = INFINITY;
//   double b = 1.5;
//   ck_assert_ldouble_infinite(s21_pow(a, b));
//   ck_assert_ldouble_infinite(pow(a, b));
// }
// END_TEST

// START_TEST(s21_pow_12) {
//   double a = -INFINITY;
//   double b = 1.5;
//   ck_assert_ldouble_infinite(s21_pow(a, b));
//   ck_assert_ldouble_infinite(pow(a, b));
// }
// END_TEST

// START_TEST(s21_pow_13) {
//   double a = 1.3;
//   double b = 1.5;
//   ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
// }
// END_TEST

// START_TEST(s21_pow_14) {
//   double a = 3971328.213;
//   double b = 13.;
//   long double x = S21_EPS;
//   if (floorl(log10l(pow(a, b))) >= 10)
//     x = S21_EPS * pow(10, floorl(log10l(pow(a, b))) - 10);
//   ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), x);
// }
// END_TEST

// START_TEST(s21_pow_15) {
//   srand(time(NULL));
//   for (double num = S21_EPS; num <= DBL_MAX - S21_EPS;
//        num *= (rand() % 10000) / 1000000. + 1.06) {
//     double a = (rand() % 10) + rand() % 100 * S21_EPS;
//     long double x = S21_EPS;
//     if (isfinite(pow(a, num))) {
//       if (floorl(log10l(pow(a, num))) >= 10)
//         x = S21_EPS * pow(10, floorl(log10l(pow(a, num))) - 10);
//       ck_assert_ldouble_eq_tol(s21_pow(a, num), pow(a, num), x);
//     }
//   }
// }
// END_TEST

Suite *test_s21_pow(void) {
  Suite *s = suite_create("\033[45m-=S21_POW=-\033[0m");
  TCase *tc = tcase_create("s21_pow_tc");

  tcase_add_test(tc, s21_pow_0);
  // tcase_add_test(tc, s21_pow_1);
  // tcase_add_test(tc, s21_pow_2);
  // tcase_add_test(tc, s21_pow_3);
  // tcase_add_test(tc, s21_pow_4);
  // tcase_add_test(tc, s21_pow_5);
  // tcase_add_test(tc, s21_pow_6);
  // tcase_add_test(tc, s21_pow_7);
  // tcase_add_test(tc, s21_pow_8);
  // tcase_add_test(tc, s21_pow_9);
  // tcase_add_test(tc, s21_pow_10);
  // tcase_add_test(tc, s21_pow_11);
  // tcase_add_test(tc, s21_pow_12);
  // tcase_add_test(tc, s21_pow_13);
  // tcase_add_test(tc, s21_pow_14);
  // tcase_add_test(tc, s21_pow_15);

  suite_add_tcase(s, tc);
  return s;
}