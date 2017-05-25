#include <stdio.h>
#include <stdlib.h>

/** TODO:
 * Create a function called "range" that creates a new array and returns a pointer to it.
 * It should fill the array with numbers based on it's paramters.
 * It should take 3 paramters:
 * int from: the first number in the array
 * int to: it will fill the array till it would reach this number (so this number is not in the array)
 * int step: the step between the numbers
 *
 * Examples:
 * range(0, 10, 2) -> {0, 2, 4, 6, 8}
 * range(1, -8, -3) -> {1, -2, -5}
 *
 * It should delete any dynamically allocated resource before the program exits.
 */
//void range(int, int, int);
//void print_array(int *array, int step);

int main() {
    int from;
    int to;
    int step;
    printf("Please enter the first number!\n");
    scanf("%d", &from);
    printf("Please enter the last number!\n");
    scanf("%d", &to);
    printf("Please enter the step!\n");
    scanf("%d", &step);
    printf("%d %d %d\n", from, to, step);

    int * array;
    array = (int*) calloc (10, sizeof(int));

    for(int i = from; i < to; i += step){
        array[i] =  i;
        printf("%d \t", array[i]);
    }

   // range(from, to, step);
  //  print_array(array, step);

    free(array);
    return 0;
}

/*
void range(int *array, int from, int to, int step){
    int i;
    for(int i = from; i < to; i++){
        array[i] = i + step;
    }
}

void print_array(int *array, int step){
    int i;
    printf("[");
        for(i = 0; i < n; i++){
            if(i == (n - 1)){
            printf("%d]\n", array[i]);
        }else {
          printf("%d, ", array[i]);
        }
}
*/
