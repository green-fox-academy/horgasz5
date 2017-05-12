#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void) {
    srand(time(NULL));
    int a = 0;
    printf("I want to play a game...\n\n");
    printf("What is the range?\n");
    scanf("%d", &a);
    int r = rand() % a;
    r += 1;
    bool correct = false;
    int guess;
    int counter = 0;

    while(!correct){
        printf("Guess my number between 1-%d! ", a);
        scanf("%d", &guess);
        if (guess < r) {
                printf("Too low... Try again!\n");
            }else if (guess > r) {
                printf("Too high... Try again!\n");
            }else{
                printf("Congratulations. You won in %d tries!\n", counter+1);
                correct = true;
                break;
        }
    counter++;
    if(counter == 5){
        printf("\nYou lose!!! HA - HA - HA\n");
        printf("The number was: %d\n", r);
        break;
        }
    }
    return 0;
}
