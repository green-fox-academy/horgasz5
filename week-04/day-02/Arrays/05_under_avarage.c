#include <stdio.h>
#include <stdlib.h>

// TODO:
// Create a function that takes a double array as a parameter, and the length of the array.
// This function should calculate the avarage of the elements.

// TODO:
// Create an other function that takes a double array as a parameter, and the length of the array.
// It calculates how much elements are under the avarage, and returns with that.

// TODO:
// Create an other function that takes a double array as a parameter, and the length of the array.
// It allocates a new array, and loads into it the elements which are under the average.
// It returns a pointer to the new array.
double average(double *tomb, int tomb_len);
int elements(double *tomb, int tomb_len);
double *create_new_array(double *tomb, int tomb_len);

int main()
{
    double tomb[] = {1.2, 3.14, 1.41, 0.707, 1.73};
    int tomb_len = sizeof(tomb) / sizeof(tomb[0]);

    printf("Average = %.2f\n", average(tomb, tomb_len));
    printf("Elements under average = %d\n", elements(tomb, tomb_len));
    printf("Numbers under the average:\n");
    double *new_array = create_new_array(tomb, tomb_len);
    //double *array_under_avg = create_array_with_under_avg(array, n, avg);
    for (int i = 0; i < elements(tomb, tomb_len); i++) {
        printf("%.2f\n", new_array[i]);
    }

    return 0;
}

double average(double *tomb, int tomb_len)
{
    double tmp = 0;
    for (int i = 0; i < tomb_len; i++) {
        tmp += tomb[i];
    }
    return (tmp / tomb_len);
}

int elements(double *tomb, int tomb_len)
{
    int elem = 0;
    for (int j = 0; j < tomb_len; j++) {
        if (tomb[j] < average(tomb, tomb_len))
            elem++;
    }
    return elem;
}

double *create_new_array(double *tomb, int tomb_len)
{
    double *new_array = (double*)calloc(tomb_len, sizeof(double));
    int index = 0;
    for (int k = 0; k < tomb_len; k++) {
        if (tomb[k] < average(tomb, tomb_len)) {
            new_array[index] = tomb[k];
            index++;
        }
    }
    return new_array;
}
