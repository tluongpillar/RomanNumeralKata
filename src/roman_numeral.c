#include "headers/roman_numeral.h"

uint is_roman_numeral(char roman_numeral)
{
  char valid_roman_numerals[] = "IVXLCDM";
  int valid_roman_numerals_count = sizeof(valid_roman_numerals) / sizeof(valid_roman_numerals[0]);

  int index;
  for (index = 0; index < valid_roman_numerals_count; ++index)
  {
    if (roman_numeral == valid_roman_numerals[index])
    {
      return 1;
    }
  }

  return 0;
}
