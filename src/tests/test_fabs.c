#include "test_me.h"

START_TEST(s21_fabs_1) {
  double num = 0;
  ck_assert_ldouble_eq(s21_fabs(num), fabs(num));
}
END_TEST

START_TEST(s21_fabs_2) {
  double num = 4.0;
  ck_assert_ldouble_eq(s21_fabs(num), fabs(num));
}
END_TEST

START_TEST(s21_fabs_3) {
  double num = -7.6;
  ck_assert_ldouble_eq(s21_fabs(num), fabs(num));
}
END_TEST

START_TEST(s21_fabs_4) {
  double num = -397291.39207;
  ck_assert_ldouble_eq(s21_fabs(num), fabs(num));
}
END_TEST

START_TEST(s21_fabs_5) {
  double num = -929339729.392074;
  ck_assert_ldouble_eq(s21_fabs(num), fabs(num));
}
END_TEST

START_TEST(s21_fabs_6) {
  double num = 1298397291.392074;
  ck_assert_ldouble_eq(s21_fabs(num), fabs(num));
}
END_TEST

START_TEST(s21_fabs_7) {
  double num = NAN;
  ck_assert_ldouble_nan(s21_fabs(num));
}
END_TEST

START_TEST(s21_fabs_8) {
  double num = INFINITY;
  ck_assert_ldouble_eq(s21_fabs(num), fabs(num));
}
END_TEST

START_TEST(s21_fabs_9) {
  double num = -INFINITY;
  ck_assert_ldouble_eq(s21_fabs(num), fabs(num));
}

END_TEST
START_TEST(s21_fabs_10) {
  double num = -958484939348489292838392928.283883838383838383;
  ck_assert_ldouble_eq(s21_fabs(num), fabs(num));
}
END_TEST

Suite *test_s21_fabs(void) {
  Suite *s = suite_create("\033[45m-=S21_FABS=-\033[0m");
  TCase *tc = tcase_create("s21_fabs_tc");

  tcase_add_test(tc, s21_fabs_1);
  tcase_add_test(tc, s21_fabs_2);
  tcase_add_test(tc, s21_fabs_3);
  tcase_add_test(tc, s21_fabs_4);
  tcase_add_test(tc, s21_fabs_5);
  tcase_add_test(tc, s21_fabs_6);
  tcase_add_test(tc, s21_fabs_7);
  tcase_add_test(tc, s21_fabs_8);
  tcase_add_test(tc, s21_fabs_9);
  tcase_add_test(tc, s21_fabs_10);

  suite_add_tcase(s, tc);
  return s;
}
