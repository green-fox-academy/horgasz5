#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Print out the addresses with and without pointer
print out the values with and without pointer
 */


int main()
{
    int number = 2017;
    float Pi = 3.14;
    char letter = 't';

    int *number_ptr = &number;
    float *Pi_ptr = &Pi;
    char *letter_ptr = &letter;

    printf("%p\n", &number);
    printf("%p\n", &Pi);
    printf("%p\n", &letter);

    printf("%p\n", number_ptr);
    printf("%p\n", Pi_ptr);
    printf("%p\n", letter_ptr);

    printf("%d\n", *number_ptr);
    printf("%f\n", *Pi_ptr);
    printf("%c\n", *letter_ptr);

    printf("%d\n", number);
    printf("%f\n", Pi);
    printf("%c\n", letter);

    return 0;
}
