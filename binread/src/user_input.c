#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include "../inc/user_input.h"
#include "../inc/interpret.h"


uint8_t parse_endianness(FILE *std_in)
{
    char input_endianess[ENDIAN_BUFFER_SIZE] = {0};
    size_t input_endianness_size;

    fgets(input_endianess, ENDIAN_BUFFER_SIZE, std_in);
    input_endianness_size = strnlen(input_endianess, ENDIAN_BUFFER_SIZE);

    if (((strncmp(input_endianess, "big\n", 4)) != 0) && ((strncmp(input_endianess, "little\n", 7)) != 0) && ((strncmp(input_endianess, "exit\n", 6))))
    {
      if (!is_new_line(input_endianess, input_endianness_size))
      {
        eat_input(std_in);
      }
      return WRONG_ENDIAN_INPUT;
    }

    if (((strncmp(input_endianess, "big\n", 4)) == 0))
    {
      return BIG;
    }

    if ((strncmp(input_endianess, "little\n", 7)) == 0)
    {
      return LITTLE;
    }

    if ((strncmp(input_endianess, "exit\n", 6)) == 0)
    {
      return ENDIAN_EXIT;
    }
    return WRONG_ENDIAN_INPUT;
}

uint8_t parse_type(FILE* std_in)
{
  uint8_t type_array[] = {INT32, UINT32, FLOAT, INT16, UINT16, SHORT, INT8, UINT8, CHAR, EXIT, WRONG_TYPE_INPUT };

  for (;;)
  {
    char type_input[TYPE_BUFFER_SIZE] = {0};
    fgets(type_input, TYPE_BUFFER_SIZE, std_in);
    char *cleaned_type_input;

    if (is_new_line(type_input, TYPE_BUFFER_SIZE))
    {
      cleaned_type_input = remove_new_line(type_input);
    } else {
      eat_input(std_in);
    }


    for (uint8_t i = 0; i < TYPE_COUNT; i++)
    {
      if ((strcmp(value_type(i), cleaned_type_input) == 0))
      {
        return type_array[i];
      }
    }
    return WRONG_TYPE_INPUT;
  }
}

void eat_input(FILE *std_in)
{
  int ch;
  while (((ch = getc(std_in)) != '\n') && (ch != EOF)) {}
}

bool is_new_line(char *str, size_t size)
{
  for (uint8_t i = 0; i < size; i++)
  {
    if (str[i] == '\n')
      return true;
  }
  return false;
}

char *remove_new_line(char *str)
{
  uint8_t i = 0;
  while ((*(str + i++) != '\n')) {}
  *(str + --i) = '\0';

  return str;
}

