#pragma once
#include <iostream>
#include "Field.h"

int GameStart();
bool CanPlaceShip(char field[SIZE][SIZE], int row, int col, int size, char direction);
void PlaceShipOnField(char field[SIZE][SIZE], int row, int col, int size, char direction);