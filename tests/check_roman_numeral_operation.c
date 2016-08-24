#include "headers/check_roman_numeral_operation.h"

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

  tcase_add_test(tcase_core, test_add_two_roman_numerals__given_I_add_I__returns_II);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
