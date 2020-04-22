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
  Int_array *below_range;
  Int_array *in_range;
  Int_array *above_range;
} Partition;

typedef enum
{
  BELOW,
  BETWEEN,
  ABOVE,
} Range;

void print_int_array(char *, Int_array *);

Int_array *int_array_from(Int_ptr, size_t);

Partition *separate_numbers(Int_ptr, size_t, int, int);