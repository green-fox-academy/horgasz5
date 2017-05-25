#include <stdio.h>
#include <string.h>

int main()
{
    char my_name_array[] = "My Name";

    //TODO:
    // Print out the array character-by-character
    int array_len = sizeof(my_name_array) / sizeof(my_name_array[0]);

    for (int i = 0; i < array_len; i++) {
        printf("%c", my_name_array[i]);
    }
    printf("\n");

    return 0;
}
