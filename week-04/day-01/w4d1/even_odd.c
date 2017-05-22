/*
Write a program that reads a number form the standard input,
than prints "Odd" if the number is odd, or "Even" it it is even.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello, add a number!\n");
    int num;
    scanf("%d", &num);
    if(num % 2 == 0){
        printf("The %d is even number!\n", num);
    }else {
        printf("The %d is odd number!\n", num);
    }
    return 0;
}
