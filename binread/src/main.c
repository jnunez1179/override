#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "../inc/read_bytes.h"
#include "../inc/select_memory.h"
#include "../inc/interpret.h"
#include "../inc/user_input.h"


#define NAME_SIZE 20
#define N_BYTES 4
#define N_TYPES 9

int main(int argc, char *argv[])
{
  Buffer input;
  Bytes selected_memory;

  FILE *file;

  uint32_t offset_one, offset_two;

  file = fopen(argv[1], "r");

  input = init_buffer();
  create_buffer(input, file);

  printf("Offset        Raw Bytes\n");
  printf("------        ----------\n");

  print_buffer(input, N_BYTES);

  printf("\nEnter the first offset of the Range (Range <= 4 bytes): \n");
  scanf("%8X", &offset_one);
  printf("Enter the second offset of the Range (Range <= 4 bytes): \n");
  scanf("%8X", &offset_two);


  selected_memory = select_memory(input, offset_one, offset_two);

  printf("Range of Bytes: \n");

  print_selected_bytes(selected_memory);

  bool machine_endianness;

  machine_endianness = test_endianness();


