#include "../include/roman_numeral_calculator.h"

bool perform_operation_with_roman_numerals(char ** result, char * lhs_roman_numeral, char * rhs_roman_numeral, char * operation)
{
  bool operation_return_status = false;

  switch (operation[0])
  {
    case '+':
    operation_return_status = add_two_roman_numerals(result, lhs_roman_numeral, rhs_roman_numeral);
    break;
    case '-':
    operation_return_status = subtract_two_roman_numerals(result, lhs_roman_numeral, rhs_roman_numeral);
    break;
    default:
    break;
  }

  return operation_return_status;
}
