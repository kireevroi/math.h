#include "test_me.h"

START_TEST(s21_cos_1) {
  double num = NAN;
  ck_assert_ldouble_nan(s21_cos(num));
  ck_assert_ldouble_nan(cos(num));
}
END_TEST

START_TEST(s21_cos_2) {
  double num = -NAN;
  ck_assert_ldouble_nan(s21_cos(num));
  ck_assert_ldouble_nan(cos(num));
}
END_TEST

START_TEST(s21_cos_3) {
  double num = INFINITY;
  ck_assert_ldouble_nan(s21_cos(num));
  ck_assert_ldouble_nan(cos(num));
}
END_TEST

START_TEST(s21_cos_4) {
  double num = -INFINITY;
  ck_assert_ldouble_nan(s21_cos(num));
  ck_assert_ldouble_nan(cos(num));
}
END_TEST

START_TEST(s21_cos_5) {
  double num = 0.;
  ck_assert_ldouble_eq(s21_cos(num), cos(num));
}
END_TEST

START_TEST(s21_cos_6) {
  double num = 0.5;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_7) {
  double num = -0.5;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_8) {
  double num = 0.2;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_9) {
  double num = 55.5;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_10) {
  double num = 1e-10;
  ck_assert_ldouble_eq(s21_cos(num), cos(num));
}
END_TEST

START_TEST(s21_cos_11) {
  double num = 2185124152.12758289526;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_12) {
  double num = 1e8;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_13) {
  double num = 0.6789;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_14) {
  double num = 65.739;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_15) {
  double num = 0.144;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_16) {
  double num = -326088.32;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_17) {
  double num = -68.4;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_18) {
  double num = 32608278368.32;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_19) {
  double num = S21_PI / 2.;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_20) {
  double num = -(S21_PI / 2.);
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_21) {
  double num = S21_PI;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

START_TEST(s21_cos_22) {
  double num = S21_PI;
  ck_assert_ldouble_eq_tol(s21_cos(num), cos(num), S21_EPS);
}
END_TEST

Suite *test_s21_cos(void) {
  Suite *s = suite_create("\033[45m-=S21_COS=-\033[0m");
  TCase *tc = tcase_create("s21_cos_tc");

  tcase_add_test(tc, s21_cos_1);
  tcase_add_test(tc, s21_cos_2);
  tcase_add_test(tc, s21_cos_3);
  tcase_add_test(tc, s21_cos_4);
  tcase_add_test(tc, s21_cos_5);
  tcase_add_test(tc, s21_cos_6);
  tcase_add_test(tc, s21_cos_7);
  tcase_add_test(tc, s21_cos_8);
  tcase_add_test(tc, s21_cos_9);
  tcase_add_test(tc, s21_cos_10);
  tcase_add_test(tc, s21_cos_11);
  tcase_add_test(tc, s21_cos_12);
  tcase_add_test(tc, s21_cos_13);
  tcase_add_test(tc, s21_cos_14);
  tcase_add_test(tc, s21_cos_15);
  tcase_add_test(tc, s21_cos_16);
  tcase_add_test(tc, s21_cos_17);
  tcase_add_test(tc, s21_cos_18);
  tcase_add_test(tc, s21_cos_19);
  tcase_add_test(tc, s21_cos_20);
  tcase_add_test(tc, s21_cos_21);
  tcase_add_test(tc, s21_cos_22);

  suite_add_tcase(s, tc);
  return s;
}
