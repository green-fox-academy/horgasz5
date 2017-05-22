/* Write a function which is called "get_fibonacci_number". It returns the "N"th
 * Fibonacci number, where "N" is received as a paramter.
 * For example:
 *  - get_fibonacci_number(1) returns 0
 *  - get_fibonacci_number(2) returns 1
 *  - get_fibonacci_number(3) returns 1
 *  - get_fibonacci_number(4) returns 2
 *  - get_fibonacci_number(5) returns 3
 *  - get_fibonacci_number(6) returns 5
 *
 *  If the function gets invalid parameter it returns -1.
 */

/*
Using that function create a program, which gets a number from the user, and
prints out the "N"th Fibonacci number, where "N" is the user given number.
Alert the user if he/she entered invalid value.
*/
int N;
int get_fibonacci_number(int N);

int main()
{
    printf("What is the parameter?\n");
    scanf("%d", &N);

    printf("\nThe %dth fibonacci number is %d!\n", N, get_fibonacci_number(N));

    return 0;
}

int get_fibonacci_number(int N){
    if(N < 1){
        return -1;
    }else if (N == 1){
        return 0;
    }else if (N == 2){
        return 1;
    }else {
        int a = get_fibonacci_number(N-1);
        int b = get_fibonacci_number(N-2);
        return a+b;
    }
}
