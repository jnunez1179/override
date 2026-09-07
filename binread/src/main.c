#include <stdint.h>
#include <stdio.h>
#include "inc/read_bytes.h"
#include "inc/select_memory.h"

#define NAME_SIZE 20
#define N_BYTES 4

int main(int argc, char *argv[])
{
  Buffer input;
  Bytes selected_memory;
  int offset = 0;

  FILE *file;

  uint32_t offset_one, offset_two;

  file = fopen(argv[1], "r");

  input = init_buffer();
  create_buffer(input, file);

  printf("Offset        Raw Bytes\n");
  printf("------        ----------\n");

  print_buffer(input, N_BYTES);

  printf("\nEnter the first offset of the Range (Range <= 8 bytes): \n");
  scanf("%8X", &beginning);
  printf("Enter the second offset of the Range (Range <= 8 bytes): \n");
  scanf("%8X", &end);


}
