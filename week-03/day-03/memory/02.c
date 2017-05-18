#include <stdio.h>
#include <stdlib.h>

// TODO:
// Please create a program that asks for a count when it starts.
// It should ask for a number count times, then it shoud print the average of the numbers.
// It should delete any dynamically allocated resource before the program exits.

int main() {
    int temp = 0;
    printf("Please enter the count!\n");
    int count;
    scanf("%d", &count);

    int * array;
    array = (int*) calloc (count , sizeof(int));
    for(int i = 0; i < count; i++){
        printf("Please enter the [%d]th  number!\n", i+1);
        scanf("%d", &array[i]);
        //printf("The array's [%d]th element: %d\n", i, array[i]);
        temp = temp + array[i];

    }
    //printf("%d\n", temp);
    float avg = (float)temp / count;
    printf("The average of the numbers: %.2f\n", avg);

    free(array);
    return 0;
}
