#include "headers/check_roman_numeral_operation.h"

START_TEST(test_add_two_roman_numerals__given_I_add_I_to_IX__returns_II_to_X)
{
  char * expected_result = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** expected_result_pointer;
  expected_result_pointer = &expected_result;

  char * actual_result = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** actual_result_pointer;
  actual_result_pointer = &actual_result;

  unsigned int expected_result_arabic_value = 0;

  char * lhs_roman_numeral = "I";
  unsigned int lhs_arabic_value = convert_to_arabic_value_from_roman_numeral(lhs_roman_numeral);

  char * rhs_roman_numeral = calloc((strlen(MAX_ROMAN_NUMERAL) + 1), sizeof(char));
  char ** rhs_roman_numeral_pointer;
  rhs_roman_numeral_pointer = &rhs_roman_numeral;

  unsigned int rhs_arabic_value;
  for (rhs_arabic_value = 1; rhs_arabic_value < 10; ++rhs_arabic_value)
  {
    expected_result_arabic_value = lhs_arabic_value + rhs_arabic_value;

    convert_to_roman_numeral_from_arabic_value(expected_result_pointer, expected_result_arabic_value);

    convert_to_roman_numeral_from_arabic_value(rhs_roman_numeral_pointer, rhs_arabic_value);

    add_two_roman_numerals(actual_result_pointer, lhs_roman_numeral, *rhs_roman_numeral_pointer);

    ck_assert_str_eq(*expected_result_pointer, *actual_result_pointer);

    memset(*rhs_roman_numeral_pointer, 0, strlen(*rhs_roman_numeral_pointer));
    memset(*expected_result_pointer, 0, strlen(*expected_result_pointer));
    memset(*actual_result_pointer, 0, strlen(*actual_result_pointer));
  }

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

Suite * roman_numeral_operation_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeralOperation");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_add_two_roman_numerals__given_I_add_I_to_IX__returns_II_to_X);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
