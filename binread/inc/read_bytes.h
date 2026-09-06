#ifndef READ_WORD_H
#define READ_WORD_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct buffer *Buffer;

Buffer init_buffer();
void create_buffer(Buffer input, FILE *file);
void print_buffer(Buffer input, int bytes_per_line);

uint8_t return_byte(Buffer input, uint32_t offset);
uint8_t return_size(Buffer input);

bool is_end_of_file(Buffer input);



#endif
