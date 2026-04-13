#pragma once
#include <iostream>
#include "Field.h"
#include "ship.h"


int GameStart();
bool CanPlaceShip(char field[SIZE][SIZE], int row, int col, int size, char direction);
void PlaceShipOnField(char field[SIZE][SIZE], ShipInfo& ship, int r, int c, int size, char dir);
