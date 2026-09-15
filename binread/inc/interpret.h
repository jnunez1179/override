#ifndef INTERPRET_H
#define INTERPRET_H

#define N_TYPES 9
#define LITTLE_ENDIAN true
#define BIG_ENDIAN false

#include <stdbool.h>
#include <stdint.h>
#include "select_memory.h"

typedef struct interpret *Interpretation;

char *value_type(uint8_t pos);

Interpretation sort_endianness(Bytes selected_memory, bool machine_endianness, bool input_endianess);
void print_interpretation(Interpretation interpretation, uint8_t type);

bool test_endianness();

#endif
