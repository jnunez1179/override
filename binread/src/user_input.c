#include <endian.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/user_input.h"

#define ENDIAN_BUFFER_SIZE 8

uint8_t parse_endianness(FILE *std_in)
{
    char input_endianess[ENDIAN_BUFFER_SIZE] = {0};
    size_t input_endianness_size;

    fgets(input_endianess, ENDIAN_BUFFER_SIZE, std_in);
    input_endianness_size = strnlen(input_endianess, ENDIAN_BUFFER_SIZE);

    if (((strncmp(input_endianess, "big\n", 4)) != 0) && ((strncmp(input_endianess, "little\n", 7)) != 0))
    {
      if (!is_new_line(input_endianess, input_endianness_size))
      {
        eat_input(std_in);
      }
      return WRONG_INPUT;
    }

    if (((strncmp(input_endianess, "big\n", 4)) == 0))
    {
      return BIG;
    }

    if ((strncmp(input_endianess, "little\n", 7)) == 0)
    {
      return LITTLE;
    }
    return WRONG_INPUT;
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

