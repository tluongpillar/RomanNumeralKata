#include "headers/roman_numeral_operation.h"

bool add_two_roman_numerals(char ** result, char * lhs, char * rhs){
  unsigned int lhs_arabic_value = convert_to_arabic_value_from_roman_numeral(lhs);
  unsigned int rhs_arabic_value = convert_to_arabic_value_from_roman_numeral(rhs);

  unsigned int sum_arabic_value = lhs_arabic_value + rhs_arabic_value;

  convert_to_roman_numeral_from_arabic_value(result, sum_arabic_value);
  return true;
}

bool subtract_two_roman_numerals(char ** result, char * lhs, char * rhs)
{
  unsigned int lhs_arabic_value = convert_to_arabic_value_from_roman_numeral(lhs);
  unsigned int rhs_arabic_value = convert_to_arabic_value_from_roman_numeral(rhs);

  unsigned int result_arabic_value = lhs_arabic_value - rhs_arabic_value;

  convert_to_roman_numeral_from_arabic_value(result, result_arabic_value);
  return false;
}
