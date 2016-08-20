#include "headers/check_roman_numeral.h"

START_TEST (test_get_arabic_value_from_roman_numeral__given_ROMAN_NUMERAL_LETTERs__returns_expected_arabic_values)
{
  ck_assert_uint_eq(1, get_arabic_value_from_roman_numeral(ROMAN_NUMERAL_LETTER_I));
  ck_assert_uint_eq(5, get_arabic_value_from_roman_numeral(ROMAN_NUMERAL_LETTER_V));
  ck_assert_uint_eq(10, get_arabic_value_from_roman_numeral(ROMAN_NUMERAL_LETTER_X));
  ck_assert_uint_eq(50, get_arabic_value_from_roman_numeral(ROMAN_NUMERAL_LETTER_L));
  ck_assert_uint_eq(100, get_arabic_value_from_roman_numeral(ROMAN_NUMERAL_LETTER_C));
  ck_assert_uint_eq(500, get_arabic_value_from_roman_numeral(ROMAN_NUMERAL_LETTER_D));
  ck_assert_uint_eq(1000, get_arabic_value_from_roman_numeral(ROMAN_NUMERAL_LETTER_M));
}
END_TEST

START_TEST (test_is_roman_numeral__given_invalid_roman_numeral__returns_false)
{
  char invalid_roman_numerals[] = "ABEFGHJKNOPQRSTUWYZ";

  int index;
  for (index = 0; index < strlen(invalid_roman_numerals); ++index)
  {
    ck_assert(is_roman_numeral(invalid_roman_numerals[index]) == false);

    char invalid_roman_numeral_lowercase = tolower(invalid_roman_numerals[index]);
    ck_assert(is_roman_numeral(invalid_roman_numeral_lowercase) == false);
  }
}
END_TEST

START_TEST (test_is_roman_numeral__given_valid_roman_numeral__returns_true)
{
  char valid_roman_numerals[] = {
    ROMAN_NUMERAL_LETTER_I, ROMAN_NUMERAL_LETTER_V, ROMAN_NUMERAL_LETTER_X,
    ROMAN_NUMERAL_LETTER_L, ROMAN_NUMERAL_LETTER_C, ROMAN_NUMERAL_LETTER_D,
    ROMAN_NUMERAL_LETTER_M
  };

  int index;
  for (index = 0; index < strlen(valid_roman_numerals); ++index)
  {
    ck_assert(is_roman_numeral(valid_roman_numerals[index]) == true);

    char valid_roman_numeral_lowercase = tolower(valid_roman_numerals[index]);
    ck_assert(is_roman_numeral(valid_roman_numeral_lowercase) == true);
  }
}
END_TEST

Suite * roman_numeral_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeral");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_get_arabic_value_from_roman_numeral__given_ROMAN_NUMERAL_LETTERs__returns_expected_arabic_values);
  tcase_add_test(tcase_core, test_is_roman_numeral__given_invalid_roman_numeral__returns_false);
  tcase_add_test(tcase_core, test_is_roman_numeral__given_valid_roman_numeral__returns_true);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
