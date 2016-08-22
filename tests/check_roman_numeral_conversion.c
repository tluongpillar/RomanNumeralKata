#include "headers/check_roman_numeral_conversion.h"

START_TEST(test_convert_to_arabic_value_from_roman_numeral__given_VIII__returns_8)
{
  char roman_numeral[] = "VIII";
  ck_assert_uint_eq(8, convert_to_arabic_value_from_roman_numeral(roman_numeral));
}
END_TEST

START_TEST(test_convert_to_arabic_value_from_roman_numeral__given_IV__returns_4)
{
  char roman_numeral[] = "IV";
  ck_assert_uint_eq(4, convert_to_arabic_value_from_roman_numeral(roman_numeral));
}
END_TEST

START_TEST(test_convert_to_arabic_value_from_roman_numeral__given_II__returns_2)
{
  char roman_numeral[] = "II";
  ck_assert_uint_eq(2, convert_to_arabic_value_from_roman_numeral(roman_numeral));
}
END_TEST

Suite * roman_numeral_conversion_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeralConversion");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_VIII__returns_8);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_IV__returns_4);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_II__returns_2);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
