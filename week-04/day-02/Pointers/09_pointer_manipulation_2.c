#include <stdio.h>

int main()
{
    int high_number = 6655;
    int low_number = 2;

    int *high_number_pointer = &low_number;
    int *low_number_pointer = &high_number;
    //TODO:
    // Please fix the problem and swap where the pointers point,
    // without using the "&" operator.
    int *tmp_ptr = high_number_pointer;
    high_number_pointer = low_number_pointer;
    low_number_pointer = tmp_ptr;

    printf("high: %d\n", *high_number_pointer);
    printf("low: %d\n", *low_number_pointer);

    return 0;
}
