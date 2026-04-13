#include "Game.h"
#include "Field.h"
#include "Player.h"
#include "Computer.h"
#include "ship.h"
#include <iostream>

using namespace std;

ShipInfo playerShips[10];
ShipInfo computerShips[10];

bool CanPlaceShip(char field[SIZE][SIZE], int row, int col, int size, char direction) {
    for (int i = 0; i < size; i++) {
        int r = row;
        int c = col;
        if (direction == 'h' || direction == 'H')
            c += i;
        else if (direction == 'v' || direction == 'V')
            r += i;
        else {
            cout << "Invalid direction!" << endl;
            return false;
        }
        if (r >= SIZE || c >= SIZE)
            return false;
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE) {
                    if (field[nr][nc] == 'S')
                        return false;
                }
            }
        }
    }
    return true;
}

void PlaceShipOnField(char field[SIZE][SIZE], ShipInfo& ship, int r, int c, int size, char dir) {
    ship.size = size;
    ship.hits = 0;
    ship.destroyed = false;
    for (int i = 0; i < size; i++) {
        int nr = r;
        int nc = c;
        if (dir == 'h') nc += i;
        else nr += i;
        field[nr][nc] = 'S';
        ship.cells[i][0] = nr;
        ship.cells[i][1] = nc;
    }
}

void GameLoop(char player[SIZE][SIZE], char computer[SIZE][SIZE],
    ShipInfo playerShips[], ShipInfo computerShips[]) {
    int playerHits = 0;
    int aiHits = 0;
    while (playerHits < 20 && aiHits < 20) {
        PlayerShoot(computer, playerHits);
        if (playerHits == 20) {
            cout << "YOU WIN!\n";
            break;
        }
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } while (player[x][y] == 'X' || player[x][y] == 'o');
        Shoot(player, playerShips, aiHits, x, y);
        if (aiHits == 20) {
            cout << "AI WINS!\n";
            break;
        }
    }
}

int GameStart() {
    srand(time(0));
    char player[SIZE][SIZE];
    char computer[SIZE][SIZE];
    int ships[10] = { 4,3,3,2,2,2,1,1,1,1 };
    int ai_ships[10] = { 4,3,3,2,2,2,1,1,1,1 };
    char choice;

    initField(computer);
    AIPlaceShips(ai_ships, computer, computerShips);
    printField(computer);

    do {
        cout << "\nEnter option:\n1 - place ships manually\n2 - AI place ships\n";
        cin >> choice;
        if (choice != '1' && choice != '2')
            cout << "Invalid option! Try again.\n";
    } while (choice != '1' && choice != '2');

    initField(player);

    if (choice == '1') {
        int localShipCount = 10;
        while (localShipCount > 0) {
            PlaceShips(ships, player, playerShips, localShipCount);
            printField(player);
        }
        GameLoop(player, computer, playerShips, computerShips);
    }
    else if (choice == '2') {
        char answer;
        do {
            initField(player);
            AIPlaceShips(ships, player, playerShips);
            printField(player);
            do {
                cout << "Do you like the position of ships (y/n)? ";
                cin >> answer;
                if (answer != 'y' && answer != 'n')
                    cout << "Invalid option! Try again.\n";
            } while (answer != 'y' && answer != 'n');
        } while (answer == 'n');
        GameLoop(player, computer, playerShips, computerShips);
    }
    return 0;
}