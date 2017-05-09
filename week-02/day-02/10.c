#include <stdio.h>

int main() {
	int j1 = 10;
	int j2 = 3;
	if(j1 > (j2*j2) && j1 < (j2*j2*j2)){
        printf("Yes!\n");
	}
	// tell if j1 is higher than j2 squared and smaller than j2 cubed
	return 0;
}
