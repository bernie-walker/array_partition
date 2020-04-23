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

Partition *create_groups(size_t n, int ranges[3][n], size_t count[3])
{
  Partition *groups = malloc(sizeof(Partition));

  groups->below_range = int_array_from(ranges[BELOW], count[BELOW]);
  groups->in_range = int_array_from(ranges[BETWEEN], count[BETWEEN]);
  groups->above_range = int_array_from(ranges[ABOVE], count[ABOVE]);

  return groups;
}

Range decide_range(int number, int limit1, int limit2)
{
  int higher_limit = limit1 > limit2 ? limit1 : limit2;
  int lower_limit = limit1 < limit2 ? limit1 : limit2;

  if (number < lower_limit)
  {
    return BELOW;
  }

  return number <= higher_limit ? BETWEEN : ABOVE;
}

Partition *separate_numbers(Int_ptr numbers, size_t length, int num1, int num2)
{
  int category[3][length];
  size_t count[3] = {0, 0, 0};

  for (size_t i = 0; i < length; i++)
  {
    int selector = decide_range(numbers[i], num1, num2);
    category[selector][count[selector]] = numbers[i];
    ++count[selector];
  }

  return create_groups(length, category, count);
}