#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../inc/read_bytes.h"
#include "../inc/select_memory.h"
#include "../inc/interpret.h"
#include "../inc/user_input.h"
#include <stdio.h>

struct interpret {
  union {
    uint8_t selected_bytes[4];
    union {
      int32_t int32;
      uint32_t uint32;
      float floater;
    } four_bytes;

    union {
      int16_t int16;
      uint16_t uint16;
      short shorter;
    } two_bytes;

    union {
      int8_t int8;
      uint8_t uint8;
      char character;
    } one_byte;
  } memory;
  uint8_t size;
};


char *type_table[] = {"int32", "uint32", "float", "int16", "uint16", "short", "int8", "uint8", "char"};

char *value_type(uint8_t pos)
{
  return type_table[pos];
}


bool test_endianness()
{
  uint16_t val = 0x1234;
  uint8_t byte_val;
  uint8_t *pval;

  pval = (uint8_t *) &val;
  byte_val = (uint8_t) val;

  return (byte_val == *pval) ? LITTLE_ENDIAN : BIG_ENDIAN;
}

Interpretation sort_endianness(Bytes selected_memory, bool machine_endianness, bool input_endianess)
{
  Interpretation interpret = calloc(sizeof(struct interpret), sizeof(return_memory_byte(selected_memory, 0)));

  if (interpret == NULL)
  {
    printf("Could not access memory for interpretation.\n");
    exit(EXIT_FAILURE);
  }

  if (machine_endianness != input_endianess)
  {
    interpret->size = return_memory_size(selected_memory);
    for (uint8_t i = 0; i < interpret->size; i++)
    {
      interpret->memory.selected_bytes[i] = return_memory_byte(selected_memory, i);
    }
  } else {
    interpret->size = return_memory_size(selected_memory);
    for (uint8_t i = interpret->size, j = 0; i > 0; j++)
    {
      interpret->memory.selected_bytes[j] = return_memory_byte(selected_memory, (--i));
    }
  }
  return interpret;
}

void print_interpretation(Interpretation interpretation, uint8_t type)
{
  switch (type)
  {
    case INT32:
      {
        printf("%d\n", interpretation->memory.four_bytes.int32);
        return;
      }
    case UINT32:
      {
        printf("%u\n", interpretation->memory.four_bytes.uint32);
        return;
      }
    case FLOAT:
      {
        printf("%f\n", interpretation->memory.four_bytes.floater);
        return;
      }
    case INT16:
      {
        printf("%hd\n", interpretation->memory.two_bytes.int16);
        return;
      }
    case UINT16:
      {
        printf("%hu\n", interpretation->memory.two_bytes.uint16);
        return;
      }
    case SHORT:
      {
        printf("%hd", interpretation->memory.two_bytes.shorter);
        return;
      }
    case INT8:
      {
        printf("%hhd\n", interpretation->memory.one_byte.int8);
        return;
      }
    case UINT8:
      {
        printf("%hhu\n", interpretation->memory.one_byte.uint8);
        return;
      }
    case CHAR:
      {
        printf("%c\n", interpretation->memory.one_byte.character);
        return;
      }
    default:
      return;
  }
}




