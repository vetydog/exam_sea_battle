#include "Computer.h"
#include "Game.h"

using namespace std;

char getRandomDirection() {
    return (rand() % 2 == 0) ? 'h' : 'v';
}

void AIPlaceShips(int ships[], char field[SIZE][SIZE]) {
    const int shipCount = 10;

    for (int i = 0; i < shipCount; i++) {
        int size = ships[i];
        bool placed = false;

        while (!placed) {
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            char dir = getRandomDirection();

            if (CanPlaceShip(field, row, col, size, dir)) {
                PlaceShipOnField(field, row, col, size, dir);
                placed = true;
            }
        }
    }
}
