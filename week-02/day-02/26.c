#include <stdio.h>

int main() {
	// Write a program that prints the numbers from 1 to 100.
	int i;
	for(i = 1; i < 101; i++){
        if((i % 3) == 0){
            printf("Fizz\n");
            if((i % 5) ==0){
                printf("FizzBuzz\n");
            }
            continue;
        }
        if((i % 5) == 0){
            printf("Buzz\n");
            continue;
        }
        printf("%d\n", i);
	}
	// But for multiples of three print "Fizz" instead of the number
	// and for the multiples of five print "Buzz".
	// For numbers which are multiples of both three and five print "FizzBuzz".
	return 0;
}
