#include "Field.h"

using namespace std;

void initField(char field[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            field[i][j] = 'w';
        }
    }
}

void printField(char field[SIZE][SIZE]) {
    cout << "  ";
    for (int i = 65; i < 75; i++) {
        cout << char(i) << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

void printEnemyField(char realField[SIZE][SIZE]) {
    cout << "  ";
    for (int i = 0; i < SIZE; i++)
        cout << char('A' + i) << " ";
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            char cell = realField[i][j];
            if (cell == 'S') 
                cell = 'w';
            cout << cell << " ";
        }
        cout << endl;
    }
}