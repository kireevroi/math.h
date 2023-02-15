#include "test_me.h"

int main(void) {
  int failed = 0;
  Suite *s_string_test[] = {
      test_s_abs(),   test_s_acos(), test_s_asin(), test_s_atan(),
      test_s_ceil(),  test_s_cos(),  test_s_exp(),  test_s_fabs(),
      test_s_floor(), test_s_fmod(), test_s_log(),  test_s_pow(),
      test_s_sin(),   test_s_sqrt(), test_s_tan(),  NULL};

  for (int i = 0; s_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  return failed == 0 ? 0 : 1;
}