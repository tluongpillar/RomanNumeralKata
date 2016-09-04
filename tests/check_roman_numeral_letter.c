#include "include/check_roman_numeral_letter.h"

static const char invalid_roman_numeral_letters[19] = "ABEFGHJKNOPQRSTUWYZ";
static const char valid_roman_numeral_letters[7] = {
  ROMAN_NUMERAL_LETTER_I, ROMAN_NUMERAL_LETTER_V, ROMAN_NUMERAL_LETTER_X,
  ROMAN_NUMERAL_LETTER_L, ROMAN_NUMERAL_LETTER_C, ROMAN_NUMERAL_LETTER_D,
  ROMAN_NUMERAL_LETTER_M
};

static const int invalid_arabic_values[21] = {
  2,3,4,6,7,8,9,
  20,30,40,60,70,80,90,
  200,300,400,600,700,800,900
};
static const int valid_arabic_values[7] = {
  ARABIC_VALUE_ONE, ARABIC_VALUE_FIVE, ARABIC_VALUE_TEN, ARABIC_VALUE_FIFTY,
  ARABIC_VALUE_ONE_HUNDRED, ARABIC_VALUE_FIVE_HUNDRED, ARABIC_VALUE_ONE_THOUSAND
};

START_TEST (test_get_roman_numeral_letter_from_arabic_value__given_invalid_arabic_value__returns_null_value)
{
  ck_assert_uint_eq('\0', get_roman_numeral_letter_from_arabic_value(invalid_arabic_values[_i]));
}
END_TEST

START_TEST (test_get_roman_numeral_letter_from_arabic_value__given_valid_arabic_value__returns_expected_roman_numeral_letter)
{
  ck_assert_uint_eq(valid_roman_numeral_letters[_i], get_roman_numeral_letter_from_arabic_value(valid_arabic_values[_i]));
}
END_TEST

START_TEST (test_get_arabic_value_from_roman_numeral_letter__given_invalid_roman_numeral_letters__returns_arabic_value_zero)
{
  ck_assert_uint_eq(ARABIC_VALUE_ZERO, get_arabic_value_from_roman_numeral_letter(invalid_roman_numeral_letters[_i]));

  char invalid_roman_numeral_letter_lowercase = tolower(invalid_roman_numeral_letters[_i]);
  ck_assert_uint_eq(ARABIC_VALUE_ZERO, get_arabic_value_from_roman_numeral_letter(invalid_roman_numeral_letter_lowercase));
}
END_TEST

START_TEST (test_get_arabic_value_from_roman_numeral_letter__given_roman_numeral_letters__returns_expected_arabic_values)
{
  // Checking uppercase
  ck_assert_uint_eq(valid_arabic_values[_i], get_arabic_value_from_roman_numeral_letter(valid_roman_numeral_letters[_i]));

  // Checking lowercase
  ck_assert_uint_eq(valid_arabic_values[_i], get_arabic_value_from_roman_numeral_letter(tolower(valid_roman_numeral_letters[_i])));
}
END_TEST

START_TEST (test_is_roman_numeral_letter__given_invalid_roman_numeral_letters__returns_false)
{
  ck_assert(is_roman_numeral_letter(invalid_roman_numeral_letters[_i]) == false);

  char invalid_roman_numeral_letter_lowercase = tolower(invalid_roman_numeral_letters[_i]);
  ck_assert(is_roman_numeral_letter(invalid_roman_numeral_letter_lowercase) == false);
}
END_TEST

START_TEST (test_is_roman_numeral_letter__given_valid_roman_numeral_letters__returns_true)
{
  ck_assert(is_roman_numeral_letter(valid_roman_numeral_letters[_i]) == true);

  char valid_roman_numeral_letter_lowercase = tolower(valid_roman_numeral_letters[_i]);
  ck_assert(is_roman_numeral_letter(valid_roman_numeral_letter_lowercase) == true);
}
END_TEST

Suite * roman_numeral_letter_suite()
{
  Suite *suite;
  TCase *tcase_core;

  const int start_index = 0;
  const int invalid_roman_numeral_letters_length = sizeof(invalid_roman_numeral_letters) / sizeof(invalid_roman_numeral_letters[0]);
  const int invalid_arabic_values_length = sizeof(invalid_arabic_values) / sizeof(invalid_arabic_values[0]);
  const int valid_roman_numeral_letters_length = sizeof(valid_roman_numeral_letters) / sizeof(valid_roman_numeral_letters[0]);

  suite = suite_create("RomanNumeralLetter");
  tcase_core = tcase_create("Core");

  tcase_add_loop_test(tcase_core, test_get_roman_numeral_letter_from_arabic_value__given_invalid_arabic_value__returns_null_value, start_index, invalid_arabic_values_length);
  tcase_add_loop_test(tcase_core, test_get_roman_numeral_letter_from_arabic_value__given_valid_arabic_value__returns_expected_roman_numeral_letter, start_index, valid_roman_numeral_letters_length);
  tcase_add_loop_test(tcase_core, test_get_arabic_value_from_roman_numeral_letter__given_invalid_roman_numeral_letters__returns_arabic_value_zero,start_index , invalid_roman_numeral_letters_length);
  tcase_add_loop_test(tcase_core, test_get_arabic_value_from_roman_numeral_letter__given_roman_numeral_letters__returns_expected_arabic_values, start_index, valid_roman_numeral_letters_length);
  tcase_add_loop_test(tcase_core, test_is_roman_numeral_letter__given_invalid_roman_numeral_letters__returns_false, start_index, invalid_roman_numeral_letters_length);
  tcase_add_loop_test(tcase_core, test_is_roman_numeral_letter__given_valid_roman_numeral_letters__returns_true, start_index, valid_roman_numeral_letters_length);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
