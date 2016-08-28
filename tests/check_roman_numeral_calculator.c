#include "headers/check_roman_numeral_calculator.h"

START_TEST(test_perform_operation_with_roman_numerals__given_I_II_add__returns_III_with_success)
{
  char * actual_result = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** actual_result_pointer;
  actual_result_pointer = &actual_result;

  bool did_perform_successfully = perform_operation_with_roman_numerals(actual_result_pointer, "I", "II", "+");

  ck_assert(true == did_perform_successfully);
  ck_assert_str_eq("III", actual_result);

  free(actual_result);
  actual_result = NULL;
  actual_result_pointer = NULL;
}
END_TEST

START_TEST(test_perform_operation_with_roman_numerals__given_MAX_ROMAN_NUMERAL_I_add__returns_empty_string_with_failure)
{
  char * actual_result = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** actual_result_pointer;
  actual_result_pointer = &actual_result;

  bool did_perform_successfully = perform_operation_with_roman_numerals(actual_result_pointer, MAX_ROMAN_NUMERAL, "I", "+");

  ck_assert(false == did_perform_successfully);
  ck_assert_str_eq("\0", actual_result);

  free(actual_result);
  actual_result = NULL;
  actual_result_pointer = NULL;
}
END_TEST

START_TEST(test_perform_operation_with_roman_numerals__given_II_I_subtract__returns_I_with_success)
{
  char * actual_result = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** actual_result_pointer;
  actual_result_pointer = &actual_result;

  bool did_perform_successfully = perform_operation_with_roman_numerals(actual_result_pointer, "II", "I", "-");

  ck_assert(true == did_perform_successfully);
  ck_assert_str_eq("I", actual_result);

  free(actual_result);
  actual_result = NULL;
  actual_result_pointer = NULL;
}
END_TEST

Suite * roman_numeral_calculator_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeralCalculator");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_perform_operation_with_roman_numerals__given_II_I_subtract__returns_I_with_success);
  tcase_add_test(tcase_core, test_perform_operation_with_roman_numerals__given_MAX_ROMAN_NUMERAL_I_add__returns_empty_string_with_failure);
  tcase_add_test(tcase_core, test_perform_operation_with_roman_numerals__given_I_II_add__returns_III_with_success);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
