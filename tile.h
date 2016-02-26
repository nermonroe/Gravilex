/*
 * tile.h
 *
 *  Created on: Jan 3, 2016
 *      Author: Nerissa
 */

#ifndef TILE_H_
#define TILE_H_

#include <iostream>

#include "board.h"

using std::cout;
using std::endl;

	const int TILE_COUNT = 26;

struct tileContents
{
	char tiles;
	int tileCounter;
};

class tile
{
public:
	tile();

	void displayTiles();
	void decrementTiles(int);
	bool isTileAvailable(int);
	int decodePosition(char);

private:
	tileContents tileContainer[26];
};


#endif /* TILE_H_ */
