#include <stdio.h>
#include "partition.h"

int main(void)
{
  int original[8] = {3, 1, 7, 4, 6, 5, 8, 2};
  Partition *groups = separate_numbers(original, 8, 4, 7);

  print_int_array("Below range", groups->below_range);
  print_int_array("In range", groups->in_range);
  print_int_array("Above range", groups->above_range);

  return 0;
}