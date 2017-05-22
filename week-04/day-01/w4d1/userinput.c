/*
Create a program which ask for a name and an age.
From the age it tells the user when he or she will be 100 years old.
You should only take care of the years (don't bother with the months or days).
*/

int main()
{
    char name[100];
    int age;
    int this_year = 2017;
    printf("What is your name?\n");
    scanf("%s", &name);
    printf("How old are you?\n");
    scanf("%d", &age);
    int hundred = this_year - age + 100;
    printf("%s will be 100 years old in %d!\n", name, hundred);

    return 0;
}
