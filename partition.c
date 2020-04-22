#include "partition.h"

void print_int_array(char message[], Int_array *numbers)
{
  printf("%s\n", message);
  for (size_t i = 0; i < numbers->length; i++)
  {
    printf("%d\n", numbers->values[i]);
  }
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