#include <stdint.h>
#include <stdbool.h>
#include "../inc/read_bytes.h"
#include "../inc/select_memory.h"
#include "../inc/interpret.h"

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

char *available_types(uint8_t pos)
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

char *interpret_memory(Bytes selected_memory, bool machine_endianness, bool input_endianess, char *type)
{

}

