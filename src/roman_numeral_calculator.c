#include "headers/roman_numeral_calculator.h"

static void request_user_for_roman_numeral_input(char ** roman_numeral);

int main()
{
  printf("Welcome to the Roman Numeral Calculator!\n");

  bool perform_another_calculation = true;
  bool verifying_operation = true;
  bool verifying_second_roman_numeral = true;

  char * user_input = calloc(20, sizeof(char));
  char * first_roman_numeral = calloc(20, sizeof(char));
  char ** first_roman_numeral_pointer;
  first_roman_numeral_pointer = &first_roman_numeral;

  char * second_roman_numeral = calloc(20, sizeof(char));
  char * operation = calloc(20, sizeof(char));

  while (perform_another_calculation)
  {
    printf("Please enter the first roman numeral: ");
    request_user_for_roman_numeral_input(first_roman_numeral_pointer);

    while (verifying_second_roman_numeral)
    {
      printf("Please enter the second roman_numeral: ");
      scanf("%s", user_input);

      if (is_valid_roman_numeral(user_input))
      {
        strcpy(second_roman_numeral, user_input);
        verifying_second_roman_numeral = false;
      } else
      {
        printf("You have entered an invalid roman numeral.\n");
      }

      memset(user_input, 0, strlen(user_input));
    }

    while (verifying_operation)
    {
      printf("Please enter the desired operation (+/-): ");
      scanf("%s", user_input);
      strcpy(operation, user_input);

      memset(user_input, 0, strlen(user_input));

      if (strcmp("+", operation) == 0 || strcmp("-", operation) == 0)
      {
        verifying_operation = false;
      } else
      {
        memset(operation, 0, strlen(operation));
      }
    }

    printf("%s %s %s = TBD\n", first_roman_numeral, operation, second_roman_numeral);

    printf("Would you like to perform another calculation? (Y/N): ");
    scanf("\n%s", user_input);
    if (strcmp("N", user_input) == 0)
    {
      perform_another_calculation = false;
    }

    verifying_operation = true;
    verifying_second_roman_numeral = true;

    memset(user_input, 0, strlen(user_input));
    memset(first_roman_numeral, 0, strlen(first_roman_numeral));
    memset(second_roman_numeral, 0, strlen(second_roman_numeral));
    memset(operation, 0, strlen(operation));
  }

  free(user_input);
  user_input = NULL;
  free(first_roman_numeral);
  first_roman_numeral = NULL;
  first_roman_numeral_pointer = NULL;
  free(second_roman_numeral);
  second_roman_numeral = NULL;
  free(operation);
  operation = NULL;

  return 0;
}


static void request_user_for_roman_numeral_input(char ** roman_numeral)
{
  bool verifying_roman_numeral = true;
  while (verifying_roman_numeral)
  {
    scanf("%s", *roman_numeral);

    if (is_valid_roman_numeral(*roman_numeral))
    {
      verifying_roman_numeral = false;
    }
    else
    {
      printf("Invalid roman numeral. Please try again: ");
      memset(*roman_numeral, 0, strlen(*roman_numeral));
    }
  }
}
