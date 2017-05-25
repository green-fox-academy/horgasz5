#include <stdio.h>

// TODO:
// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters

struct house {
    char address[255];
    int price;
    int rooms;
    double area;
};

// TODO:
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a pointer to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)
#define MARKET_PRICE    400
int worth(struct house* haz);
// TODO:
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.

int main()
{
    struct house haz1;
        strcpy(haz1.address, "Petofi 1");
        haz1.price = 39900;
        haz1.rooms = 3;
        haz1.area = 80;

    struct house haz2;
        strcpy(haz2.address, "Kossuth 5");
        haz2.price = 18100;
        haz2.rooms = 2;
        haz2.area = 46;

    struct house haz3;
        strcpy(haz3.address, "Zrinyi 8");
        haz3.price = 47900;
        haz3.rooms = 5;
        haz3.area = 120;

    return 0;
}

int worth(struct house* haz)
{
    if (MARKET_PRICE >= (haz -> price / haz -> area)) {
        return 1;
    } else {
        return 0;
    }
}
