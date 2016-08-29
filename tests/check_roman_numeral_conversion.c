#include "headers/check_roman_numeral_conversion.h"

START_TEST(test_convert_to_roman_numeral_from_arabic_value__given_1_through_9__returns_I_through_IX)
{
  char * roman_numeral = (char*)malloc((strlen(MAX_ROMAN_NUMERAL) + 1) * sizeof(char));
  char ** roman_numeral_pointer;
  roman_numeral_pointer = &roman_numeral;

  char * expected_roman_numeral[] = {
    "\0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
  };

  int index;
  for (index = 0; index <= 9; ++index)
  {
    convert_to_roman_numeral_from_arabic_value(roman_numeral_pointer, index);
    ck_assert_str_eq(expected_roman_numeral[index], *roman_numeral_pointer);
    memset(*roman_numeral_pointer, 0, strlen(*roman_numeral_pointer));
  }

  free(roman_numeral);
  roman_numeral = NULL;
  roman_numeral_pointer = NULL;
}
END_TEST

START_TEST(test_convert_to_roman_numeral_from_arabic_value__given_10_through_90__returns_X_through_XC)
{
  char * roman_numeral = (char*)malloc((strlen(MAX_ROMAN_NUMERAL) + 1) * sizeof(char));
  char ** roman_numeral_pointer;
  roman_numeral_pointer = &roman_numeral;

  char * expected_roman_numeral[] = {
    "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
  };

  unsigned int input_arabic_value[] = {
    10, 20, 30, 40, 50, 60, 70, 80, 90
  };

  int index;
  for (index = 0; index <= 8; ++index)
  {
    convert_to_roman_numeral_from_arabic_value(roman_numeral_pointer, input_arabic_value[index]);
    ck_assert_str_eq(expected_roman_numeral[index], *roman_numeral_pointer);
    memset(*roman_numeral_pointer, 0, strlen(*roman_numeral_pointer));
  }

  free(roman_numeral);
  roman_numeral = NULL;
  roman_numeral_pointer = NULL;
}
END_TEST

START_TEST(test_convert_to_roman_numeral_from_arabic_value__given_100_through_900__returns_C_through_CM)
{
  char * roman_numeral = (char*)malloc((strlen(MAX_ROMAN_NUMERAL) + 1) * sizeof(char));
  char ** roman_numeral_pointer;
  roman_numeral_pointer = &roman_numeral;

  char * expected_roman_numeral[] = {
    "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
  };

  unsigned int input_arabic_value[] = {
    100, 200, 300, 400, 500, 600, 700, 800, 900
  };

  int index;
  for (index = 0; index <= 8; ++index)
  {
    convert_to_roman_numeral_from_arabic_value(roman_numeral_pointer, input_arabic_value[index]);
    ck_assert_str_eq(expected_roman_numeral[index], *roman_numeral_pointer);
    memset(*roman_numeral_pointer, 0, strlen(*roman_numeral_pointer));
  }

  free(roman_numeral);
  roman_numeral = NULL;
  roman_numeral_pointer = NULL;
}
END_TEST

START_TEST(test_convert_to_roman_numeral_from_arabic_value__given_1000_through_3000__returns_M_through_MMM)
{
  char * roman_numeral = (char*)malloc((strlen(MAX_ROMAN_NUMERAL) + 1) * sizeof(char));
  char ** roman_numeral_pointer;
  roman_numeral_pointer = &roman_numeral;

  convert_to_roman_numeral_from_arabic_value(roman_numeral_pointer, 1000);
  ck_assert_str_eq("M", *roman_numeral_pointer);
  memset(*roman_numeral_pointer, 0, strlen(*roman_numeral_pointer));

  convert_to_roman_numeral_from_arabic_value(roman_numeral_pointer, 2000);
  ck_assert_str_eq("MM", *roman_numeral_pointer);
  memset(*roman_numeral_pointer, 0, strlen(*roman_numeral_pointer));

  convert_to_roman_numeral_from_arabic_value(roman_numeral_pointer, 3000);
  ck_assert_str_eq("MMM", *roman_numeral_pointer);
  memset(*roman_numeral_pointer, 0, strlen(*roman_numeral_pointer));

  free(roman_numeral);
  roman_numeral = NULL;
  roman_numeral_pointer = NULL;
}
END_TEST

START_TEST(test_convert_to_roman_numeral_from_arabic_value__given_3999__returns_MMMCMXCIX)
{
  char * roman_numeral = (char*)malloc((strlen(MAX_ROMAN_NUMERAL) + 1) * sizeof(char));
  char ** roman_numeral_pointer;
  roman_numeral_pointer = &roman_numeral;

  convert_to_roman_numeral_from_arabic_value(roman_numeral_pointer, MAX_ROMAN_NUMERAL_ARABIC_VALUE);
  ck_assert_str_eq(MAX_ROMAN_NUMERAL, *roman_numeral_pointer);
  memset(*roman_numeral_pointer, 0, strlen(*roman_numeral_pointer));

  free(roman_numeral);
  roman_numeral = NULL;
  roman_numeral_pointer = NULL;
}
END_TEST

START_TEST(test_convert_to_arabic_value_from_roman_numeral__given_I_through_IX__returns_1_through_9)
{
  char * input_roman_numeral[] = {
    "\0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
  };

  unsigned int expected_arabic_value[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9
  };

  int index;
  for (index = 0; index <= 9; ++index)
  {
    ck_assert_uint_eq(expected_arabic_value[index], convert_to_arabic_value_from_roman_numeral(input_roman_numeral[index]));
  }
}
END_TEST

START_TEST(test_convert_to_arabic_value_from_roman_numeral__given_X_through_XC_by_X__returns_10_through_90_by_10)
{
  char * input_roman_numeral[] = {
    "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
  };

  unsigned int expected_arabic_value[] = {
    10, 20, 30, 40, 50, 60, 70, 80, 90
  };

  int index;
  for (index = 0; index <= 8; ++index)
  {
    ck_assert_uint_eq(expected_arabic_value[index], convert_to_arabic_value_from_roman_numeral(input_roman_numeral[index]));
  }
}
END_TEST

START_TEST(test_convert_to_arabic_value_from_roman_numeral__given_C_through_CM_by_C__returns_100_through_900_by_100)
{
  char * input_roman_numeral[] = {
    "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
  };

  unsigned int expected_arabic_value[] = {
    100, 200, 300, 400, 500, 600, 700, 800, 900
  };

  int index;
  for (index = 0; index <= 8; ++index)
  {
    ck_assert_uint_eq(expected_arabic_value[index], convert_to_arabic_value_from_roman_numeral(input_roman_numeral[index]));
  }
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

  tcase_add_test(tcase_core, test_convert_to_roman_numeral_from_arabic_value__given_3999__returns_MMMCMXCIX);
  tcase_add_test(tcase_core, test_convert_to_roman_numeral_from_arabic_value__given_1000_through_3000__returns_M_through_MMM);
  tcase_add_test(tcase_core, test_convert_to_roman_numeral_from_arabic_value__given_100_through_900__returns_C_through_CM);
  tcase_add_test(tcase_core, test_convert_to_roman_numeral_from_arabic_value__given_10_through_90__returns_X_through_XC);
  tcase_add_test(tcase_core, test_convert_to_roman_numeral_from_arabic_value__given_1_through_9__returns_I_through_IX);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_MMMCMXCIX_max_roman_numeral__returns_3999);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_M_through_MMM_by_M__returns_1000_through_3000_by_1000);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_C_through_CM_by_C__returns_100_through_900_by_100);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_X_through_XC_by_X__returns_10_through_90_by_10);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_I_through_IX__returns_1_through_9);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
