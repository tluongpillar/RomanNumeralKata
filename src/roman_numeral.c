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
  int arabic_value = 0;

  switch (*roman_numeral)
  {
    case 'I':
      arabic_value = 1;
      break;
    case 'V':
      arabic_value = 5;
      break;
    case 'X':
      arabic_value = 10;
      break;
    case 'L':
      arabic_value = 50;
      break;
    case 'C':
      arabic_value = 100;
      break;
    default:
      break;
  }

  return arabic_value;
}
