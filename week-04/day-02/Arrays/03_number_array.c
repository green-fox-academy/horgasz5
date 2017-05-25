#include <stdio.h>

int main()
{
    int int_array[] = {1, 654, 987, 654, 31};
    float float_array[] = {1.2, 3.14, 1.41, 0.707, 1.73};

    //TODO:
    // Print out the content of the arrays
    int int_array_len = sizeof(int_array) / sizeof(int_array[0]);

    for (int i = 0; i < int_array_len; i++) {
        printf("%d, ", int_array[i]);
    }
    printf("\n");

    int float_array_len = sizeof(float_array) / sizeof(float_array[0]);

    for (int i = 0; i < float_array_len; i++) {
        printf("%.3f, ", float_array[i]);
    }
    printf("\n");

    return 0;
}
