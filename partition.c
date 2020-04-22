#include "partition.h"

void print_int_array(char message[], Int_array *integers)
{
  printf("%s\n", message);
  for (size_t i = 0; i < integers->length; i++)
  {
    printf("%d\n", integers->values[i]);
  }
}