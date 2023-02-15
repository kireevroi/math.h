#include "test_me.h"

START_TEST(s_ceil_1) {
  double num = 0.;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_2) {
  double num = 65.739;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_3) {
  double num = 0.144;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_4) {
  double num = 326088.32;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_5) {
  double num = 68.6238;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_6) {
  double num = -21.3;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_7) {
  double num = 65.739;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_8) {
  double num = 86.21;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_9) {
  double num = 231.32;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_10) {
  double num = 21.5;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_11) {
  double num = 5.99999999999;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_12) {
  double num = -5.99999999999;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_13) {
  double num = -0.000000000000000000000001;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_14) {
  double num = 5.000000000000000000000001;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_15) {
  double num = 5.000000000000000001;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_16) {
  double num = NAN;
  ck_assert_ldouble_nan(s_ceil(num));
  ck_assert_ldouble_nan(ceil(num));
}
END_TEST

START_TEST(s_ceil_17) {
  double num = INFINITY;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_18) {
  double num = -NAN;
  ck_assert_ldouble_nan(s_ceil(num));
  ck_assert_ldouble_nan(ceil(num));
}
END_TEST

START_TEST(s_ceil_19) {
  double num = -INFINITY;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_20) {
  double num = 113937.989480;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_21) {
  double num = 4289114249765131.500000;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_22) {
  double num = 32815685683.;
  ck_assert_ldouble_eq(s_ceil(num), ceil(num));
}
END_TEST

START_TEST(s_ceil_23) {
  srand(time(NULL));
  for (double num = s_EPS; num < 1e18 - 1;
       num *= (rand() % 10000) / 1000000. + 3.02) {
    long double x = s_EPS;
    if (floorl(log10l(ceil(num))) >= 10)
      x = s_EPS * powl(10, floorl(log10l(ceil(num))) - 10);
    ck_assert_ldouble_eq_tol(s_ceil(num), ceil(num), x);
  }
}

START_TEST(s_ceil_24) {
  srand(time(NULL));
  for (double num = -1e18 + s_EPS + 1; num < 0;
       num /= (rand() % 10000) / 1000000. + 3.02) {
    ck_assert_ldouble_eq(s_ceil(num), ceil(num));
  }
}

Suite *test_s_ceil(void) {
  Suite *s = suite_create("\033[45m-=s_CEIL=-\033[0m");
  TCase *tc = tcase_create("s_ceil_tc");

  tcase_add_test(tc, s_ceil_1);
  tcase_add_test(tc, s_ceil_2);
  tcase_add_test(tc, s_ceil_3);
  tcase_add_test(tc, s_ceil_4);
  tcase_add_test(tc, s_ceil_5);
  tcase_add_test(tc, s_ceil_6);
  tcase_add_test(tc, s_ceil_7);
  tcase_add_test(tc, s_ceil_8);
  tcase_add_test(tc, s_ceil_9);
  tcase_add_test(tc, s_ceil_10);
  tcase_add_test(tc, s_ceil_11);
  tcase_add_test(tc, s_ceil_12);
  tcase_add_test(tc, s_ceil_13);
  tcase_add_test(tc, s_ceil_14);
  tcase_add_test(tc, s_ceil_15);
  tcase_add_test(tc, s_ceil_16);
  tcase_add_test(tc, s_ceil_17);
  tcase_add_test(tc, s_ceil_18);
  tcase_add_test(tc, s_ceil_19);
  tcase_add_test(tc, s_ceil_20);
  tcase_add_test(tc, s_ceil_21);
  tcase_add_test(tc, s_ceil_22);
  tcase_add_test(tc, s_ceil_23);
  tcase_add_test(tc, s_ceil_24);

  suite_add_tcase(s, tc);
  return s;
}
