#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ROMAN_NUMERAL_LETTERS_COUNT 7

#define ROMAN_NUMERAL_LETTER_I 'I'
#define ROMAN_NUMERAL_LETTER_V 'V'
#define ROMAN_NUMERAL_LETTER_X 'X'
#define ROMAN_NUMERAL_LETTER_L 'L'
#define ROMAN_NUMERAL_LETTER_C 'C'
#define ROMAN_NUMERAL_LETTER_D 'D'
#define ROMAN_NUMERAL_LETTER_M 'M'

bool is_roman_numeral(char roman_numeral);
unsigned int get_arabic_value_from_roman_numeral(char roman_numeral);
