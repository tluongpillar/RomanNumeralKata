#include "headers/check_roman_numeral.h"

START_TEST (test_is_roman_numeral__given_invalid_roman_numeral__returns_false)
{
  ck_assert_uint_eq(0, is_roman_numeral('a'));
}
END_TEST

Suite * roman_numeral_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeral");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_is_roman_numeral__given_invalid_roman_numeral__returns_false);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
