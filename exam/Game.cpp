#include <iostream>
#include "Field.h"

using namespace std;

int GameStart() {
	char player[SIZE][SIZE];
	char computer[SIZE][SIZE];

	initField(player);
	initField(computer);
	printField(player);

	return 0;
}