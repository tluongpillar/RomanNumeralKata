#include "../include/roman_numeral_conversion.h"

static const int return_value_when_null_pointer_detected = -9999;

static const char * roman_numeral_ones_digit[10] = {
  "\0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
};
static const char * roman_numeral_tens_digit[10] = {
  "\0", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
};
static const char * roman_numeral_hundreds_digit[10] = {
  "\0", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
};
static const char * roman_numeral_thousands_digit[4] = {
  "\0", "M", "MM", "MMM"
};

static void convert_to_roman_numeral_from_arabic_value_1_through_9(char * roman_numeral, const int arabic_value);
static void convert_to_roman_numeral_from_arabic_value_10_through_90(char * roman_numeral, const int arabic_value);
static void convert_to_roman_numeral_from_arabic_value_100_through_900(char * roman_numeral, const int arabic_value);
static void convert_to_roman_numeral_from_arabic_value_1000_through_3000(char * roman_numeral, const int arabic_value);

bool convert_to_roman_numeral_from_arabic_value(char * roman_numeral, const int arabic_value)
{
  bool success = false;

  if (roman_numeral && arabic_value >= 0 && arabic_value <= MAX_ROMAN_NUMERAL_ARABIC_VALUE)
  {
    convert_to_roman_numeral_from_arabic_value_1000_through_3000(roman_numeral, arabic_value);
    convert_to_roman_numeral_from_arabic_value_100_through_900(roman_numeral, arabic_value);
    convert_to_roman_numeral_from_arabic_value_10_through_90(roman_numeral, arabic_value);
    convert_to_roman_numeral_from_arabic_value_1_through_9(roman_numeral, arabic_value);
    success = true;
  }

  return success;
}

int convert_to_arabic_value_from_roman_numeral(const char * roman_numeral)
{
  if (!roman_numeral)
  {
    return return_value_when_null_pointer_detected;
  }

  int arabic_value = 0;

  int roman_numeral_count = strlen(roman_numeral);

  int index;
  char current_roman_numeral_letter;
  char next_roman_numeral_letter;
  int current_roman_numeral_letter_arabic_value;
  int next_roman_numeral_letter_arabic_value;

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

static void convert_to_roman_numeral_from_arabic_value_1_through_9(char * roman_numeral, const int arabic_value)
{
  int index = arabic_value % 10;
  strcat(roman_numeral, roman_numeral_ones_digit[index]);
}

static void convert_to_roman_numeral_from_arabic_value_10_through_90(char * roman_numeral, const int arabic_value)
{
  int arabic_value_tens_digit = arabic_value / 10;

  int index = arabic_value_tens_digit % 10;
  strcat(roman_numeral, roman_numeral_tens_digit[index]);
}

static void convert_to_roman_numeral_from_arabic_value_100_through_900(char * roman_numeral, const int arabic_value)
{
  int arabic_value_hundreds_digit = arabic_value / 100;

  int index = arabic_value_hundreds_digit % 10;
  strcat(roman_numeral, roman_numeral_hundreds_digit[index]);
}

static void convert_to_roman_numeral_from_arabic_value_1000_through_3000(char * roman_numeral, const int arabic_value)
{
  int arabic_value_thousands_digit = arabic_value / 1000;

  int index = arabic_value_thousands_digit % 10;
  strcat(roman_numeral, roman_numeral_thousands_digit[index]);
}
