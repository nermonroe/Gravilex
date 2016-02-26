/*
 * game.cpp
 *
 *  Created on: Jan 19, 2016
 *      Author: Nerissa
 */
#include "game.h"

void game::gamePlay(board& b, tile& playerTiles, tile& computerTiles, string dictionary[], int size)
{
	int counter = 0;

	do {
		p.humanPlayer(b, playerTiles, dictionary, size);
		c.computerPlayer(b, computerTiles, dictionary, size);
		addScore();
		announceScore();
		counter++; }
	while(counter < ROUNDS);

}


