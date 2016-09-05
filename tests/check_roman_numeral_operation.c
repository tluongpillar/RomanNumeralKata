#include "include/check_roman_numeral_operation.h"

static char * lhs_roman_numeral;
static char * rhs_roman_numeral;
static char * expected_result;
static char * actual_result;
static char * failed_result = "INVALID";

static void setup()
{
  const int max_roman_numeral_string_length = strlen(MAX_ROMAN_NUMERAL) + 1;
  lhs_roman_numeral = calloc(max_roman_numeral_string_length, sizeof(char));
  rhs_roman_numeral = calloc(max_roman_numeral_string_length, sizeof(char));
  expected_result = calloc(max_roman_numeral_string_length, sizeof(char));
  actual_result = calloc(max_roman_numeral_string_length, sizeof(char));
}

static void teardown()
{
  free(lhs_roman_numeral);
  lhs_roman_numeral = NULL;

  free(rhs_roman_numeral);
  rhs_roman_numeral = NULL;

  free(expected_result);
  expected_result = NULL;

  free(actual_result);
  actual_result = NULL;
}

static void reset_string_variables()
{
  memset(lhs_roman_numeral, 0, strlen(lhs_roman_numeral));
  memset(rhs_roman_numeral, 0, strlen(rhs_roman_numeral));
  memset(expected_result, 0, strlen(expected_result));
  memset(actual_result, 0, strlen(actual_result));
}

START_TEST(test_add_two_roman_numerals__given_MAX_ROMAN_NUMERAL_plus_I__returns_INVALID_string)
{
  strcpy(lhs_roman_numeral, MAX_ROMAN_NUMERAL);
  strcpy(rhs_roman_numeral, "I");

  add_two_roman_numerals(actual_result, lhs_roman_numeral, rhs_roman_numeral);

  ck_assert_str_eq(failed_result, actual_result);
}
END_TEST

START_TEST(test_add_two_roman_numerals__given_MAX_ROMAN_NUMERAL_plus_I__returns_false)
{
  strcpy(lhs_roman_numeral, MAX_ROMAN_NUMERAL);
  strcpy(rhs_roman_numeral, "I");

  bool did_add_successfully = add_two_roman_numerals(actual_result, lhs_roman_numeral, rhs_roman_numeral);

  ck_assert(false == did_add_successfully);
}
END_TEST

START_TEST(test_add_two_roman_numerals__given_I_plus_I__returns_true)
{
  strcpy(lhs_roman_numeral, "I");
  strcpy(rhs_roman_numeral, "I");

  bool did_add_successfully = add_two_roman_numerals(actual_result, lhs_roman_numeral, rhs_roman_numeral);

  ck_assert(true == did_add_successfully);
}
END_TEST

START_TEST(test_add_two_roman_numerals__given_all_valid_input_combination__returns_correct_sum_with_success)
{
  const unsigned int lhs_arabic_value = _i;
  const unsigned int rhs_arabic_value_upper_limit = MAX_ROMAN_NUMERAL_ARABIC_VALUE - lhs_arabic_value;
  unsigned int expected_result_arabic_value;

  unsigned int rhs_arabic_value;
  for (rhs_arabic_value = 0; rhs_arabic_value <= rhs_arabic_value_upper_limit; ++rhs_arabic_value)
  {
    expected_result_arabic_value = lhs_arabic_value + rhs_arabic_value;
    convert_to_roman_numeral_from_arabic_value(expected_result, expected_result_arabic_value);
    convert_to_roman_numeral_from_arabic_value(lhs_roman_numeral, lhs_arabic_value);
    convert_to_roman_numeral_from_arabic_value(rhs_roman_numeral, rhs_arabic_value);

    add_two_roman_numerals(actual_result, lhs_roman_numeral, rhs_roman_numeral);

    ck_assert_str_eq(expected_result, actual_result);

    reset_string_variables();
  }
}
END_TEST

START_TEST(test_subtract_two_roman_numerals__given_I_minus_II__returns_empty_string)
{
  strcpy(lhs_roman_numeral, "I");
  strcpy(rhs_roman_numeral, "II");
  strcpy(expected_result, "\0");

  subtract_two_roman_numerals(actual_result, lhs_roman_numeral, rhs_roman_numeral);

  ck_assert_str_eq(expected_result, actual_result);
}
END_TEST

START_TEST(test_subtract_two_roman_numerals__given_I_minus_II__returns_false)
{
  strcpy(lhs_roman_numeral, "I");
  strcpy(rhs_roman_numeral, "II");

  bool did_subtract_successfully = subtract_two_roman_numerals(actual_result, lhs_roman_numeral, rhs_roman_numeral);

  ck_assert(false == did_subtract_successfully);
}
END_TEST

START_TEST(test_subtract_two_roman_numerals__given_II_minus_I__returns_true)
{
  strcpy(lhs_roman_numeral, "II");
  strcpy(rhs_roman_numeral, "I");

  bool did_subtract_successfully = subtract_two_roman_numerals(actual_result, lhs_roman_numeral, rhs_roman_numeral);

  ck_assert(true == did_subtract_successfully);
}
END_TEST

START_TEST(test_subtract_two_roman_numerals__given_all_valid_combination_inputs___returns_correct_result_with_success)
{
  const unsigned int lhs_arabic_value = _i;
  unsigned int expected_result_arabic_value;
  unsigned int rhs_arabic_value;

  for (rhs_arabic_value = lhs_arabic_value; rhs_arabic_value >= 0 && rhs_arabic_value <= lhs_arabic_value; --rhs_arabic_value)
  {
    expected_result_arabic_value = lhs_arabic_value - rhs_arabic_value;
    convert_to_roman_numeral_from_arabic_value(expected_result, expected_result_arabic_value);
    convert_to_roman_numeral_from_arabic_value(lhs_roman_numeral, lhs_arabic_value);
    convert_to_roman_numeral_from_arabic_value(rhs_roman_numeral, rhs_arabic_value);

    subtract_two_roman_numerals(actual_result, lhs_roman_numeral, rhs_roman_numeral);

    ck_assert_str_eq(expected_result, actual_result);

    reset_string_variables();
  }
}
END_TEST

START_TEST(test_is_valid_roman_numeral__given_MAX_ROMAN_NUMERAL__returns_true)
{
  ck_assert(true == is_valid_roman_numeral(MAX_ROMAN_NUMERAL));
}
END_TEST

START_TEST(test_is_valid_roman_numeral__given_invalid_roman_numeral__returns_false)
{
  ck_assert(false == is_valid_roman_numeral("FOOBAR"));
}
END_TEST

START_TEST(test_is_valid_roman_numeral__given_invalid_out_of_order_roman_numeral__returns_false)
{
  ck_assert(false == is_valid_roman_numeral("MMMVMXCIX"));
}
END_TEST

START_TEST(test_is_valid_roman_numeral__given_empty_string__returns_true)
{
  ck_assert(true == is_valid_roman_numeral("\0"));
}
END_TEST

Suite * roman_numeral_operation_suite()
{
  Suite *suite;
  TCase *tcase_core;
  const int start_index = 0;
  const int all_valid_combination_inputs_length = MAX_ROMAN_NUMERAL_ARABIC_VALUE + 1;

  suite = suite_create("RomanNumeralOperation");
  tcase_core = tcase_create("Core");

  tcase_add_checked_fixture(tcase_core, setup, teardown);

  tcase_set_timeout(tcase_core, 3600);
  tcase_add_test(tcase_core, test_is_valid_roman_numeral__given_empty_string__returns_true);
  tcase_add_test(tcase_core, test_is_valid_roman_numeral__given_invalid_out_of_order_roman_numeral__returns_false);
  tcase_add_test(tcase_core, test_is_valid_roman_numeral__given_invalid_roman_numeral__returns_false);
  tcase_add_test(tcase_core, test_is_valid_roman_numeral__given_MAX_ROMAN_NUMERAL__returns_true);
  tcase_add_test(tcase_core, test_add_two_roman_numerals__given_MAX_ROMAN_NUMERAL_plus_I__returns_INVALID_string);
  tcase_add_test(tcase_core, test_add_two_roman_numerals__given_MAX_ROMAN_NUMERAL_plus_I__returns_false);
  tcase_add_test(tcase_core, test_add_two_roman_numerals__given_I_plus_I__returns_true);
  tcase_add_loop_test(tcase_core, test_add_two_roman_numerals__given_all_valid_input_combination__returns_correct_sum_with_success, start_index, all_valid_combination_inputs_length);
  tcase_add_test(tcase_core, test_subtract_two_roman_numerals__given_I_minus_II__returns_empty_string);
  tcase_add_test(tcase_core, test_subtract_two_roman_numerals__given_I_minus_II__returns_false);
  tcase_add_test(tcase_core, test_subtract_two_roman_numerals__given_II_minus_I__returns_true);
  tcase_add_loop_test(tcase_core, test_subtract_two_roman_numerals__given_all_valid_combination_inputs___returns_correct_result_with_success, start_index, all_valid_combination_inputs_length);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
