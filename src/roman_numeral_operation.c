#include "../include/roman_numeral_operation.h"

bool add_two_roman_numerals(char ** result, const char * lhs, const char * rhs){
  unsigned int lhs_arabic_value = convert_to_arabic_value_from_roman_numeral(lhs);
  unsigned int rhs_arabic_value = convert_to_arabic_value_from_roman_numeral(rhs);

  unsigned int sum_arabic_value = lhs_arabic_value + rhs_arabic_value;

  if (sum_arabic_value <= MAX_ROMAN_NUMERAL_ARABIC_VALUE)
  {
    convert_to_roman_numeral_from_arabic_value(result, sum_arabic_value);
    return true;
  }
  else
  {
    return false;
  }
}

bool subtract_two_roman_numerals(char ** result, const char * lhs, const char * rhs)
{
  unsigned int lhs_arabic_value = convert_to_arabic_value_from_roman_numeral(lhs);
  unsigned int rhs_arabic_value = convert_to_arabic_value_from_roman_numeral(rhs);

  if (lhs_arabic_value >= rhs_arabic_value)
  {
    unsigned int result_arabic_value = lhs_arabic_value - rhs_arabic_value;
    convert_to_roman_numeral_from_arabic_value(result, result_arabic_value);
    return true;
  }
  else
  {
    return false;
  }
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

  unsigned int roman_numeral_arabic_value = convert_to_arabic_value_from_roman_numeral(roman_numeral);
  char * expected_roman_numeral = calloc(strlen(MAX_ROMAN_NUMERAL) + 1, sizeof(char));
  char ** expected_roman_numeral_pointer;
  expected_roman_numeral_pointer = &expected_roman_numeral;

  convert_to_roman_numeral_from_arabic_value(expected_roman_numeral_pointer, roman_numeral_arabic_value);

  if (strcmp(expected_roman_numeral, roman_numeral) == 0)
  {
    return true;
  }

  free(expected_roman_numeral);
  expected_roman_numeral = NULL;
  expected_roman_numeral_pointer = NULL;

  return false;
}
