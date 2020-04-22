#include "partition.h"

void print_int_array(char message[], Int_array *numbers)
{
  printf("%s\n", message);
  for (size_t i = 0; i < numbers->length; i++)
  {
    printf("%d\n", numbers->values[i]);
  }
  printf("\n");
}

Int_array *int_array_from(Int_ptr numbers, size_t length)
{
  Int_array *int_array = malloc(sizeof(Int_array));
  int_array->length = length;
  int_array->values = malloc(sizeof(int) * length);

  for (size_t i = 0; i < length; i++)
  {
    int_array->values[i] = numbers[i];
  }

  return int_array;
}

Partition *separate_numbers(Int_ptr numbers, size_t length, int num1, int num2)
{
  int category[3][length];
  int count[3] = {0, 0, 0};

  for (size_t i = 0; i < length; i++)
  {
    int selector = numbers[i] < num1 ? 0 : numbers[i] <= num2 ? 1 : 2;
    category[selector][count[selector]] = numbers[i];
    ++count[selector];
  }

  Partition *groups = malloc(sizeof(Partition));
  groups->below_range = int_array_from(category[0], count[0]);
  groups->in_range = int_array_from(category[1], count[1]);
  groups->above_range = int_array_from(category[2], count[2]);

  return groups;
}