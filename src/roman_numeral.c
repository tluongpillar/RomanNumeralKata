#include "headers/roman_numeral.h"

bool is_roman_numeral(char roman_numeral)
{
  switch (toupper(roman_numeral))
  {
    case 'I':
    case 'V':
    case 'X':
    case 'L':
    case 'C':
    case 'D':
    case 'M':
      return true;
    default:
      return false;
  }
}

unsigned int get_arabic_value_from_roman_numeral(char *roman_numeral)
{
  return (roman_numeral[0] == 'I') ? 1 : 0;
}
