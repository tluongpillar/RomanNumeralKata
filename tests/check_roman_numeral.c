#include "headers/check_roman_numeral.h"

START_TEST (test_first)
{
  ck_assert( 1 == 1);
}
END_TEST

Suite * roman_numeral_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeral");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_first);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
