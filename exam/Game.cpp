#include "Field.h"
#include "Player.h";


int GameStart() {
	char player[SIZE][SIZE];
	char computer[SIZE][SIZE];
	int ships[10] = { 4,3,3,2,2,2,1,1,1,1 };

	initField(player);
	initField(computer);
	printField(player);
	PlaceShips(ships, player);
	printField(player);

	
	for (int i = 0; i < shipscount; i++) {
	std::cout << ships[i] << " ";
	}

	return 0;
}