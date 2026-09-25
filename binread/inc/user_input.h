#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define ENDIAN_BUFFER_SIZE 8
#define TYPE_BUFFER_SIZE 8

enum endian {
  BIG = 0,
  LITTLE = 1,
  WRONG_ENDIAN_INPUT = 2,
  ENDIAN_EXIT = 3
};

enum type {
  INT32 = 0,
  UINT32 = 1,
  FLOAT = 2,
  INT16 = 3,
  UINT16 = 4,
  SHORT = 5,
  INT8 = 6,
  UINT8 = 7,
  CHAR = 8,
  EXIT = 9,
  TYPE_COUNT = 10,
  WRONG_TYPE_INPUT = 11,
};

uint8_t parse_endianness(FILE *std_in);
uint8_t parse_type(FILE* std_in);


void eat_input(FILE *std_in);

bool is_new_line(char *str, size_t size);
char *remove_new_line(char *str);




#endif

