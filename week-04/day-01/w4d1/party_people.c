// Write a program that asks for two numbers
// The first number represents the number of girls that comes to a party, the
// second the boys.

// It should print "The party is excellent!" if the the number of girls and
// boys are equal and there are more people coming than 20

// It should print "Quite cool party!"
// if there are more than 20 people coming but the girl - boy ratio is not 1-1

// It should print: "Average party..."
// if there are less people coming than 20

// It should print: "Sausage party"
// if no girls are coming, regardless the count of the people

int main()
{
    int num_girls;
    int num_boys;
    printf("How many girls will come to the party?\n");
    scanf("%d", &num_girls);
    printf("How many boys will come to the party?\n");
    scanf("%d", &num_boys);

    if ((num_girls == num_boys) && (num_girls + num_boys >= 20)){
        printf("The party is excellent!\n");
    }else if(num_girls + num_boys >= 20){
        printf("Quite cool party!\n");
    }else if((num_girls + num_boys < 20) && (num_girls != 0)){
        printf("Average party...\n");
    }else if(num_girls == 0){
        printf("Sausage party\n");
    }
    return 0;
}
