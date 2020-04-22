#include <stdio.h>
#include <stdlib.h>

typedef int *Int_ptr;

typedef struct
{
  size_t length;
  Int_ptr values;
} Int_array;

typedef struct
{
  Int_array below_range;
  Int_array above_range;
  Int_array in_range;
} Partition;

void print_int_array(char *, Int_array *);

Int_array *int_array_from(Int_ptr, size_t);