#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t ad = 6;
	// print the numbers till ad from 0
	int a = 0;
	int i;
	for(i = 0; i < (ad + 1); i++){
        printf("%d\n", a++);
	}
	return 0;
}
