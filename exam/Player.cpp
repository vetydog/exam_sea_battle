#include "Player.h"
#include "Field.h"

using namespace std;

int shipscount = 10;


bool RemoveShip(int ships[], int& count, int size) {
    for (int i = 0; i < count; i++) {
        if (ships[i] == size) {

            for (int j = i; j < count - 1; j++) {
                ships[j] = ships[j + 1];
            }

            count--;
            return true;
        }
    }
    return false;
}

bool CanPlaceShip(char field[SIZE][SIZE], int row, int col, int size, char direction) {

    for (int i = 0; i < size; i++) {
        int r = row;
        int c = col;

        if (direction == 'h' || direction == 'H')
            c += i;
        else if (direction == 'v' || direction == 'V')
            r += i;
        else {
            cout << "Invalid option!" << endl;
            return false;
        }


        if (r >= SIZE || c >= SIZE) 
            return false;

        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE) {
                    if (field[nr][nc] == 'S') {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

void PlaceShipOnField(char field[SIZE][SIZE], int row, int col, int size, char direction) {
    for (int i = 0; i < size; i++) {
        if (direction == 'h') {
            field[row][col + i] = 'S';
        }
        else {
            field[row + i][col] = 'S';
        }
    }
}


int PlaceShips(int ships[], char field[SIZE][SIZE]) {
    int sizeship;
    char letter;
    int number;
    char input;
    char inputNumber;

    do {
        cout << "Which size of ship will you place (1-4): ";
        cin >> input;

        if (input < '1' || input > '4') {
            cout << "Invalid size of ship\n";
            continue;
        }

        sizeship = input - '0';

    } while (input < '1' || input > '4');

    do {
        cout << "Enter letter (A-J): ";
        cin >> letter;
    } while (!((letter >= 'a' && letter <= 'z') ||(letter >= 'A' && letter <= 'Z')));

    if (letter >= 'a' && letter <= 'z')
        letter = letter - 'a';
    else
        letter = letter - 'A';


    do {
        cout << "Enter number (0-9): ";
        cin >> inputNumber;

        if (inputNumber < '0' || inputNumber > '9') {
            cout << "Invalid number\n";
            continue;
        }

        number = inputNumber - '0';

    } while (inputNumber < '0' || inputNumber > '9');

    char direction = 'h';

    if (sizeship > 1) {
        do {
            cout << "Enter direction (h - horizontal, v - vertical): ";
            cin >> direction;

            if (direction != 'h' && direction != 'v') {
                cout << "Invalid option! Try again.\n";
            }

        } while (direction != 'h' && direction != 'v');
    }

    if (letter < 0 || letter >= SIZE || number < 0 || number >= SIZE) {
        cout << "Invalid position!" << endl;
        return 0;
    }

    if (!CanPlaceShip(field, number, letter, sizeship, direction)) {
        cout << "Cannot place ship here!" << endl;
        return 0;
    }

    if (!RemoveShip(ships, shipscount, sizeship)) {
        cout << "No ships of this size left!" << endl;
        return 0;
    }

    PlaceShipOnField(field, number, letter, sizeship, direction);

    return 1;
}