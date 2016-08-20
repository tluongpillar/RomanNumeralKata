#include "headers/check_roman_numeral.h"

START_TEST (test_get_arabic_value_from_roman_numeral__given_I__returns_1)
{
  char roman_numeral = 'I';
  ck_assert_uint_eq(1, get_arabic_value_from_roman_numeral(roman_numeral));
}
END_TEST

START_TEST (test_get_arabic_value_from_roman_numeral__given_V__returns_5)
{
  char roman_numeral = 'V';
  ck_assert_uint_eq(5, get_arabic_value_from_roman_numeral(roman_numeral));
}
END_TEST

START_TEST (test_get_arabic_value_from_roman_numeral__given_X__returns_10)
{
  char roman_numeral = 'X';
  ck_assert_uint_eq(10, get_arabic_value_from_roman_numeral(roman_numeral));
}
END_TEST

START_TEST (test_get_arabic_value_from_roman_numeral__given_L__returns_50)
{
  char roman_numeral = 'L';
  ck_assert_uint_eq(50, get_arabic_value_from_roman_numeral(roman_numeral));
}
END_TEST

START_TEST (test_get_arabic_value_from_roman_numeral__given_C__returns_100)
{
  char roman_numeral = 'C';
  ck_assert_uint_eq(100, get_arabic_value_from_roman_numeral(roman_numeral));
}
END_TEST

START_TEST (test_get_arabic_value_from_roman_numeral__given_D__returns_500)
{
  char roman_numeral = 'D';
  ck_assert_uint_eq(500, get_arabic_value_from_roman_numeral(roman_numeral));
}
END_TEST

START_TEST (test_get_arabic_value_from_roman_numeral__given_M__returns_1000)
{
  char roman_numeral = 'M';
  ck_assert_uint_eq(1000, get_arabic_value_from_roman_numeral(roman_numeral));
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
  char valid_roman_numerals[] = "IVXLCDM";

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

  tcase_add_test(tcase_core, test_get_arabic_value_from_roman_numeral__given_I__returns_1);
  tcase_add_test(tcase_core, test_get_arabic_value_from_roman_numeral__given_V__returns_5);
  tcase_add_test(tcase_core, test_get_arabic_value_from_roman_numeral__given_X__returns_10);
  tcase_add_test(tcase_core, test_get_arabic_value_from_roman_numeral__given_L__returns_50);
  tcase_add_test(tcase_core, test_get_arabic_value_from_roman_numeral__given_C__returns_100);
  tcase_add_test(tcase_core, test_get_arabic_value_from_roman_numeral__given_D__returns_500);
  tcase_add_test(tcase_core, test_get_arabic_value_from_roman_numeral__given_M__returns_1000);
  tcase_add_test(tcase_core, test_is_roman_numeral__given_invalid_roman_numeral__returns_false);
  tcase_add_test(tcase_core, test_is_roman_numeral__given_valid_roman_numeral__returns_true);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
