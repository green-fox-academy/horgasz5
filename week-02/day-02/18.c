#include <stdio.h>
#include <stdint.h>

int main() {
	uint16_t number = 254;
	// if number can't be represented with 8bits
	if(number > 256){
        printf("longer than 8bits\n");
	}else{
        printf("ok\n");
	}
	// print 'longer than 8bits' otherwise print 'ok'
	return 0;
}
