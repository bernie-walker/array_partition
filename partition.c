#include <stdio.h>
#include <stdlib.h>

typedef int *Int_ptr;

typedef struct
{
  size_t length;
  Int_ptr values;
} Int_array;
