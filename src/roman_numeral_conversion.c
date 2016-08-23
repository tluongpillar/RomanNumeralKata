#include "headers/roman_numeral_conversion.h"

void convert_to_roman_numeral_from_arabic_value(char ** roman_numeral, unsigned int arabic_value)
{
  switch (arabic_value)
  {
    case 1:
    strcat(*roman_numeral, "I");
    break;
    case 2:
    strcat(*roman_numeral, "II");
    break;
    default:
    *roman_numeral = "\0";
    break;
  }
}

unsigned int convert_to_arabic_value_from_roman_numeral(char * roman_numeral)
{
  int arabic_value = 0;

  int roman_numeral_count = strlen(roman_numeral);

  int index;
  char current_roman_numeral_letter;
  char next_roman_numeral_letter;
  unsigned int current_roman_numeral_letter_arabic_value;
  unsigned int next_roman_numeral_letter_arabic_value;

  for (index = 0; index < roman_numeral_count; ++index)
  {
    current_roman_numeral_letter = roman_numeral[index];

    if (is_roman_numeral_letter(current_roman_numeral_letter))
    {
      next_roman_numeral_letter = roman_numeral[index + 1];

      current_roman_numeral_letter_arabic_value = get_arabic_value_from_roman_numeral_letter(current_roman_numeral_letter);
      next_roman_numeral_letter_arabic_value = get_arabic_value_from_roman_numeral_letter(next_roman_numeral_letter);

      if (next_roman_numeral_letter_arabic_value > current_roman_numeral_letter_arabic_value)
      {
        arabic_value -= current_roman_numeral_letter_arabic_value;
      } else
      {
        arabic_value += current_roman_numeral_letter_arabic_value;
      }
    }
  }

  return arabic_value;
}
