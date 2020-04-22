#include <stdio.h>
#include "partition.h"

int main(void)
{
  int z[3] = {1, 2, 3};
  Int_array x = {3, z};

  print_int_array("original array", &x);

  return 0;
}