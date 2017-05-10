#include <stdio.h>

/* Write a non void function which returns the value of PI, so the following number:
3.14159
Try it out in the main function by printing out the result of the pi generator function!
*/

float pi_value();

int main(){
    printf("%f\n", pi_value());
    return 0;
}

float pi_value(){
    float pi = 3.14159;
    return pi;
}
