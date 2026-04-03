#include <iostream>
#include "Game.h"

using namespace std;

void startGame() {
    cout << "\n--- Game started ---\n";
    GameStart();
}

int main() {
    char choice;
    cout << "------------Battleship------------\n";
    cout << "1. Play\n2. Rules of game\n0. Exit\n";

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '1') {
            startGame();
            break;
        }
        else if (choice == '2') {
            cout << "\nRules of the game \"Battleship\"\n\n";
            cout << "Goal of the game:\nDestroy all enemy ships before your opponent destroys yours.\n\n";

            cout << "Game board:\n";
            cout << "Each player has a 10x10 grid.\nRows are numbered (1-10), columns are labeled with letters (A-J).\n\n";

            cout << "Ships:\n";
            cout << "Each player places:\n";
            cout << "1 ship with 4 cells\n2 ships with 3 cells\n3 ships with 2 cells\n4 ships with 1 cell\n\n";

            cout << "Placement rules:\n";
            cout << "Ships can be placed horizontally or vertically.\nShips must not touch each other, even diagonally.\n\n";

            cout << "Gameplay:\n";
            cout << "Players take turns.\n";
            cout << "A player calls out a coordinate (e.g., B5).\n";
            cout << "The opponent responds:\n";
            cout << "\"Miss\" - no ship\n";
            cout << "\"Hit\" - ship is there\n";
            cout << "\"Sunk\" - the whole ship is destroyed\n\n";

            cout << "Winning:\n";
            cout << "The first player to destroy all enemy ships wins.\n\n";

            char choice2;
            cout << "Do you want to play? (y/n): ";
            cin >> choice2;

            if (choice2 == 'y' || choice2 == 'Y') {
                startGame();
                break;
            }
            else if (choice2 == 'n' || choice2 == 'N') {
                cout<<"Bey!\n";
                break;
            }
            else {
                cout << "Invalid option!\n\n";
            }
        }
        else if (choice == '0') {
            cout << "Bye!";
            break;
        }
        else {
            cout << "Invalid option\n\n";
        }
    }

}