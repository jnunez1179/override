#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/read_bytes.h"
#include "../inc/select_memory.h"

#define ENDIAN_VALUES 2

struct size {
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
  uint8_t amount_bytes;
};

bool endianess[ENDIAN_VALUES] = {false};

Bytes select_memory(Buffer input, uint32_t offset_one, uint32_t offset_two)
{
  Bytes m = calloc(return_buffer_size(input), sizeof(return_buffer_byte(input, 0)));

   if (m == NULL)
   {
     printf("Error in finding selected memory storage.\n");
     exit(EXIT_FAILURE);
   }

   uint32_t beginning, end, range;

   if (offset_one < offset_two)
   {
     beginning = offset_one;
     end = offset_two;
   } else {
     beginning = offset_two;
     end = offset_one;
   }

   if (((range = (end - beginning)) >= 4))
   {
     printf("Invalid Range of Offsets.\nEnsure 0 < Range >= 4\n");
     exit(EXIT_FAILURE);
   }
   // Implement functionality to make program prompt another range if range is invalid

   uint32_t i = 0;
   do {m->memory.selected_bytes[i] = return_buffer_byte(input, beginning++);}
   while (i++ < range);

   m->amount_bytes = i;

   return m;
}

uint8_t return_memory_byte(Bytes selected_memory, uint8_t offset)
{
  if (offset >= selected_memory->amount_bytes)
    {
      printf("Reached out of Selected Memory Range.\n");
      exit(EXIT_FAILURE);
    }
  return selected_memory->memory.selected_bytes[offset];
}

uint8_t return_memory_size(Bytes selected_memory)
{
  return selected_memory->amount_bytes;
}
