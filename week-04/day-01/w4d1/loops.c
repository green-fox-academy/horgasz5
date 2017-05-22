/*
Create a program which writes down the following sentence 100 times:
"I won't cheat on the test!"

Do it with:
    - for loop
    - while loop
    - do while loop

Also create a funtion which does the same.
*/

int i;
void Printsentence();

int main()
{
    for(i = 0; i < 100; i++) {
        printf("%i: I won't cheat on the test!\n", i+1);
    }

    i = 0;
    printf("\n");
    while (i != 100){
        printf("%i: I won't cheat on the test!\n", i+1);
        i++;
    }

    i = 0;
    printf("\n");
    do{
        printf("%i: I won't cheat on the test!\n", i+1);
        i++;
    }while (i != 100 );

    printf("\n");
    Printsentence();

    return 0;
}

void Printsentence(){
    for(i = 0; i < 100; i++) {
        printf("%i: I won't cheat on the test!\n", i+1);
    }
}
