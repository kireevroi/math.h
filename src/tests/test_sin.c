#include "test_me.h"

START_TEST(s21_sin_1) {
  double num = NAN;
  ck_assert_ldouble_nan(s21_sin(num));
  ck_assert_ldouble_nan(sin(num));
}
END_TEST

START_TEST(s21_sin_2) {
  double num = -NAN;
  ck_assert_ldouble_nan(s21_sin(num));
  ck_assert_ldouble_nan(sin(num));
}
END_TEST

START_TEST(s21_sin_3) {
  double num = INFINITY;
  ck_assert_ldouble_nan(s21_sin(num));
  ck_assert_ldouble_nan(sin(num));
}
END_TEST

START_TEST(s21_sin_4) {
  double num = -INFINITY;
  ck_assert_ldouble_nan(s21_sin(num));
  ck_assert_ldouble_nan(sin(num));
}
END_TEST

START_TEST(s21_sin_5) {
  double num = 0.;
  ck_assert_ldouble_eq(s21_sin(num), sin(num));
}
END_TEST

START_TEST(s21_sin_6) {
  double num = 0.5;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_7) {
  double num = -0.5;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_8) {
  double num = 0.2;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_9) {
  double num = 55.5;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_10) {
  double num = 1e-10;
  ck_assert_ldouble_eq(s21_sin(num), sin(num));
}
END_TEST

START_TEST(s21_sin_11) {
  double num = 2185124152.12758289526;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_12) {
  double num = 1e8;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_13) {
  double num = S21_PI / 2.;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_14) {
  double num = -(S21_PI / 2.);
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_15) {
  double num = S21_PI;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_16) {
  double num = S21_PI;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_17) {
  double num = 68.7;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_18) {
  double num = 2412.;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_19) {
  double num = -60.;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

START_TEST(s21_sin_20) {
  double num = -2198.2;
  ck_assert_ldouble_eq_tol(s21_sin(num), sin(num), S21_EPS);
}
END_TEST

Suite *test_s21_sin(void) {
  Suite *s = suite_create("\033[45m-=S21_SIN=-\033[0m");
  TCase *tc = tcase_create("s21_sin_tc");

  tcase_add_test(tc, s21_sin_1);
  tcase_add_test(tc, s21_sin_2);
  tcase_add_test(tc, s21_sin_3);
  tcase_add_test(tc, s21_sin_4);
  tcase_add_test(tc, s21_sin_5);
  tcase_add_test(tc, s21_sin_6);
  tcase_add_test(tc, s21_sin_7);
  tcase_add_test(tc, s21_sin_8);
  tcase_add_test(tc, s21_sin_9);
  tcase_add_test(tc, s21_sin_10);
  tcase_add_test(tc, s21_sin_11);
  tcase_add_test(tc, s21_sin_12);
  tcase_add_test(tc, s21_sin_13);
  tcase_add_test(tc, s21_sin_14);
  tcase_add_test(tc, s21_sin_15);
  tcase_add_test(tc, s21_sin_16);
  tcase_add_test(tc, s21_sin_17);
  tcase_add_test(tc, s21_sin_18);
  tcase_add_test(tc, s21_sin_19);
  tcase_add_test(tc, s21_sin_20);

  suite_add_tcase(s, tc);
  return s;
}
