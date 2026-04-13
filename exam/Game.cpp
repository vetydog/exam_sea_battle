#include "Field.h"
#include "Player.h";
#include "Computer.h";

using namespace std;

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

int GameStart() {
	char player[SIZE][SIZE];
	char computer[SIZE][SIZE];
	int ships[10] = { 4,3,3,2,2,2,1,1,1,1 };
	int ai_ships[10] = { 4,3,3,2,2,2,1,1,1,1 };

	initField(computer);
	AIPlaceShips(ai_ships,computer);
    printField(computer);

	initField(player);
	printField(player);

	while (shipscount > 0) {
		PlaceShips(ships, player);
		printField(player);
	}

	return 0;
}