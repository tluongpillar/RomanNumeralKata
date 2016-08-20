#include "headers/roman_numeral.h"

bool is_roman_numeral(char roman_numeral)
{
  char valid_roman_numerals[] = "IVXLCDM";

  int index;
  for (index = 0; index < strlen(valid_roman_numerals); ++index)
  {
    char roman_numeral_uppercase = toupper(roman_numeral);

    if (roman_numeral_uppercase == valid_roman_numerals[index])
    {
      return true;
    }
  }

  return false;
}

unsigned int get_arabic_value_from_roman_numeral(char *roman_numeral)
{
  return (roman_numeral[0] == 'I') ? 1 : 0;
}
