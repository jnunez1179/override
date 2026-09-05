#ifndef SELECT_MEMORY_H
#define SELECT_MEMORY_H

#include <stdint.h>

typedef Size *Memory;

Memory select_memory(Buffer input, uint32_t beginning, uint32_t end);


#endif
