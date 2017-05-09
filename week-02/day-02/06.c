#include <stdio.h>

int main() {
	int f = 16;
	float x1, x2;

	x1 = (f + (f/f))/2;

	while(x2 != x1){
        x2 = (x1 + (f/x1))/2;
        x1 = (x2 + (f/x2))/2;
	}
	printf("%.2f\n", x1);
	// please square root f's value
	return 0;
}
