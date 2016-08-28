#include "headers/check_roman_numeral_calculator.h"

START_TEST(test_first)
{
  ck_assert(false);
}
END_TEST

Suite * roman_numeral_calculator_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeralCalculator");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_first);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
