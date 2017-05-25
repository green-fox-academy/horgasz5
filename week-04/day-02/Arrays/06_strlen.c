#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a function which receives a string as parameter, and returns
// the numbers of characters in the string.
// Don't use the strlen() function!
int string_len(char *text);

int main()
{
    char text[100] = "RS5 is the best!";

    printf("%d\n", string_len(text));
    return 0;
}

int string_len(char *text)
{
    int char_num = 0;
    while (text[char_num] != '\0') {
        char_num++;
    }
    return char_num;
}
