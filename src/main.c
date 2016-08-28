#include "headers/main.h"

static void request_user_for_roman_numeral_input(char ** roman_numeral);
static void request_user_for_operation_input(char ** operation);
static bool request_user_to_continue();

int main()
{
  printf("Welcome to the Roman Numeral Calculator!\n");

  bool continue_running = true;

  char * first_roman_numeral = calloc(20, sizeof(char));
  char ** first_roman_numeral_pointer;
  first_roman_numeral_pointer = &first_roman_numeral;

  char * second_roman_numeral = calloc(20, sizeof(char));
  char ** second_roman_numeral_pointer;
  second_roman_numeral_pointer = &second_roman_numeral;

  char * operation = calloc(20, sizeof(char));
  char ** operation_pointer;
  operation_pointer = &operation;

  while (continue_running)
  {
    printf("Please enter the first roman numeral: ");
    request_user_for_roman_numeral_input(first_roman_numeral_pointer);

    printf("Please enter the second roman numeral: ");
    request_user_for_roman_numeral_input(second_roman_numeral_pointer);

    printf("Please enter the desired operation (+/-): ");
    request_user_for_operation_input(operation_pointer);

    printf("%s %s %s = TBD\n", first_roman_numeral, operation, second_roman_numeral);

    printf("Would you like to perform another calculation? (Y/N): ");
    continue_running = request_user_to_continue();

    memset(first_roman_numeral, 0, strlen(first_roman_numeral));
    memset(second_roman_numeral, 0, strlen(second_roman_numeral));
    memset(operation, 0, strlen(operation));
  }

  free(first_roman_numeral);
  first_roman_numeral = NULL;
  first_roman_numeral_pointer = NULL;
  free(second_roman_numeral);
  second_roman_numeral = NULL;
  second_roman_numeral_pointer = NULL;
  free(operation);
  operation = NULL;
  operation_pointer = NULL;

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

static void request_user_for_operation_input(char ** operation)
{
  bool verifying_operation = true;
  while (verifying_operation)
  {
    scanf("%s", *operation);

    if (strcmp("+", *operation) == 0 || strcmp("-", *operation) == 0)
    {
      verifying_operation = false;
    } else
    {
      printf("Invalid operation. Please try again (+/-): ");
      memset(*operation, 0, strlen(*operation));
    }
  }
}

static bool request_user_to_continue()
{
  bool continue_running;
  char * user_input = calloc(20, sizeof(char));

  bool verifying_input = true;
  while (verifying_input)
  {
      scanf("%s", user_input);
      switch (user_input[0])
      {
        case 'N':
        continue_running = false;
        verifying_input = false;
        break;
        case 'Y':
        continue_running = true;
        verifying_input = false;
        break;
        default:
        printf("Invalid selection. Please try again (Y/N): ");
        memset(user_input, 0, strlen(user_input));
        break;
      }
  }

  free(user_input);
  user_input = NULL;

  return continue_running;
}
