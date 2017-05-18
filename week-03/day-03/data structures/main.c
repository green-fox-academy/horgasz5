#include <stdio.h>

struct RectangularCuboid {
    double a;
    double b;
    double c;
};

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
double GetSurface(struct RectangularCuboid tegla);
// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume
double GetVolume(struct RectangularCuboid tegla);

int main() {
    struct RectangularCuboid tegla;
    tegla.a = 3;
    tegla.b = 4;
    tegla.c = 5;
    double surface;
    double GetSurface(struct RectangularCuboid tegla);
    printf("Surface: %f", surface);

    return 0;
}

double GetSurface(struct RectangularCuboid tegla) {
    double surface = tegla.a * tegla.b * tegla.c;
    return surface;
}

double GetVolume(struct RectangularCuboid tegla){

}
