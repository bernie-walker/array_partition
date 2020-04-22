#include <stdio.h>
#include "partition.h"

int main(void)
{
  int z[3] = {1, 2, 3};
  Int_array *original = int_array_from(z, 3);

  print_int_array("original array", original);

  return 0;
}