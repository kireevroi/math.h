#include "test_me.h"

START_TEST(s21_exp_0) {
  double num = 21.323;
  ck_assert_ldouble_eq_tol(s21_exp(num), exp(num), S21_EPS);
}
END_TEST

START_TEST(s21_exp_1_1) {
  double num = 0.;
  ck_assert_ldouble_eq_tol(s21_exp(num), exp(num), S21_EPS);
}
END_TEST

START_TEST(s21_exp_1_2) {
  double num = -0.;
  ck_assert_ldouble_eq_tol(s21_exp(num), exp(num), S21_EPS);
}
END_TEST

START_TEST(s21_exp_2) {
  double num = 1.;
  ck_assert_ldouble_eq_tol(s21_exp(num), exp(num), S21_EPS);
}
END_TEST

START_TEST(s21_exp_3) {
  double num = -1.;
  ck_assert_ldouble_eq_tol(s21_exp(num), exp(num), S21_EPS);
}
END_TEST

START_TEST(s21_exp_4) {
  double num = 999999999999;
  ck_assert_ldouble_infinite(s21_exp(num));
  ck_assert_ldouble_infinite(exp(num));
}
END_TEST

START_TEST(s21_exp_5) {
  double num = -999999999999;
  ck_assert_ldouble_eq_tol(s21_exp(num), exp(num), S21_EPS);
}
END_TEST

START_TEST(s21_exp_6) {
  double num = DBL_MAX;
  ck_assert_ldouble_infinite(s21_exp(num));
  ck_assert_ldouble_infinite(exp(num));
}
END_TEST

START_TEST(s21_exp_7) {
  double num = -DBL_MAX;
  ck_assert_ldouble_eq_tol(s21_exp(num), exp(num), S21_EPS);
}
END_TEST

START_TEST(s21_exp_8) {
  double num = 1e-9;
  ck_assert_ldouble_eq_tol(s21_exp(num), exp(num), S21_EPS);
}
END_TEST

START_TEST(s21_exp_9) {
  double num = -1e-9;
  ck_assert_ldouble_eq_tol(s21_exp(num), exp(num), S21_EPS);
}
END_TEST

START_TEST(s21_exp_10_1) {
  double num = NAN;
  ck_assert_ldouble_nan(s21_exp(num));
  ck_assert_ldouble_nan(exp(num));
}
END_TEST

START_TEST(s21_exp_10_2) {
  double num = -NAN;
  ck_assert_ldouble_nan(s21_exp(num));
  ck_assert_ldouble_nan(exp(num));
}
END_TEST

START_TEST(s21_exp_11) {
  double num = INFINITY;
  ck_assert_ldouble_infinite(s21_exp(num));
  ck_assert_ldouble_infinite(exp(num));
}
END_TEST

START_TEST(s21_exp_12) {
  double num = -INFINITY;
  ck_assert_ldouble_eq_tol(s21_exp(num), exp(num), S21_EPS);
}
END_TEST

START_TEST(s21_exp_13) {
  srand(time(NULL));
  for (double num = -logl(DBL_MAX); num <= logl(DBL_MAX);
       num += (rand() % 10000) / 1000000. + 0.06) {
    long double x = S21_EPS;
    if (floorl(log10l(expl(num))) >= 10)
      x = S21_EPS * powl(10, floorl(log10l(expl(num))) - 10);
    ck_assert_ldouble_eq_tol(s21_exp(num), expl(num), x);
  }
}
END_TEST

START_TEST(s21_exp_14) {
  double num = 3971328.213;
  ck_assert_ldouble_infinite(s21_exp(num));
  ck_assert_ldouble_infinite(exp(num));
}
END_TEST

Suite *test_s21_exp(void) {
  Suite *s = suite_create("\033[45m-=S21_EXP=-\033[0m");
  TCase *tc = tcase_create("s21_exp_tc");

  tcase_add_test(tc, s21_exp_0);
  tcase_add_test(tc, s21_exp_1_1);
  tcase_add_test(tc, s21_exp_1_2);
  tcase_add_test(tc, s21_exp_2);
  tcase_add_test(tc, s21_exp_3);
  tcase_add_test(tc, s21_exp_4);
  tcase_add_test(tc, s21_exp_5);
  tcase_add_test(tc, s21_exp_6);
  tcase_add_test(tc, s21_exp_7);
  tcase_add_test(tc, s21_exp_8);
  tcase_add_test(tc, s21_exp_9);
  tcase_add_test(tc, s21_exp_10_1);
  tcase_add_test(tc, s21_exp_10_2);
  tcase_add_test(tc, s21_exp_11);
  tcase_add_test(tc, s21_exp_12);
  tcase_add_test(tc, s21_exp_13);
  tcase_add_test(tc, s21_exp_14);

  suite_add_tcase(s, tc);
  return s;
}