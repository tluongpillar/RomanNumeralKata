#include "headers/roman_numeral_calculator.h"

int main()
{
  printf("Welcome to the Roman Numeral Calculator!\n");

  bool perform_another_calculation = true;
  char * user_input = calloc(20, sizeof(char));

  char * first_roman_numeral = calloc(20, sizeof(char));
  char * second_roman_numeral = calloc(20, sizeof(char));
  char * operation = calloc(20, sizeof(char));

  while (perform_another_calculation)
  {
    printf("Please enter the first roman_numeral: ");
    scanf("%s", user_input);
    strcpy(first_roman_numeral, user_input);
    memset(user_input, 0, strlen(user_input));

    printf("Please enter the second roman_numeral: ");
    scanf("%s", user_input);
    strcpy(second_roman_numeral, user_input);
    memset(user_input, 0, strlen(user_input));

    printf("Please enter the desired operation (+/-): ");
    scanf("%s", user_input);
    strcpy(operation, user_input);
    memset(user_input, 0, strlen(user_input));

    printf("%s %s %s = TBD\n", first_roman_numeral, operation, second_roman_numeral);

    printf("Would you like to perform another calculation? (Y/N): ");
    scanf("\n%s", user_input);
    if (strcmp("N", user_input) == 0)
    {
      perform_another_calculation = false;
    }
    memset(user_input, 0, strlen(user_input));
    memset(first_roman_numeral, 0, strlen(first_roman_numeral));
    memset(second_roman_numeral, 0, strlen(second_roman_numeral));
    memset(operation, 0, strlen(operation));

  }

  free(user_input);
  user_input = NULL;
  free(first_roman_numeral);
  first_roman_numeral = NULL;
  free(second_roman_numeral);
  second_roman_numeral = NULL;
  free(operation);
  operation = NULL;

  return 0;
}
