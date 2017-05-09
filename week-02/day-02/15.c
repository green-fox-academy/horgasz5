#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t u = 123;
	// print 'Hooray!' if the number is bigger than 100
	printf("%d\n", u);
	if(u > 100){
        printf("Hooray!\n");
	}
	return 0;
}
