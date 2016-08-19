#include "headers/check_roman_numeral.h"

START_TEST (test_is_roman_numeral__given_invalid_roman_numeral__returns_false)
{
  char invalid_roman_numerals[] = "ABEFGHJKNOPQRSTUWYZ";
  int invalid_roman_numerals_count = sizeof(invalid_roman_numerals) / sizeof(invalid_roman_numerals[0]);

  int index;
  for (index = 0; index < invalid_roman_numerals_count; ++index)
  {
    ck_assert_uint_eq(0, is_roman_numeral(invalid_roman_numerals[index]));

    char invalid_roman_numeral_lowercase = tolower(invalid_roman_numerals[index]);
    ck_assert_uint_eq(0, is_roman_numeral(invalid_roman_numeral_lowercase));
  }
}
END_TEST

START_TEST (test_is_roman_numeral__given_valid_roman_numeral__returns_true)
{
  char valid_roman_numerals[] = "IVXLCDM";
  int valid_roman_numerals_count = sizeof(valid_roman_numerals) / sizeof(valid_roman_numerals[0]);

  int index;
  for (index = 0; index < valid_roman_numerals_count; ++index)
  {
    ck_assert_uint_eq(1, is_roman_numeral(valid_roman_numerals[index]));

    char valid_roman_numeral_lowercase = tolower(valid_roman_numerals[index]);
    ck_assert_uint_eq(1, is_roman_numeral(valid_roman_numeral_lowercase));
  }
}
END_TEST

Suite * roman_numeral_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeral");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_is_roman_numeral__given_invalid_roman_numeral__returns_false);
  tcase_add_test(tcase_core, test_is_roman_numeral__given_valid_roman_numeral__returns_true);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
