#include <stdio.h>
#include <stdlib.h>

// TODO:
// Please create a program that asks for a count when it starts.
// It should ask for a number count times, then it shoud print the average of the numbers.
// It should delete any dynamically allocated resource before the program exits.

int main()
{
    int count;
    float sum = 0;
    float temp_int = 0;
    printf("Please add the value of the count:\n");
    scanf("%d", &count);
    printf("%d\n", count);

    int *pointer = (int*)calloc(count, sizeof(int));
    for (int i = 0; i < count; i++) {
        printf("Please add a number!\n");
        scanf("%f", &temp_int);
        sum += temp_int; // == sum = sum + temp_int;
    }

    printf("The average of the numbers: %.2f\n", sum/count);

    free(*pointer);

    return 0;
}
