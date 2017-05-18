#include <stdio.h>
#include <stdlib.h>

int main() {
  int* pointer = NULL;

  // TODO:
  // Please allocate a 5 long array and fill it with numbers from 0 to 4, then print the whole array
  // Please delete the array before the program exits
  int * array;
  array = (int*) calloc (5 , sizeof(int));
  for(int i = 0; i < 5; i++){
    array[i] = i;
    printf("The array's [%d]th element: %d\n", i, array[i]);
  }

  free (array);
  return 0;
}
