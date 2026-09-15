#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "../inc/read_bytes.h"
#include "../inc/select_memory.h"
#include "../inc/interpret.h"
#include "../inc/user_input.h"

#define NAME_SIZE 20
#define N_BYTES 4

int main(int argc, char *argv[])
{
  Buffer input;

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

  Bytes selected_memory;
  selected_memory = select_memory(input, offset_one, offset_two);

  printf("Range of Bytes: \n");
  print_selected_bytes(selected_memory);

  bool machine_endianness = test_endianness();

  uint8_t input_endianess = 0;
  if ((return_memory_size(selected_memory)) > 1)
  {
    printf("\nWhat endianness will the value use? (big/little)\n");

    do {
      input_endianess = parse_endianness(stdin);
      if (input_endianess == WRONG_ENDIAN_INPUT)
      {
        printf("Please enter \"big\" or \"little\"\n");
      }
    } while (input_endianess == WRONG_ENDIAN_INPUT);
  }

  printf("\nWhat Type Would You Like Your Range of Values to be Interpreted As?\n");

  uint8_t input_type = 0;
  do {
    printf("\nOptions: (\"exit\" to exit )\n");
    for (uint8_t i = 0; i < N_TYPES; i++)
    {
      printf("%s\n", value_type(i));
    }

    printf("\nArranged Bytes:\n");

    Interpretation interpretation;
    interpretation = sort_endianness(selected_memory, machine_endianness, input_endianess);
    print_interpreted_bytes(interpretation);

    input_type = parse_type(stdin);
    if (input_type == WRONG_TYPE_INPUT)
    {
      printf("\nNot an option.\n");
    }
    printf("-------------\nValue: ");
    print_interpretation(interpretation, input_type);

  } while ((input_type == WRONG_TYPE_INPUT) || (input_type != EXIT));

}

