#include "headers/check_roman_numeral_operation.h"

START_TEST(test_add_two_roman_numerals__given_MAX_ROMAN_NUMERAL_plus_I__returns_empty_string_with_failure)
{
  char * lhs_roman_numeral = MAX_ROMAN_NUMERAL;
  char * rhs_roman_numeral = "I";

  char * expected_result = "\0";

  char * actual_result = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** actual_result_pointer;
  actual_result_pointer = &actual_result;

  bool did_add_successfully = add_two_roman_numerals(actual_result_pointer, lhs_roman_numeral, rhs_roman_numeral);

  ck_assert(false == did_add_successfully);
  ck_assert_str_eq(expected_result, actual_result);
}
END_TEST

START_TEST(test_add_two_roman_numerals__given_all_input_combination__returns_correct_sum_with_success)
{
  char * expected_result = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** expected_result_pointer;
  expected_result_pointer = &expected_result;

  char * actual_result = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** actual_result_pointer;
  actual_result_pointer = &actual_result;

  char * lhs_roman_numeral = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** lhs_roman_numeral_pointer;
  lhs_roman_numeral_pointer = &lhs_roman_numeral;

  char * rhs_roman_numeral = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** rhs_roman_numeral_pointer;
  rhs_roman_numeral_pointer = &rhs_roman_numeral;

  bool did_add_successfully = false;
  unsigned int expected_result_arabic_value;
  unsigned int rhs_arabic_value;
  unsigned int rhs_arabic_value_upper_limit;
  unsigned int lhs_arabic_value;
  unsigned int lhs_arabic_value_upper_limit = MAX_ROMAN_NUMERAL_ARABIC_VALUE - 1;
  for (lhs_arabic_value = 1; lhs_arabic_value <= lhs_arabic_value_upper_limit; ++lhs_arabic_value)
  {
    rhs_arabic_value_upper_limit = MAX_ROMAN_NUMERAL_ARABIC_VALUE - lhs_arabic_value;
    for (rhs_arabic_value = 1; rhs_arabic_value <= rhs_arabic_value_upper_limit; ++rhs_arabic_value)
    {
      expected_result_arabic_value = lhs_arabic_value + rhs_arabic_value;

      convert_to_roman_numeral_from_arabic_value(expected_result_pointer, expected_result_arabic_value);

      convert_to_roman_numeral_from_arabic_value(lhs_roman_numeral_pointer, lhs_arabic_value);
      convert_to_roman_numeral_from_arabic_value(rhs_roman_numeral_pointer, rhs_arabic_value);

      did_add_successfully = add_two_roman_numerals(actual_result_pointer, lhs_roman_numeral, rhs_roman_numeral);

      printf("success:%d %s + %s = %s\n", did_add_successfully, lhs_roman_numeral, rhs_roman_numeral, actual_result);

      ck_assert(did_add_successfully);
      ck_assert_str_eq(expected_result, actual_result);

      did_add_successfully = false;
      memset(lhs_roman_numeral, 0, strlen(lhs_roman_numeral));
      memset(rhs_roman_numeral, 0, strlen(rhs_roman_numeral));
      memset(expected_result, 0, strlen(expected_result));
      memset(actual_result, 0, strlen(actual_result));
    }
  }

  free(lhs_roman_numeral);
  lhs_roman_numeral = NULL;
  lhs_roman_numeral_pointer = NULL;

  free(rhs_roman_numeral);
  rhs_roman_numeral = NULL;
  rhs_roman_numeral_pointer = NULL;

  free(actual_result);
  actual_result = NULL;
  actual_result_pointer = NULL;

  free(expected_result);
  expected_result = NULL;
  expected_result_pointer = NULL;
}
END_TEST

START_TEST(test_subtract_two_roman_numerals__given_II_minus_I__returns_I_with_success)
{
  char * lhs_roman_numeral = "II";
  char * rhs_roman_numeral = "I";

  char * expected_result = "I";

  char * actual_result = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** actual_result_pointer;
  actual_result_pointer = &actual_result;

  bool did_subtract_successfully = subtract_two_roman_numerals(actual_result_pointer, lhs_roman_numeral, rhs_roman_numeral);

  ck_assert(true == did_subtract_successfully);
  ck_assert_str_eq(expected_result, actual_result);

  free(actual_result);
  actual_result = NULL;
  actual_result_pointer = NULL;
}
END_TEST

START_TEST(test_subtract_two_roman_numerals__given_I_minus_II__returns_empty_string_with_failure)
{
  char * lhs_roman_numeral = "I";
  char * rhs_roman_numeral = "II";

  char * expected_result = "\0";

  char * actual_result = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** actual_result_pointer;
  actual_result_pointer = &actual_result;

  bool did_subtract_successfully = subtract_two_roman_numerals(actual_result_pointer, lhs_roman_numeral, rhs_roman_numeral);

  ck_assert(false == did_subtract_successfully);
  ck_assert_str_eq(expected_result, actual_result);

  free(actual_result);
  actual_result = NULL;
  actual_result_pointer = NULL;
}
END_TEST

START_TEST(test_subtract_two_roman_numerals__given_I_minus_I__returns_empty_string_with_success)
{
  char * lhs_roman_numeral = "I";
  char * rhs_roman_numeral = "I";

  char * expected_result = "\0";

  char * actual_result = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** actual_result_pointer;
  actual_result_pointer = &actual_result;

  bool did_subtract_successfully = subtract_two_roman_numerals(actual_result_pointer, lhs_roman_numeral, rhs_roman_numeral);

  ck_assert(true == did_subtract_successfully);
  ck_assert_str_eq(expected_result, actual_result);

  free(actual_result);
  actual_result = NULL;
  actual_result_pointer = NULL;
}
END_TEST

Suite * roman_numeral_operation_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeralOperation");
  tcase_core = tcase_create("Core");

  tcase_set_timeout(tcase_core, 3600);
  tcase_add_test(tcase_core, test_add_two_roman_numerals__given_MAX_ROMAN_NUMERAL_plus_I__returns_empty_string_with_failure);
  tcase_add_test(tcase_core, test_add_two_roman_numerals__given_all_input_combination__returns_correct_sum_with_success);
  tcase_add_test(tcase_core, test_subtract_two_roman_numerals__given_II_minus_I__returns_I_with_success);
  tcase_add_test(tcase_core, test_subtract_two_roman_numerals__given_I_minus_II__returns_empty_string_with_failure);
  tcase_add_test(tcase_core, test_subtract_two_roman_numerals__given_I_minus_I__returns_empty_string_with_success);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
