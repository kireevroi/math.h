#include "test_me.h"

START_TEST(s21_asin_1) {
  double num = NAN;
  ck_assert_ldouble_nan(s21_asin(num));
  ck_assert_ldouble_nan(asin(num));
}
END_TEST

START_TEST(s21_asin_2) {
  double num = -NAN;
  ck_assert_ldouble_nan(s21_asin(num));
  ck_assert_ldouble_nan(asin(num));
}
END_TEST

START_TEST(s21_asin_3) {
  double num = INFINITY;
  ck_assert_ldouble_nan(s21_asin(num));
  ck_assert_ldouble_nan(asin(num));
}
END_TEST

START_TEST(s21_asin_4) {
  double num = -INFINITY;
  ck_assert_ldouble_nan(s21_asin(num));
  ck_assert_ldouble_nan(asin(num));
}
END_TEST

START_TEST(s21_asin_5) {
  double num = 0.95;
  ck_assert_ldouble_eq_tol(s21_acos(num), acos(num), S21_EPS);
}
END_TEST

START_TEST(s21_asin_6) {
  double num = 0.5;
  ck_assert_ldouble_eq_tol(s21_asin(num), asin(num), S21_EPS);
}
END_TEST

START_TEST(s21_asin_7) {
  double num = -0.5;
  ck_assert_ldouble_eq_tol(s21_asin(num), asin(num), S21_EPS);
}
END_TEST

START_TEST(s21_asin_8) {
  double num = 0.2;
  ck_assert_ldouble_eq_tol(s21_asin(num), asin(num), S21_EPS);
}
END_TEST

START_TEST(s21_asin_9) {
  double num = -0.6;
  ck_assert_ldouble_eq_tol(s21_asin(num), asin(num), S21_EPS);
}
END_TEST

START_TEST(s21_asin_10) {
  double num = -1.;
  ck_assert_ldouble_eq_tol(s21_asin(num), asin(num), S21_EPS);
}
END_TEST

START_TEST(s21_asin_11) {
  double num = 1.;
  ck_assert_ldouble_eq_tol(s21_asin(num), asin(num), S21_EPS);
}
END_TEST

START_TEST(s21_asin_12) {
  double num = 0.;
  ck_assert_ldouble_eq_tol(s21_asin(num), asin(num), S21_EPS);
}
END_TEST

START_TEST(s21_asin_13) {
  srand(time(NULL));
  for (double num = S21_EPS; num < 1;
       num *= (rand() % 10000) / 1000000. + 1.01) {
    ck_assert_ldouble_eq_tol(s21_asin(num), asin(num), S21_EPS);
  }
}

START_TEST(s21_asin_14) {
  srand(time(NULL));
  for (double num = -S21_EPS; num > -1;
       num *= (rand() % 10000) / 1000000. + 1.01) {
    ck_assert_ldouble_eq_tol(s21_asin(num), asin(num), S21_EPS);
  }
}

Suite *test_s21_asin(void) {
  Suite *s = suite_create("\033[45m-=S21_ASIN=-\033[0m");
  TCase *tc = tcase_create("s21_asin_tc");

  tcase_add_test(tc, s21_asin_1);
  tcase_add_test(tc, s21_asin_2);
  tcase_add_test(tc, s21_asin_3);
  tcase_add_test(tc, s21_asin_4);
  tcase_add_test(tc, s21_asin_5);
  tcase_add_test(tc, s21_asin_6);
  tcase_add_test(tc, s21_asin_7);
  tcase_add_test(tc, s21_asin_8);
  tcase_add_test(tc, s21_asin_9);
  tcase_add_test(tc, s21_asin_10);
  tcase_add_test(tc, s21_asin_11);
  tcase_add_test(tc, s21_asin_12);
  tcase_add_test(tc, s21_asin_13);
  tcase_add_test(tc, s21_asin_14);

  suite_add_tcase(s, tc);
  return s;
}
