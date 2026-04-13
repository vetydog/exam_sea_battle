#pragma once
#include "Field.h"
#include "Game.h"

void AIPlaceShips(int ships[], char field[SIZE][SIZE], ShipInfo computerShips[]);
bool Shoot(char field[SIZE][SIZE], ShipInfo ships[], int& hits, int x, int y);