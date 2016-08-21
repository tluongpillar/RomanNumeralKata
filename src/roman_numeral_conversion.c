#include "headers/roman_numeral_conversion.h"

unsigned int convert_to_arabic_value_from_roman_numeral(char roman_numeral[])
{
  int arabic_value = 0;

  int roman_numeral_count = strlen(roman_numeral);

  int index;
  for (index = 0; index < roman_numeral_count; ++index)
  {
    if (is_roman_numeral_letter(roman_numeral[index]))
    {
      arabic_value += get_arabic_value_from_roman_numeral_letter(roman_numeral[index]);
    }
  }

  return arabic_value;
}
