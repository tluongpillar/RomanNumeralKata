#include "headers/check_roman_numeral_conversion.h"

START_TEST(test_convert_to_roman_numeral_from_arabic_value__given_2__returns_II)
{
  char ** roman_numeral;
  convert_to_roman_numeral_from_arabic_value(roman_numeral, 2);
  ck_assert_str_eq("II", *roman_numeral);
}
END_TEST

START_TEST(test_convert_to_roman_numeral_from_arabic_value__given_1__returns_I)
{
  char * roman_numeral = (char*)malloc(10 * sizeof(char));
  char ** roman_numeral_pointer;
  roman_numeral_pointer = &roman_numeral;

  convert_to_roman_numeral_from_arabic_value(roman_numeral_pointer, 1);
  ck_assert_str_eq("I", *roman_numeral_pointer);

  free(roman_numeral);
  roman_numeral = NULL;
}
END_TEST

START_TEST(test_convert_to_arabic_value_from_roman_numeral__given_I_through_IX__returns_1_through_9)
{
  ck_assert_uint_eq(1, convert_to_arabic_value_from_roman_numeral("I"));
  ck_assert_uint_eq(2, convert_to_arabic_value_from_roman_numeral("II"));
  ck_assert_uint_eq(3, convert_to_arabic_value_from_roman_numeral("III"));
  ck_assert_uint_eq(4, convert_to_arabic_value_from_roman_numeral("IV"));
  ck_assert_uint_eq(5, convert_to_arabic_value_from_roman_numeral("V"));
  ck_assert_uint_eq(6, convert_to_arabic_value_from_roman_numeral("VI"));
  ck_assert_uint_eq(7, convert_to_arabic_value_from_roman_numeral("VII"));
  ck_assert_uint_eq(8, convert_to_arabic_value_from_roman_numeral("VIII"));
  ck_assert_uint_eq(9, convert_to_arabic_value_from_roman_numeral("IX"));
}
END_TEST

START_TEST(test_convert_to_arabic_value_from_roman_numeral__given_X_through_XC_by_X__returns_10_through_90_by_10)
{
  ck_assert_uint_eq(10, convert_to_arabic_value_from_roman_numeral("X"));
  ck_assert_uint_eq(20, convert_to_arabic_value_from_roman_numeral("XX"));
  ck_assert_uint_eq(30, convert_to_arabic_value_from_roman_numeral("XXX"));
  ck_assert_uint_eq(40, convert_to_arabic_value_from_roman_numeral("XL"));
  ck_assert_uint_eq(50, convert_to_arabic_value_from_roman_numeral("L"));
  ck_assert_uint_eq(60, convert_to_arabic_value_from_roman_numeral("LX"));
  ck_assert_uint_eq(70, convert_to_arabic_value_from_roman_numeral("LXX"));
  ck_assert_uint_eq(80, convert_to_arabic_value_from_roman_numeral("LXXX"));
  ck_assert_uint_eq(90, convert_to_arabic_value_from_roman_numeral("XC"));
}
END_TEST

START_TEST(test_convert_to_arabic_value_from_roman_numeral__given_C_through_CM_by_C__returns_100_through_900_by_100)
{
  ck_assert_uint_eq(100, convert_to_arabic_value_from_roman_numeral("C"));
  ck_assert_uint_eq(200, convert_to_arabic_value_from_roman_numeral("CC"));
  ck_assert_uint_eq(300, convert_to_arabic_value_from_roman_numeral("CCC"));
  ck_assert_uint_eq(400, convert_to_arabic_value_from_roman_numeral("CD"));
  ck_assert_uint_eq(500, convert_to_arabic_value_from_roman_numeral("D"));
  ck_assert_uint_eq(600, convert_to_arabic_value_from_roman_numeral("DC"));
  ck_assert_uint_eq(700, convert_to_arabic_value_from_roman_numeral("DCC"));
  ck_assert_uint_eq(800, convert_to_arabic_value_from_roman_numeral("DCCC"));
  ck_assert_uint_eq(900, convert_to_arabic_value_from_roman_numeral("CM"));
}
END_TEST

START_TEST(test_convert_to_arabic_value_from_roman_numeral__given_M_through_MMM_by_M__returns_1000_through_3000_by_1000)
{
  ck_assert_uint_eq(1000, convert_to_arabic_value_from_roman_numeral("M"));
  ck_assert_uint_eq(2000, convert_to_arabic_value_from_roman_numeral("MM"));
  ck_assert_uint_eq(3000, convert_to_arabic_value_from_roman_numeral("MMM"));

}
END_TEST

START_TEST(test_convert_to_arabic_value_from_roman_numeral__given_MMMCMXCIX_max_roman_numeral__returns_3999)
{
  ck_assert_uint_eq(MAX_ROMAN_NUMERAL_ARABIC_VALUE, convert_to_arabic_value_from_roman_numeral(MAX_ROMAN_NUMERAL));

}
END_TEST

Suite * roman_numeral_conversion_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeralConversion");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_convert_to_roman_numeral_from_arabic_value__given_2__returns_II);
  tcase_add_test(tcase_core, test_convert_to_roman_numeral_from_arabic_value__given_1__returns_I);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_MMMCMXCIX_max_roman_numeral__returns_3999);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_M_through_MMM_by_M__returns_1000_through_3000_by_1000);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_C_through_CM_by_C__returns_100_through_900_by_100);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_X_through_XC_by_X__returns_10_through_90_by_10);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_I_through_IX__returns_1_through_9);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
