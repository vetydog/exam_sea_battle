#pragma once
#include <iostream>
#include "Field.h"

extern int shipscount;

int PlaceShips(int ships[], char field[SIZE][SIZE]);
bool RemoveShip(int ships[], int &shipscount, int size);
bool CanPlaceShip(char field[SIZE][SIZE], int row, int col, int size, char direction);
void PlaceShipOnField(char field[SIZE][SIZE], int row, int col, int size, char direction);

