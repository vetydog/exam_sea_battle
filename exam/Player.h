#pragma once
#include <iostream>
#include "Field.h"

extern int shipscount;

int PlaceShips(int ships[], char field[SIZE][SIZE]);
bool RemoveShip(int ships[], int &shipscount, int size);

