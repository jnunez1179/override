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
  file = fopen(argv[1], "r");

  input = init_buffer();
  create_buffer(input, file);

  printf("Offset        Raw Bytes\n");
  printf("------        ----------\n");

  print_buffer(input, N_BYTES);

  uint32_t offset_one, offset_two;
  printf("\nEnter the first offset of the Range (Range <= 4 bytes): \n");
  scanf("%8X", &offset_one);
  printf("Enter the second offset of the Range (Range <= 4 bytes): \n");
  scanf("%8X", &offset_two);

  eat_input(stdin);

  selected_memory = select_memory(input, offset_one, offset_two);

  printf("Range of Bytes: \n");
  print_selected_bytes(selected_memory);

  bool machine_endianness = test_endianness();

  uint8_t input_endianess;
  if ((return_memory_size(selected_memory)) > 1)
  {
    printf("What endianness will the value use? (big/little)\n");

    for (;;)
    {
      input_endianess = parse_endianness(stdin);
      if (input_endianess != WRONG_INPUT)
      {
        break;
      }
      printf("Please enter \"big\" or \"little\"\n");
    }
  }
  printf("Endianness Output: %hhu\n", input_endianess);
}

