#ifndef INTERPRET_H
#define INTERPRET

#include <stdbool.h>
#include <stdint.h>

typedef struct interpret *Interpretation;

char *available_types(uint8_t pos);

#endif
