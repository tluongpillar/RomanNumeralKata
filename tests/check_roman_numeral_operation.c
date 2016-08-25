#include "headers/check_roman_numeral_operation.h"

START_TEST(test_add_two_roman_numerals__given_IV_add_V__returns_IX)
{
  char * result = (char*)malloc(strlen(MAX_ROMAN_NUMERAL) * sizeof(char));
  char ** result_pointer;
  result_pointer = &result;

  add_two_roman_numerals(result_pointer, "IV", "V");

  ck_assert_str_eq("IX", *result_pointer);

  free(result);
  result = NULL;
  result_pointer = NULL;

}
END_TEST

START_TEST(test_add_two_roman_numerals__given_I_add_III__returns_IV)
{
  char * result = (char*)malloc(strlen(MAX_ROMAN_NUMERAL) * sizeof(char));
  char ** result_pointer;
  result_pointer = &result;

  add_two_roman_numerals(result_pointer, "I", "III");

  ck_assert_str_eq("IV", *result_pointer);

  free(result);
  result = NULL;
  result_pointer = NULL;

}
END_TEST

START_TEST(test_add_two_roman_numerals__given_I_add_II__returns_III)
{
  char * result = (char*)malloc(strlen(MAX_ROMAN_NUMERAL) * sizeof(char));
  char ** result_pointer;
  result_pointer = &result;

  add_two_roman_numerals(result_pointer, "I", "II");

  ck_assert_str_eq("III", *result_pointer);

  free(result);
  result = NULL;
  result_pointer = NULL;

}
END_TEST

START_TEST(test_add_two_roman_numerals__given_I_add_I__returns_II)
{
  char * result = (char*)malloc(strlen(MAX_ROMAN_NUMERAL) * sizeof(char));
  char ** result_pointer;
  result_pointer = &result;

  add_two_roman_numerals(result_pointer, "I", "I");

  ck_assert_str_eq("II", *result_pointer);

  free(result);
  result = NULL;
  result_pointer = NULL;

}
END_TEST

Suite * roman_numeral_operation_suite()
{
  Suite *suite;
  TCase *tcase_core;

  suite = suite_create("RomanNumeralOperation");
  tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, test_add_two_roman_numerals__given_IV_add_V__returns_IX);
  tcase_add_test(tcase_core, test_add_two_roman_numerals__given_I_add_III__returns_IV);
  tcase_add_test(tcase_core, test_add_two_roman_numerals__given_I_add_II__returns_III);
  tcase_add_test(tcase_core, test_add_two_roman_numerals__given_I_add_I__returns_II);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
