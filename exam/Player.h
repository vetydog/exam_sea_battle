#pragma once
#include <iostream>
#include "Field.h"
#include "ship.h"

extern int shipscount;

int PlaceShips(int ships[], char field[SIZE][SIZE], ShipInfo playerShips[], int& shipsCount);
bool RemoveShip(int ships[], int &shipscount, int size);
bool PlayerShoot(char enemy[SIZE][SIZE], ShipInfo computerShips[], int& hits);
