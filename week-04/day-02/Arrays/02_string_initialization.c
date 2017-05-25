#include <stdio.h>

int main()
{
    char char_array[] = {'a', 'b', 'c', 'd'};
    char char_array_the_same[] = "abcd";

    //TODO:
    // Print out the two arrays character-by-character
    int array_len1 = sizeof(char_array) / sizeof(char_array[0]);

    for (int i = 0; i < array_len1; i++) {
        printf("%c", char_array[i]);
    }
    printf("\n");
    //TODO:
    // What is the difference between the arrays?
    int array_len2 = sizeof(char_array_the_same) / sizeof(char_array_the_same[0]);

    for (int i = 0; i < array_len2; i++) {
        printf("%c", char_array_the_same[i]);
    }
    printf("\n");
    printf("%d\n", array_len1);
    printf("%d\n", array_len2);
    //  a masodik tombnel van egy new line karakter is...
    return 0;
}
