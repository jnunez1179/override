#ifndef SELECT_MEMORY_H
#define SELECT_MEMORY_H

#include <stdint.h>
#include "read_bytes.h"

enum wrong_input {
  WRONG_RANGE = 5,
  OUT_OF_BOUNDS = 6
};

typedef struct size *Bytes;

Bytes select_memory(Buffer input, uint32_t offset_one, uint32_t offset_two);

uint8_t return_memory_byte(Bytes selected_memory, uint8_t offset);
uint8_t return_memory_size(Bytes selected_memory);

void print_selected_bytes(Bytes selected_memory);




#endif
