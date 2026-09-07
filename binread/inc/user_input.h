#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

enum endian {
  BIG = 0,
  LITTLE = 1,
  WRONG_INPUT = 2,
};

uint8_t parse_endianness(FILE *std_in);

void eat_input(FILE *std_in);
bool is_new_line(char *str, size_t size);




#endif

