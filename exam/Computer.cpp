#include "Computer.h"
#include <cstdlib>

namespace {

char getRandomDirection() {
    return (rand() % 2 == 0) ? 'h' : 'v';
}

bool canPlaceShip(char field[SIZE][SIZE], int row, int col, int size, char direction) {
    for (int i = 0; i < size; i++) {
        int r = row;
        int c = col;

        if (direction == 'h' || direction == 'H') {
            c += i;
        }
        else if (direction == 'v' || direction == 'V') {
            r += i;
        }
        else {
            return false;
        }

        if (r >= SIZE || c >= SIZE) {
            return false;
        }

        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE && field[nr][nc] == 'S') {
                    return false;
                }
            }
        }
    }

    return true;
}

void placeShipOnField(char field[SIZE][SIZE], int row, int col, int size, char direction) {
    for (int i = 0; i < size; i++) {
        if (direction == 'h' || direction == 'H') {
            field[row][col + i] = 'S';
        }
        else {
            field[row + i][col] = 'S';
        }
    }
}

}  // namespace

void AIPlaceShips(int ships[], char field[SIZE][SIZE]) {
    const int shipCount = 10;

    for (int i = 0; i < shipCount; i++) {
        int size = ships[i];
        bool placed = false;

        while (!placed) {
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            char dir = getRandomDirection();

            if (canPlaceShip(field, row, col, size, dir)) {
                placeShipOnField(field, row, col, size, dir);
                placed = true;
            }
        }
    }
}
