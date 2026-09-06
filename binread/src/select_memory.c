#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/read_bytes.h"
#include "../inc/select_memory.h"

#define ENDIAN_VALUES 2

typedef struct {
  union {
    uint8_t selected_bytes[4];
    uint32_t uint32;
    int32_t int32;
    float floater;
  } four_bytes;

  union {
    uint8_t selected_bytes[2];
    uint16_t uint16;
    int16_t int16;
  } two_bytes;

  union {
    uint8_t selected_bytes[1];
    uint8_t uint8;
    int8_t int8;
  } one_byte;
} Size;

bool endianess[ENDIAN_VALUES] = {false};

Memory select_memory(Buffer input, uint32_t beginning, uint32_t end)
{
  Memory m = malloc(sizeof(Size));

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

   int i = 0;
   do {m->memory.selected_bytes[i] = return_byte(input, beginning++);}
   while (i++ < range);

   m->amount_bytes = i;

   return m;
}
