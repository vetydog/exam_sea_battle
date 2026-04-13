#include "Player.h"
#include "Field.h"
#include "Game.h"
#include <iostream>
#include <cctype>

using namespace std;

int shipscount = 10;

bool PlayerShoot(char enemy[SIZE][SIZE], int& hits) {
    char letter;
    int row;
    cout << "Your turn!\nLetter A-J: ";
    cin >> letter;
    letter = toupper(letter) - 'A';
    cout << "Row 0-9: ";
    cin >> row;
    if (row < 0 || row >= SIZE || letter < 0 || letter >= SIZE) {
        cout << "Invalid coordinates!\n";
        return false;
    }
    if (enemy[row][letter] == 'S') {
        enemy[row][letter] = 'X';
        hits++;
        cout << "\"Hit\" - ship is there\n";
        return true;
    }
    else {
        enemy[row][letter] = 'o';
        cout << "\"Miss\" - no ship\n";
        return false;
    }
}

bool RemoveShip(int ships[], int& count, int size) {
    for (int i = 0; i < count; i++) {
        if (ships[i] == size) {
            for (int j = i; j < count - 1; j++)
                ships[j] = ships[j + 1];
            count--;
            return true;
        }
    }
    return false;
}

int PlaceShips(int ships[], char field[SIZE][SIZE], ShipInfo playerShips[], int& shipsCount) {
    int sizeship;
    char letter;
    int number;
    char input;
    char inputNumber;

    do {
        cout << "Which size of ship will you place (1-4): ";
        cin >> input;
        if (input < '1' || input > '4')
            cout << "Invalid size\n";
    } while (input < '1' || input > '4');
    sizeship = input - '0';

    do {
        cout << "Enter letter (A-J): ";
        cin >> letter;
    } while (!isalpha(letter));
    letter = toupper(letter) - 'A';

    do {
        cout << "Enter number (0-9): ";
        cin >> inputNumber;
        if (inputNumber < '0' || inputNumber > '9')
            cout << "Invalid number\n";
    } while (inputNumber < '0' || inputNumber > '9');
    number = inputNumber - '0';

    char direction = 'h';
    if (sizeship > 1) {
        do {
            cout << "Enter direction (h - horizontal, v - vertical): ";
            cin >> direction;
            if (direction != 'h' && direction != 'v')
                cout << "Invalid option! Try again.\n";
        } while (direction != 'h' && direction != 'v');
    }

    if (!CanPlaceShip(field, number, letter, sizeship, direction)) {
        cout << "Cannot place ship here!\n";
        return 0;
    }

    if (!RemoveShip(ships, shipsCount, sizeship)) {
        cout << "No ships of this size left!\n";
        return 0;
    }

    int index = 10 - shipsCount - 1;
    PlaceShipOnField(field, playerShips[index], number, letter, sizeship, direction);
    return 1;
}