#include <stdio.h>
#include <stdlib.h>

// Define the TOTORO macro which holds the number of students in our class
//#define TOTORO 19

int main()
{
    // Use the #ifdef and #ifndef macros!

    // If the TOTORO macro is not defined print out 32
    #ifdef TOTORO
    printf("%d\n", TOTORO);
    #endif
    #ifndef TOTORO
    printf("%d\n", 32);
    #endif // TOTORO
    // If the TOTORO macro is defined print out it's value


    return 0;
}
