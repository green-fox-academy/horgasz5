#include <stdio.h>

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
    enum CarType type;
    double km;
    double gas;
};

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level
void print(struct Car car);

int main()
{
    struct Car car = {TOYOTA, 1500.25, 80.75};
    print(car);
    printf("\n");
    return 0;
}
void print(struct Car car)
{
    printf("%.2f\n", car.km);
    if (car.type != TESLA) {
        printf("%.2f", car.gas);
    }
}
