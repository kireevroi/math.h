#include "test_me.h"

// START_TEST(s21_pow_0) {
// double num = 21.287287;
// double exp = 7.453;
// printf("%Lf -- %Lf\n", s21_pow(num, exp), powl(num, exp));
// ck_assert_ldouble_eq_tol(s21_pow(num, exp), powl(num, exp), S21_EPS);
// }
// END_TEST

START_TEST(s21_pow_1) {
  double a = 0.;
  double b = 5.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_2) {
  double a = 3.46;
  double b = 4.5;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

// START_TEST(s21_pow_3) {
//   double a = -1.;
//   double b = 2.;
//   ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
// }
// END_TEST

START_TEST(s21_pow_4) {
  double a = -5.74;
  double b = -7.2;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_5) {
  double a = 32.3;
  double b = 3.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_6) {
  double a = 0.321;
  double b = 3.;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

// START_TEST(s21_pow_7) {
//   double a = 0.;
//   double b = 0.;
//   ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
// }
// END_TEST

START_TEST(s21_pow_8) {
  double a = INFINITY;
  double b = -INFINITY;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

START_TEST(s21_pow_9) {
  double a = NAN;
  double b = NAN;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_10) {
  double a = -NAN;
  double b = 1.5;
  ck_assert_ldouble_nan(s21_pow(a, b));
  ck_assert_ldouble_nan(pow(a, b));
}
END_TEST

START_TEST(s21_pow_11) {
  double a = INFINITY;
  double b = 1.5;
  ck_assert_ldouble_infinite(s21_pow(a, b));
  ck_assert_ldouble_infinite(pow(a, b));
}
END_TEST

START_TEST(s21_pow_12) {
  double a = -INFINITY;
  double b = 1.5;
  ck_assert_ldouble_infinite(s21_pow(a, b));
  ck_assert_ldouble_infinite(pow(a, b));
}
END_TEST

START_TEST(s21_pow_13) {
  double a = 1.3;
  double b = 1.5;
  ck_assert_ldouble_eq_tol(s21_pow(a, b), pow(a, b), S21_EPS);
}
END_TEST

// START_TEST(s21_pow_13) {
//   srand(time(NULL));
//   for (double num = -logl(DBL_MAX); num <= logl(DBL_MAX);
//        num += (rand() % 10000) / 1000000. + 0.06) {
//     long double x = S21_EPS;
//     if (floorl(log10l(powl(num))) >= 10)
//       x = S21_EPS * powl(10, floorl(log10l(powl(num))) - 10);
//     ck_assert_ldouble_eq_tol(s21_pow(num), powl(num),
//                              x);  // powl иначе точность стандартной
//                              хромает...
//   }
// }
// END_TEST

// START_TEST(s21_pow_14) {
//   double num = 3971328.213;
//   ck_assert_ldouble_infinite(s21_pow(num));
//   ck_assert_ldouble_infinite(pow(num));
// }
// END_TEST

Suite *test_s21_pow(void) {
  Suite *s = suite_create("\033[45m-=S21_POW=-\033[0m");
  TCase *tc = tcase_create("s21_pow_tc");

  // tcase_add_test(tc, s21_pow_0);
  tcase_add_test(tc, s21_pow_1);
  tcase_add_test(tc, s21_pow_2);
  // tcase_add_test(tc, s21_pow_3);
  tcase_add_test(tc, s21_pow_4);
  tcase_add_test(tc, s21_pow_5);
  tcase_add_test(tc, s21_pow_6);
  // tcase_add_test(tc, s21_pow_7);
  tcase_add_test(tc, s21_pow_8);
  tcase_add_test(tc, s21_pow_9);
  tcase_add_test(tc, s21_pow_10);
  tcase_add_test(tc, s21_pow_11);
  tcase_add_test(tc, s21_pow_12);
  tcase_add_test(tc, s21_pow_13);
  // tcase_add_test(tc, s21_pow_14);

  suite_add_tcase(s, tc);
  return s;
}