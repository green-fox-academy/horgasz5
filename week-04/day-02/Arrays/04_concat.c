#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TODO: Implement a function that concatenates 2 strings (dest and source).
The return value should be the concatenated strings.
*/
void concat();
char first[] = "My name is";
char second[] = "Peter";

int main()
{
    //char first[] = "My name is ";
    //char second[] = "Peter";

    concat();

    return 0;
}

void concat()
{
    char result[255] = {0};
    snprintf(result, sizeof(result), "%s %s", first, second);
    printf("%s\n", result);
}
