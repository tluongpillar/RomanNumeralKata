#include "headers/roman_numeral.h"

uint is_roman_numeral(char roman_numeral)
{
  if (roman_numeral == NULL)
  {
    return 0;
  }

  char valid_roman_numerals[] = "IVXLCDM";

  int index;
  for (index = 0; index < strlen(valid_roman_numerals); ++index)
  {
    char roman_numeral_uppercase = toupper(roman_numeral);

    if (roman_numeral_uppercase == valid_roman_numerals[index])
    {
      return 1;
    }
  }

  return 0;
}

uint get_arabic_value_from_roman_numeral(char *roman_numeral)
{
  return (roman_numeral[0] == 'I') ? 1 : 0;
}
