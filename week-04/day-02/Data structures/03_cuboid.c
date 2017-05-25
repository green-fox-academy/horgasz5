#include <stdio.h>

struct rectangular_cuboid {
    double a;
    double b;
    double c;
};

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
double getsurface(struct rectangular_cuboid tmp);
// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume
double getvolume(struct rectangular_cuboid tmp);

int main()
{
    struct rectangular_cuboid tegla = {3, 4, 5};

    printf("Surface: %.2f\n", getsurface(tegla));
    printf("Volumee: %.2f\n", getvolume(tegla));

    return 0;
}

double getsurface(struct rectangular_cuboid tmp)
{
    double surface = 2 * (tmp.a * tmp.b + tmp.a * tmp.c + tmp.b * tmp.c);
    return surface;
}

double getvolume(struct rectangular_cuboid tmp)
{
    double volume = tmp.a * tmp.b * tmp.c;
    return volume;
}
