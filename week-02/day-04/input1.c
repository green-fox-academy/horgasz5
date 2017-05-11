#include <stdio.h>

int main() {
    char buffer[255];   // Buffer variable for user input
    printf("Name?\n");
    //TODO:
    // Get the user's name with scanf
    scanf("%s", buffer);
    //TODO:
    // Print it out with printf
    printf("Name: %s\n", buffer);

    return 0;
}
