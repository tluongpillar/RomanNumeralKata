#include "include/check_roman_numeral_conversion.h"

static const char * roman_numeral_ones_digit[10] = {
  "\0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
};
static const char * roman_numeral_tens_digit[9] = {
  "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
};
static const char * roman_numeral_hundreds_digit[9] = {
  "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
};
static const char * roman_numeral_thousands_digit[3] = {
  "M", "MM", "MMM"
};

static const unsigned int arabic_value_ones_digit[10] = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9
};
static const unsigned int arabic_value_tens_digit[9] = {
  10, 20, 30, 40, 50, 60, 70, 80, 90
};
static const unsigned int arabic_value_hundreds_digit[9] = {
  100, 200, 300, 400, 500, 600, 700, 800, 900
};
static const unsigned int arabic_value_thousands_digit[3] = {
  1000, 2000, 3000
};

char * roman_numeral;

void setup()
{
  roman_numeral = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
}

void teardown()
{
  free(roman_numeral);
  roman_numeral = NULL;
}

START_TEST(test_convert_to_roman_numeral_from_arabic_value__given_0_through_9__returns_empty_string_through_IX)
{
  convert_to_roman_numeral_from_arabic_value(roman_numeral, arabic_value_ones_digit[_i]);
  ck_assert_str_eq(roman_numeral_ones_digit[_i], roman_numeral);
}
END_TEST

START_TEST(test_convert_to_roman_numeral_from_arabic_value__given_10_through_90__returns_X_through_XC)
{
  convert_to_roman_numeral_from_arabic_value(roman_numeral, arabic_value_tens_digit[_i]);
  ck_assert_str_eq(roman_numeral_tens_digit[_i], roman_numeral);
}
END_TEST

START_TEST(test_convert_to_roman_numeral_from_arabic_value__given_100_through_900__returns_C_through_CM)
{
  convert_to_roman_numeral_from_arabic_value(roman_numeral, arabic_value_hundreds_digit[_i]);
  ck_assert_str_eq(roman_numeral_hundreds_digit[_i], roman_numeral);
}
END_TEST

START_TEST(test_convert_to_roman_numeral_from_arabic_value__given_1000_through_3000__returns_M_through_MMM)
{
  convert_to_roman_numeral_from_arabic_value(roman_numeral, arabic_value_thousands_digit[_i]);
  ck_assert_str_eq(roman_numeral_thousands_digit[_i], roman_numeral);
}
END_TEST

START_TEST(test_convert_to_roman_numeral_from_arabic_value__given_3999__returns_MMMCMXCIX)
{
  convert_to_roman_numeral_from_arabic_value(roman_numeral, MAX_ROMAN_NUMERAL_ARABIC_VALUE);
  ck_assert_str_eq(MAX_ROMAN_NUMERAL, roman_numeral);
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

  const int start_index = 0;
  const int roman_numeral_ones_digit_length = sizeof(roman_numeral_ones_digit) / sizeof(roman_numeral_ones_digit[0]);
  const int roman_numeral_tens_digit_length = sizeof(roman_numeral_tens_digit) / sizeof(roman_numeral_tens_digit[0]);
  const int roman_numeral_hundreds_digit_length = sizeof(roman_numeral_hundreds_digit) / sizeof(roman_numeral_hundreds_digit[0]);
  const int roman_numeral_thousands_digit_length = sizeof(roman_numeral_thousands_digit) / sizeof(roman_numeral_thousands_digit[0]);

  suite = suite_create("RomanNumeralConversion");
  tcase_core = tcase_create("Core");

  tcase_add_checked_fixture(tcase_core, setup, teardown);

  tcase_add_test(tcase_core, test_convert_to_roman_numeral_from_arabic_value__given_3999__returns_MMMCMXCIX);
  tcase_add_loop_test(tcase_core, test_convert_to_roman_numeral_from_arabic_value__given_1000_through_3000__returns_M_through_MMM, start_index, roman_numeral_thousands_digit_length);
  tcase_add_loop_test(tcase_core, test_convert_to_roman_numeral_from_arabic_value__given_100_through_900__returns_C_through_CM, start_index, roman_numeral_hundreds_digit_length);
  tcase_add_loop_test(tcase_core, test_convert_to_roman_numeral_from_arabic_value__given_10_through_90__returns_X_through_XC, start_index, roman_numeral_tens_digit_length);
  tcase_add_loop_test(tcase_core, test_convert_to_roman_numeral_from_arabic_value__given_0_through_9__returns_empty_string_through_IX, start_index, roman_numeral_ones_digit_length);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_MMMCMXCIX_max_roman_numeral__returns_3999);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_M_through_MMM_by_M__returns_1000_through_3000_by_1000);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_C_through_CM_by_C__returns_100_through_900_by_100);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_X_through_XC_by_X__returns_10_through_90_by_10);
  tcase_add_test(tcase_core, test_convert_to_arabic_value_from_roman_numeral__given_I_through_IX__returns_1_through_9);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
