#include "headers/check_suite_runner.h"

int main()
{
  int failure_count;
  Suite *suite;
  SRunner *srunner;

  suite = libcheck_suite();
  srunner = srunner_create(suite);

  srunner_add_suite(sr, roman_numeral_suite());

  srunner_run_all(srunner, CK_NORMAL);
  failure_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (failure_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
