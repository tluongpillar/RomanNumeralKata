#include "headers/check_roman_numeral_conversion.h"

START_TEST(test_first_test)
{
  ck_assert(1 == 2);
}
END_TEST

Suite * roman_numeral_operation_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeralOperation");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_first_test);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
