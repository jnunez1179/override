#ifndef INTERPRET_H
#define INTERPRET_H

#define LITTLE_ENDIAN true
#define BIG_ENDIAN false

#include <stdbool.h>
#include <stdint.h>

typedef struct interpret *Interpretation;

char *available_types(uint8_t pos);

bool test_endianness();

#endif
