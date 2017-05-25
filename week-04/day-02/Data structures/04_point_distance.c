#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} point_t;

point_t* NewPoint (int x, int y);
double Distance (point_t *p1, point_t *p2);
// TODO:
// Create a function the constructs a Point (returns a pointer to a new point)
// It should take it's x and y coordinate as parameter

// TODO:
// Create a function that takes 2 Points as a pointer and returns the distance between them

int main()
{
    point_t *point1ptr = NewPoint(0,0);
    point_t *point2ptr = NewPoint(3,4);

    printf("Distance: %.02f\n", Distance(point1ptr, point2ptr));

    return 0;
}

point_t* NewPoint (int x, int y)
{
    point_t *temp = (point_t*)malloc(sizeof(point_t));
    temp -> x = x;
    temp -> y = y;
    return temp;
}

double Distance (point_t *p1, point_t *p2)
{
    double d = (double)(sqrt(pow((p1 -> x - p2 -> x), 2) + pow((p1 -> y - p2 -> y), 2)));
    return d;
}
