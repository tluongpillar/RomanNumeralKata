#include "../include/roman_numeral_conversion.h"

static void convert_to_roman_numeral_from_arabic_value_1_through_9(char * roman_numeral, const unsigned int arabic_value);
static void convert_to_roman_numeral_from_arabic_value_10_through_90(char * roman_numeral, const unsigned int arabic_value);
static void convert_to_roman_numeral_from_arabic_value_100_through_900(char * roman_numeral, const unsigned int arabic_value);
static void convert_to_roman_numeral_from_arabic_value_1000_through_3000(char * roman_numeral, const unsigned int arabic_value);


void convert_to_roman_numeral_from_arabic_value(char * roman_numeral, const unsigned int arabic_value)
{
  convert_to_roman_numeral_from_arabic_value_1000_through_3000(roman_numeral, arabic_value);
  convert_to_roman_numeral_from_arabic_value_100_through_900(roman_numeral, arabic_value);
  convert_to_roman_numeral_from_arabic_value_10_through_90(roman_numeral, arabic_value);
  convert_to_roman_numeral_from_arabic_value_1_through_9(roman_numeral, arabic_value);
}

unsigned int convert_to_arabic_value_from_roman_numeral(const char * roman_numeral)
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
      }
      else
      {
        arabic_value += current_roman_numeral_letter_arabic_value;
      }
    }
  }

  return arabic_value;
}

static void convert_to_roman_numeral_from_arabic_value_1_through_9(char * roman_numeral, const unsigned int arabic_value)
{
  switch (arabic_value % 10)
  {
    case 1:
    strcat(roman_numeral, "I");
    break;
    case 2:
    strcat(roman_numeral, "II");
    break;
    case 3:
    strcat(roman_numeral, "III");
    break;
    case 4:
    strcat(roman_numeral, "IV");
    break;
    case 5:
    strcat(roman_numeral, "V");
    break;
    case 6:
    strcat(roman_numeral, "VI");
    break;
    case 7:
    strcat(roman_numeral, "VII");
    break;
    case 8:
    strcat(roman_numeral, "VIII");
    break;
    case 9:
    strcat(roman_numeral, "IX");
    break;
    default:
    break;
  }
}

static void convert_to_roman_numeral_from_arabic_value_10_through_90(char * roman_numeral, const unsigned int arabic_value)
{
  unsigned int arabic_value_tens_digit = arabic_value / 10;

  switch (arabic_value_tens_digit % 10)
  {
    case 1:
    strcat(roman_numeral, "X");
    break;
    case 2:
    strcat(roman_numeral, "XX");
    break;
    case 3:
    strcat(roman_numeral, "XXX");
    break;
    case 4:
    strcat(roman_numeral, "XL");
    break;
    case 5:
    strcat(roman_numeral, "L");
    break;
    case 6:
    strcat(roman_numeral, "LX");
    break;
    case 7:
    strcat(roman_numeral, "LXX");
    break;
    case 8:
    strcat(roman_numeral, "LXXX");
    break;
    case 9:
    strcat(roman_numeral, "XC");
    break;
    default:
    break;
  }
}

static void convert_to_roman_numeral_from_arabic_value_100_through_900(char * roman_numeral, const unsigned int arabic_value)
{
  unsigned int arabic_value_hundreds_digit = arabic_value / 100;

  switch (arabic_value_hundreds_digit % 10)
  {
    case 1:
    strcat(roman_numeral, "C");
    break;
    case 2:
    strcat(roman_numeral, "CC");
    break;
    case 3:
    strcat(roman_numeral, "CCC");
    break;
    case 4:
    strcat(roman_numeral, "CD");
    break;
    case 5:
    strcat(roman_numeral, "D");
    break;
    case 6:
    strcat(roman_numeral, "DC");
    break;
    case 7:
    strcat(roman_numeral, "DCC");
    break;
    case 8:
    strcat(roman_numeral, "DCCC");
    break;
    case 9:
    strcat(roman_numeral, "CM");
    break;
    default:
    break;
  }
}

static void convert_to_roman_numeral_from_arabic_value_1000_through_3000(char * roman_numeral, const unsigned int arabic_value)
{
  unsigned int arabic_value_thousands_digit = arabic_value / 1000;

  switch (arabic_value_thousands_digit % 4)
  {
    case 1:
    strcat(roman_numeral, "M");
    break;
    case 2:
    strcat(roman_numeral, "MM");
    break;
    case 3:
    strcat(roman_numeral, "MMM");
    break;
    default:
    break;
  }
}
