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

#define MAX_ROMAN_NUMERAL "MMMCMXCIX"

#define ARABIC_VALUE_ZERO 0
#define ARABIC_VALUE_ONE 1
#define ARABIC_VALUE_FIVE 5
#define ARABIC_VALUE_TEN 10
#define ARABIC_VALUE_FIFTY 50
#define ARABIC_VALUE_ONE_HUNDRED 100
#define ARABIC_VALUE_FIVE_HUNDRED 500
#define ARABIC_VALUE_ONE_THOUSAND 1000
#define MAX_ROMAN_NUMERAL_ARABIC_VALUE 3999

bool is_roman_numeral_letter(const char roman_numeral_letter);
int get_arabic_value_from_roman_numeral_letter(const char roman_numeral_letter);
char get_roman_numeral_letter_from_arabic_value(const int arabic_value);
