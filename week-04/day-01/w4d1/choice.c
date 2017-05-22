//make it work

int main(){

    printf("\t**********\n\tHello User\n\t**********\nYou have an integer named 'number'\n");
    printf("- for it's memory address please press 1\n");
    printf("- for it's current value please press 2\n");
    printf("- to double it's value please press 3\n");
    int number = 255;
    int * number_ptr = &number;
    int cho;
    scanf("%d", &cho);
    if(cho == 1){
        printf("%d's memory address %p\n", number, &number);
    }else if(cho == 2){
        printf("%d's value %d\n", number, *number_ptr);
    }else if(cho == 3){
        printf("%d's double value is %d\n", number, *number_ptr * 2);
    }else {
        printf("Please enter a number between 1 - 3!\n");
    }

return 0;
}
