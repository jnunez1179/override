#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "read_bytes.h"

#define ONE_MB 1000000
#define FILE_SIZE ONE_MB

struct buffer{
  uint8_t bytes[FILE_SIZE];
  int current_byte;
  int bytes_per_line;
  int file_size;
};

Buffer init_buffer()
{
  Buffer output = malloc(sizeof(struct buffer));
  if (output == NULL)
  {
    printf("Could not allocate buffer space.\n");
    exit(EXIT_FAILURE);
  }

  memset(output, 0, sizeof(struct buffer));

  return output;
}

void create_buffer(Buffer input, FILE *file)
{
  int ch, i;
  ch = getc(file);
  for (i = 0; (ch != EOF) && (i < FILE_SIZE); i++)
  {
    input->bytes[i] = (uint8_t) ch;

    ch = getc(file);
  }

  if ((ch != EOF) && (i == FILE_SIZE))
  {
    printf("Binary too large (>1MB)\n");
    exit(EXIT_FAILURE);
  }
  input->file_size = i;
}

void print_buffer(Buffer input, int bytes_per_line)
{
  input->bytes_per_line = bytes_per_line;

  int offset = 0;

    while (!is_end_of_file(input))
    {
      printf("%.8X:     ", offset);
      for (int i = 0; (i < input->bytes_per_line) && !is_end_of_file(input); i++)
      {
        printf("%.2hhX ", input->bytes[input->current_byte++]);
      }
      printf("\n");
      offset += input->bytes_per_line;
    }
}


bool is_end_of_file(Buffer input)
{
  return (input->current_byte >= input->file_size);
}

