#include <stdio.h>
#include <stdint.h>

int main() {
	int a = 654;
	uint64_t b = 654987312;
	int c = b % a;
	printf("%d\n", c);
	// Tell if the reminder of b devided by a is 3
    if((b % a) == 3){
        printf("Yeah!\n");
    }else{
        printf("Noo!\n");
    }
	return 0;
}
