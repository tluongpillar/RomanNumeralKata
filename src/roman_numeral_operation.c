#include "../include/roman_numeral_operation.h"

static char * invalid_result = "INVALID";

bool add_two_roman_numerals(const char * result, const char * lhs, const char * rhs){
  bool success = false;
  strcpy(result, invalid_result);

  if (is_valid_roman_numeral(lhs) && is_valid_roman_numeral(rhs))
  {
    int lhs_arabic_value = convert_to_arabic_value_from_roman_numeral(lhs);
    int rhs_arabic_value = convert_to_arabic_value_from_roman_numeral(rhs);

    int sum_arabic_value = lhs_arabic_value + rhs_arabic_value;

    if (sum_arabic_value <= MAX_ROMAN_NUMERAL_ARABIC_VALUE)
    {
      memset(result, 0, strlen(result));
      convert_to_roman_numeral_from_arabic_value(result, sum_arabic_value);
      success = true;
    }
  }

  return success;
}

bool subtract_two_roman_numerals(const char * result, const char * lhs, const char * rhs)
{
  bool success = false;
  strcpy(result, invalid_result);

  if (is_valid_roman_numeral(lhs) && is_valid_roman_numeral(rhs))
  {
    int lhs_arabic_value = convert_to_arabic_value_from_roman_numeral(lhs);
    int rhs_arabic_value = convert_to_arabic_value_from_roman_numeral(rhs);

    if (lhs_arabic_value >= rhs_arabic_value)
    {
      memset(result, 0, strlen(result));
      int result_arabic_value = lhs_arabic_value - rhs_arabic_value;
      convert_to_roman_numeral_from_arabic_value(result, result_arabic_value);
      success = true;
    }
  }

  return success;
}

bool is_valid_roman_numeral(const char * roman_numeral)
{
  int index;
  for (index = 0; index < strlen(roman_numeral); ++index)
  {
    if (!is_roman_numeral_letter(roman_numeral[index]))
    {
      return false;
    }
  }

  bool is_valid = false;
  int roman_numeral_arabic_value = convert_to_arabic_value_from_roman_numeral(roman_numeral);
  char * expected_roman_numeral = calloc(strlen(MAX_ROMAN_NUMERAL) + 1, sizeof(char));

  convert_to_roman_numeral_from_arabic_value(expected_roman_numeral, roman_numeral_arabic_value);

  if (strcmp(expected_roman_numeral, roman_numeral) == 0)
  {
    is_valid = true;
  }

  free(expected_roman_numeral);
  expected_roman_numeral = NULL;

  return is_valid;
}
