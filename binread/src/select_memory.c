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

  uint32_t range = end - beginning + 1;

  if ((range > 0) && (range <=7))
  {
    int i;
    for (i = 0; i < range; i++)
      m->one_byte.selected_bytes[i] = *input->address++];
  } else if ((range > 7) && (range <= 15))
  {
    for (int i = 0; i < range; i++)
      m->one_byte.selected_bytes[i] = *input->address++];
  } else {
    for (int i = 0; i < range; i++)
      m->one_byte.selected_bytes[i] = *input->address++];
  }
  return m;
}
