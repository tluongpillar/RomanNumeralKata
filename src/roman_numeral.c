#include "headers/roman_numeral.h"

bool is_roman_numeral(char roman_numeral)
{
  switch (toupper(roman_numeral))
  {
    case ROMAN_NUMERAL_LETTER_I:
    case ROMAN_NUMERAL_LETTER_V:
    case ROMAN_NUMERAL_LETTER_X:
    case ROMAN_NUMERAL_LETTER_L:
    case ROMAN_NUMERAL_LETTER_C:
    case ROMAN_NUMERAL_LETTER_D:
    case ROMAN_NUMERAL_LETTER_M:
      return true;
    default:
      return false;
  }
}

unsigned int get_arabic_value_from_roman_numeral(char roman_numeral)
{
  int arabic_value = 0;

  switch (roman_numeral)
  {
    case ROMAN_NUMERAL_LETTER_I:
      arabic_value = 1;
      break;
    case ROMAN_NUMERAL_LETTER_V:
      arabic_value = 5;
      break;
    case ROMAN_NUMERAL_LETTER_X:
      arabic_value = 10;
      break;
    case ROMAN_NUMERAL_LETTER_L:
      arabic_value = 50;
      break;
    case ROMAN_NUMERAL_LETTER_C:
      arabic_value = 100;
      break;
    case ROMAN_NUMERAL_LETTER_D:
      arabic_value = 500;
      break;
    case ROMAN_NUMERAL_LETTER_M:
      arabic_value = 1000;
      break;
    default:
      break;
  }

  return arabic_value;
}
