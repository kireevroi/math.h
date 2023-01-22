#include "test_me.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {
      test_s21_abs(),   test_s21_acos(), test_s21_asin(), test_s21_atan(),
      test_s21_ceil(),  test_s21_cos(),  test_s21_exp(),  test_s21_fabs(),
      test_s21_floor(), test_s21_fmod(), test_s21_log(),  test_s21_pow(),
      test_s21_sin(),   test_s21_sqrt(), test_s21_tan(),  NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  return failed == 0 ? 0 : 1;
}