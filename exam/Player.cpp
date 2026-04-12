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

int PlaceShips(int ships[], char masPLayer[SIZE][SIZE]) {
    int sizeship;
    char letter;
    int number;

    cout << "Which size of ship will you place: ";
    cin >> sizeship;

    if (sizeship == 1) {
        cout << "Enter place for ship" << endl;

        cout << "Enter letter: ";
        cin >> letter;
        if (letter >= 'a' && letter <= 'z') {
            letter = letter - 'a';
        }
        else {
            letter = letter - 'A';
        }

        cout << "Enter number: ";
        cin >> number;

        if (letter >= 0 && letter < SIZE && number >= 0 && number < SIZE) {
            if (RemoveShip(ships, shipscount, sizeship)) {
                masPLayer[number][letter] = 'S';
            }
            return 1;
        }
        else {
            cout << "Invalid position!" << endl;
            return 0;
        }
    }

    return 0;

}