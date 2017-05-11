#include <stdio.h>

int main() {
    char buffer[255];   // Buffer variable for user input
    printf("Name?\n");
    //TODO:
    // Get the user's name with gets
    gets(buffer);
    //TODO:
    // Print it out with puts
    puts(buffer);
    printf("Pet's name?\n");
    //TODO:
    // Get the user's pet name with getchar
    char n;
    n = getchar();
    //TODO:
    // Print it out
    putchar(n);
    return 0;
}
