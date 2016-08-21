#include "headers/roman_numeral_letter.h"

bool is_roman_numeral_letter(char roman_numeral_letter)
{
  switch (toupper(roman_numeral_letter))
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

unsigned int get_arabic_value_from_roman_numeral_letter(char roman_numeral_letter)
{
  int arabic_value = ARABIC_VALUE_ZERO;

  switch (toupper(roman_numeral_letter))
  {
    case ROMAN_NUMERAL_LETTER_I:
      arabic_value = ARABIC_VALUE_ONE;
      break;
    case ROMAN_NUMERAL_LETTER_V:
      arabic_value = ARABIC_VALUE_FIVE;
      break;
    case ROMAN_NUMERAL_LETTER_X:
      arabic_value = ARABIC_VALUE_TEN;
      break;
    case ROMAN_NUMERAL_LETTER_L:
      arabic_value = ARABIC_VALUE_FIFTY;
      break;
    case ROMAN_NUMERAL_LETTER_C:
      arabic_value = ARABIC_VALUE_ONE_HUNDRED;
      break;
    case ROMAN_NUMERAL_LETTER_D:
      arabic_value = ARABIC_VALUE_FIVE_HUNDRED;
      break;
    case ROMAN_NUMERAL_LETTER_M:
      arabic_value = ARABIC_VALUE_ONE_THOUSAND;
      break;
    default:
      break;
  }

  return arabic_value;
}
