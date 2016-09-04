#include "include/check_roman_numeral_letter.h"

static const char invalid_roman_numeral_letters[] = "ABEFGHJKNOPQRSTUWYZ";
static const int standard_US_alphabet_letters_count = 26;
static const int invalid_arabic_values[21] = {
  2,3,4,6,7,8,9,
  20,30,40,60,70,80,90,
  200,300,400,600,700,800,900
};

START_TEST (test_get_roman_numeral_letter_from_arabic_value__given_invalid_arabic_value__returns_null_value)
{
  ck_assert_uint_eq('\0', get_roman_numeral_letter_from_arabic_value(invalid_arabic_values[_i]));
}
END_TEST

START_TEST (test_get_roman_numeral_letter_from_arabic_value__given_valid_arabic_value__returns_expected_roman_numeral_letter)
{
  ck_assert_uint_eq(ROMAN_NUMERAL_LETTER_I, get_roman_numeral_letter_from_arabic_value(ARABIC_VALUE_ONE));
  ck_assert_uint_eq(ROMAN_NUMERAL_LETTER_V, get_roman_numeral_letter_from_arabic_value(ARABIC_VALUE_FIVE));
  ck_assert_uint_eq(ROMAN_NUMERAL_LETTER_X, get_roman_numeral_letter_from_arabic_value(ARABIC_VALUE_TEN));
  ck_assert_uint_eq(ROMAN_NUMERAL_LETTER_L, get_roman_numeral_letter_from_arabic_value(ARABIC_VALUE_FIFTY));
  ck_assert_uint_eq(ROMAN_NUMERAL_LETTER_C, get_roman_numeral_letter_from_arabic_value(ARABIC_VALUE_ONE_HUNDRED));
  ck_assert_uint_eq(ROMAN_NUMERAL_LETTER_D, get_roman_numeral_letter_from_arabic_value(ARABIC_VALUE_FIVE_HUNDRED));
  ck_assert_uint_eq(ROMAN_NUMERAL_LETTER_M, get_roman_numeral_letter_from_arabic_value(ARABIC_VALUE_ONE_THOUSAND));
}
END_TEST

START_TEST (test_get_arabic_value_from_roman_numeral_letter__given_invalid_roman_numeral_letters__returns_arabic_value_zero)
{
  int index;
  for (index = 0; index < strlen(invalid_roman_numeral_letters); ++index)
  {
    ck_assert_uint_eq(ARABIC_VALUE_ZERO, get_arabic_value_from_roman_numeral_letter(invalid_roman_numeral_letters[index]));

    char invalid_roman_numeral_letter_lowercase = tolower(invalid_roman_numeral_letters[index]);
    ck_assert_uint_eq(ARABIC_VALUE_ZERO, get_arabic_value_from_roman_numeral_letter(invalid_roman_numeral_letter_lowercase));
  }
}
END_TEST

START_TEST (test_get_arabic_value_from_roman_numeral_letter__given_roman_numeral_letters__returns_expected_arabic_values)
{
  // Checking uppercase
  ck_assert_uint_eq(ARABIC_VALUE_ONE, get_arabic_value_from_roman_numeral_letter(ROMAN_NUMERAL_LETTER_I));
  ck_assert_uint_eq(ARABIC_VALUE_FIVE, get_arabic_value_from_roman_numeral_letter(ROMAN_NUMERAL_LETTER_V));
  ck_assert_uint_eq(ARABIC_VALUE_TEN, get_arabic_value_from_roman_numeral_letter(ROMAN_NUMERAL_LETTER_X));
  ck_assert_uint_eq(ARABIC_VALUE_FIFTY, get_arabic_value_from_roman_numeral_letter(ROMAN_NUMERAL_LETTER_L));
  ck_assert_uint_eq(ARABIC_VALUE_ONE_HUNDRED, get_arabic_value_from_roman_numeral_letter(ROMAN_NUMERAL_LETTER_C));
  ck_assert_uint_eq(ARABIC_VALUE_FIVE_HUNDRED, get_arabic_value_from_roman_numeral_letter(ROMAN_NUMERAL_LETTER_D));
  ck_assert_uint_eq(ARABIC_VALUE_ONE_THOUSAND, get_arabic_value_from_roman_numeral_letter(ROMAN_NUMERAL_LETTER_M));

  // Checking lowercase
  ck_assert_uint_eq(ARABIC_VALUE_ONE, get_arabic_value_from_roman_numeral_letter(tolower(ROMAN_NUMERAL_LETTER_I)));
  ck_assert_uint_eq(ARABIC_VALUE_FIVE, get_arabic_value_from_roman_numeral_letter(tolower(ROMAN_NUMERAL_LETTER_V)));
  ck_assert_uint_eq(ARABIC_VALUE_TEN, get_arabic_value_from_roman_numeral_letter(tolower(ROMAN_NUMERAL_LETTER_X)));
  ck_assert_uint_eq(ARABIC_VALUE_FIFTY, get_arabic_value_from_roman_numeral_letter(tolower(ROMAN_NUMERAL_LETTER_L)));
  ck_assert_uint_eq(ARABIC_VALUE_ONE_HUNDRED, get_arabic_value_from_roman_numeral_letter(tolower(ROMAN_NUMERAL_LETTER_C)));
  ck_assert_uint_eq(ARABIC_VALUE_FIVE_HUNDRED, get_arabic_value_from_roman_numeral_letter(tolower(ROMAN_NUMERAL_LETTER_D)));
  ck_assert_uint_eq(ARABIC_VALUE_ONE_THOUSAND, get_arabic_value_from_roman_numeral_letter(tolower(ROMAN_NUMERAL_LETTER_M)));

}
END_TEST

START_TEST (test_is_roman_numeral_letter__given_invalid_roman_numeral_letters__returns_false)
{
  int index;
  for (index = 0; index < strlen(invalid_roman_numeral_letters); ++index)
  {
    ck_assert(is_roman_numeral_letter(invalid_roman_numeral_letters[index]) == false);

    char invalid_roman_numeral_letter_lowercase = tolower(invalid_roman_numeral_letters[index]);
    ck_assert(is_roman_numeral_letter(invalid_roman_numeral_letter_lowercase) == false);
  }
}
END_TEST

START_TEST (test_is_roman_numeral_letter__given_valid_roman_numeral_letters__returns_true)
{
  char valid_roman_numeral_letters[] = {
    ROMAN_NUMERAL_LETTER_I, ROMAN_NUMERAL_LETTER_V, ROMAN_NUMERAL_LETTER_X,
    ROMAN_NUMERAL_LETTER_L, ROMAN_NUMERAL_LETTER_C, ROMAN_NUMERAL_LETTER_D,
    ROMAN_NUMERAL_LETTER_M
  };

  int valid_roman_numeral_letters_count = strlen(valid_roman_numeral_letters);

  ck_assert_int_eq(ROMAN_NUMERAL_LETTERS_COUNT, valid_roman_numeral_letters_count);

  int index;
  for (index = 0; index < valid_roman_numeral_letters_count; ++index)
  {
    ck_assert(is_roman_numeral_letter(valid_roman_numeral_letters[index]) == true);

    char valid_roman_numeral_letter_lowercase = tolower(valid_roman_numeral_letters[index]);
    ck_assert(is_roman_numeral_letter(valid_roman_numeral_letter_lowercase) == true);
  }
}
END_TEST

Suite * roman_numeral_letter_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeralLetter");
  tcase_core = tcase_create("Core");

  tcase_add_loop_test(tcase_core, test_get_roman_numeral_letter_from_arabic_value__given_invalid_arabic_value__returns_null_value, 0, 21);
  tcase_add_test(tcase_core, test_get_roman_numeral_letter_from_arabic_value__given_valid_arabic_value__returns_expected_roman_numeral_letter);
  tcase_add_test(tcase_core, test_get_arabic_value_from_roman_numeral_letter__given_invalid_roman_numeral_letters__returns_arabic_value_zero);
  tcase_add_test(tcase_core, test_get_arabic_value_from_roman_numeral_letter__given_roman_numeral_letters__returns_expected_arabic_values);
  tcase_add_test(tcase_core, test_is_roman_numeral_letter__given_invalid_roman_numeral_letters__returns_false);
  tcase_add_test(tcase_core, test_is_roman_numeral_letter__given_valid_roman_numeral_letters__returns_true);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
