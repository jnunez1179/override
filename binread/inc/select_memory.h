#ifndef SELECT_MEMORY_H
#define SELECT_MEMORY_H

#include <stdint.h>
#include "read_bytes.h"

typedef struct size *Bytes;

Bytes select_memory(Buffer input, uint32_t offset_one, uint32_t offset_two);


#endif
