#include "test_me.h"

START_TEST(s21_abs_1) {
  int num = 0;
  ck_assert_int_eq(s21_abs(num), abs(num));
}
END_TEST

START_TEST(s21_abs_2) {
  int num = -148;
  ck_assert_int_eq(s21_abs(num), abs(num));
}
END_TEST

START_TEST(s21_abs_3) {
  int num = -1;
  ck_assert_int_eq(s21_abs(num), abs(num));
}
END_TEST

START_TEST(s21_abs_4) {
  int num = 149046;
  ck_assert_int_eq(s21_abs(num), abs(num));
}
END_TEST

START_TEST(s21_abs_5) {
  for (int num = -1490400; num > -1490465; num -= 5) {
    ck_assert_int_eq(s21_abs(num), abs(num));
  }
}
END_TEST

START_TEST(s21_abs_6) {
  for (int num = INT_MIN; num < 0; num /= 3) {
    ck_assert_int_eq(s21_abs(num), abs(num));
  }
}
END_TEST

START_TEST(s21_abs_7) {
  for (int num = INT_MAX; num > 0; num /= 3) {
    ck_assert_int_eq(s21_abs(num), abs(num));
  }
}
END_TEST

Suite *test_s21_abs(void) {
  Suite *s = suite_create("\033[45m-=S21_ABS=-\033[0m");
  TCase *tc = tcase_create("s21_abs_tc");

  tcase_add_test(tc, s21_abs_1);
  tcase_add_test(tc, s21_abs_2);
  tcase_add_test(tc, s21_abs_3);
  tcase_add_test(tc, s21_abs_4);
  tcase_add_test(tc, s21_abs_5);
  tcase_add_test(tc, s21_abs_6);
  tcase_add_test(tc, s21_abs_7);

  suite_add_tcase(s, tc);
  return s;
}
