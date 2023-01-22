#include "test_me.h"

START_TEST(s21_acos_1) {
  double num = 0.;
  ck_assert_ldouble_eq_tol(s21_acos(num), acos(num), S21_EPS);
}
END_TEST

START_TEST(s21_acos_2) {
  double num = 0.99;
  ck_assert_ldouble_eq_tol(s21_acos(num), acos(num), S21_EPS);
}
END_TEST

START_TEST(s21_acos_3) {
  double num = -0.144;
  ck_assert_ldouble_eq_tol(s21_acos(num), acos(num), S21_EPS);
}
END_TEST

START_TEST(s21_acos_4) {
  double num = 1.;
  ck_assert_ldouble_eq_tol(s21_acos(num), acos(num), S21_EPS);
}
END_TEST

START_TEST(s21_acos_5) {
  double num = 0.5555;
  ck_assert_ldouble_eq_tol(s21_acos(num), acos(num), S21_EPS);
}
END_TEST

START_TEST(s21_acos_6) {
  double num = -1.;
  ck_assert_ldouble_eq_tol(s21_acos(num), acos(num), S21_EPS);
}
END_TEST

START_TEST(s21_acos_7) {
  double num = NAN;
  ck_assert_ldouble_nan(s21_acos(num));
  ck_assert_ldouble_nan(acos(num));
}
END_TEST

START_TEST(s21_acos_8) {
  double num = -NAN;
  ck_assert_ldouble_nan(s21_acos(num));
  ck_assert_ldouble_nan(acos(num));
}
END_TEST

START_TEST(s21_acos_9) {
  double num = INFINITY;
  ck_assert_ldouble_nan(s21_acos(num));
  ck_assert_ldouble_nan(acos(num));
}
END_TEST

START_TEST(s21_acos_10) {
  double num = -INFINITY;
  ck_assert_ldouble_nan(s21_acos(num));
  ck_assert_ldouble_nan(acos(num));
}
END_TEST

START_TEST(s21_acos_11) {
  srand(time(NULL));
  for (double num = S21_EPS; num < 1;
       num *= (rand() % 10000) / 1000000. + 1.01) {
    ck_assert_ldouble_eq_tol(s21_acos(num), acos(num), S21_EPS);
  }
}

START_TEST(s21_acos_12) {
  srand(time(NULL));
  for (double num = -S21_EPS; num > -1;
       num *= (rand() % 10000) / 1000000. + 1.01) {
    ck_assert_ldouble_eq_tol(s21_acos(num), acos(num), S21_EPS);
  }
}

START_TEST(s21_acos_13) {
  double num = -2.2;
  ck_assert_ldouble_nan(s21_acos(num));
}
END_TEST

START_TEST(s21_acos_14) {
  double num = 2.2;
  ck_assert_ldouble_nan(s21_acos(num));
}
END_TEST

Suite *test_s21_acos(void) {
  Suite *s = suite_create("\033[45m-=S21_ACOS=-\033[0m");
  TCase *tc = tcase_create("s21_acos_tc");

  tcase_add_test(tc, s21_acos_1);
  tcase_add_test(tc, s21_acos_2);
  tcase_add_test(tc, s21_acos_3);
  tcase_add_test(tc, s21_acos_4);
  tcase_add_test(tc, s21_acos_5);
  tcase_add_test(tc, s21_acos_6);
  tcase_add_test(tc, s21_acos_7);
  tcase_add_test(tc, s21_acos_8);
  tcase_add_test(tc, s21_acos_9);
  tcase_add_test(tc, s21_acos_10);
  tcase_add_test(tc, s21_acos_11);
  tcase_add_test(tc, s21_acos_12);
  tcase_add_test(tc, s21_acos_13);
  tcase_add_test(tc, s21_acos_14);

  suite_add_tcase(s, tc);
  return s;
}
