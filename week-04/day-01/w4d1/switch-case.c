/*
Write a program which receives a number between 0-10 from the user.
It prints out the english word for that number on the screen.
For example if the user enters 8, the program prints out "Eight".
Use switch-case in this task!
Handle the invalid user input!
*/

int main()
{
    int num;
    printf("What is the number?\n");
    scanf("%d", &num);

    switch(num) {
        case 0 :
            printf("\nThe %d in english is: Zero\n", num);
        break;
        case 1 :
            printf("\nThe %d in english is: One\n", num);
        break;
        case 2 :
            printf("\nThe %d in english is: Two\n", num);
        break;
        case 3 :
            printf("\nThe %d in english is: Three\n", num);
        break;
        case 4 :
            printf("\nThe %d in english is: Four\n", num);
        break;
        case 5 :
            printf("\nThe %d in english is: Five\n", num);
        break;
        case 6 :
            printf("\nThe %d in english is: Six\n", num);
        break;
        case 7 :
            printf("\nThe %d in english is: Seven\n", num);
        break;
        case 8 :
            printf("\nThe %d in english is: Eight\n", num);
        break;
        case 9 :
            printf("\nThe %d in english is: Nine\n", num);
        break;
        case 10 :
            printf("\nThe %d in english is: Ten\n", num);
        break;
        default :
            printf("Invalid number\n");
        }

    return 0;
}
