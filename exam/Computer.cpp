#include "Computer.h"
#include "Game.h"
#include "ship.h"
#include <iostream>

using namespace std;

bool Shoot(char field[SIZE][SIZE], ShipInfo ships[], int& hits, int x, int y) {
    char letter = 'A' + y; 
    int row = x;
    cout << "AI shoots at " << letter << row << ": ";

    if (field[x][y] != 'S') {
        field[x][y] = 'o';
        cout << "\"Miss\" - no ship\n";
        return false;
    }

    field[x][y] = 'X';
    cout << "\"Hit\" - ship is there\n";
    hits++;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < ships[i].size; j++) {
            if (ships[i].cells[j][0] == x && ships[i].cells[j][1] == y) {
                ships[i].hits++;
                if (ships[i].hits == ships[i].size) {
                    ships[i].destroyed = true;
                    cout << "AI: \"Sunk\" - the whole ship is destroyed\n";
                }
                return true;
            }
        }
    }
    return true;
}

void AITurn(char playerField[SIZE][SIZE], ShipInfo playerShips[], int& aiHits) {
    bool hit;
    do {
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (playerField[x][y] == 'X' || playerField[x][y] == 'o');

        hit = Shoot(playerField, playerShips, aiHits, x, y);
    } while (hit && aiHits < 20);
}

char getRandomDirection() {
    return (rand() % 2 == 0) ? 'h' : 'v';
}

void AIPlaceShips(int ships[], char field[SIZE][SIZE], ShipInfo computerShips[]) {
    const int shipCount = 10;
    for (int i = 0; i < shipCount; i++) {
        int size = ships[i];
        bool placed = false;
        while (!placed) {
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            char dir = getRandomDirection();
            if (CanPlaceShip(field, row, col, size, dir)) {
                PlaceShipOnField(field, computerShips[i], row, col, size, dir);
                placed = true;
            }
        }
    }
}