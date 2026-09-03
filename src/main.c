#include <stdint.h>
#include <stdio.h>
#include "inc/read_bytes.h"

#define NAME_SIZE 20
#define N_BYTES 4

int main(int argc, char *argv[])
{
  Buffer input;
  int offset = 0;

  FILE *file;

  file = fopen(argv[1], "r");

  input = init_buffer();
  create_buffer(input, file);

  printf("Offset        Raw Bytes\n");
  printf("------        ----------\n");

  print_buffer(input, N_BYTES);
}
