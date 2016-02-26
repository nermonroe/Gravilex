/*
 * tile.cpp
 *
 *  Created on: Jan 3, 2016
 *      Author: Nerissa
 */

#include "tile.h"

tile::tile()
{
	char alphabet = 'a';

	for(int i = 0; i < TILE_COUNT; i++) {
		tileContainer[i].tiles = alphabet;
			if((alphabet == 'a') || (alphabet == 'e') || (alphabet == 'i') || (alphabet == 'o') || (alphabet == 'u')) {
				tileContainer[i].tileCounter = 2; }
			else {
				tileContainer[i].tileCounter = 1; }
		alphabet++;
	}
}

void tile::displayTiles()
{
	for(int i = 0; i < TILE_COUNT; i++) {
		if(tileContainer[i].tileCounter == 2)
			cout<<tileContainer[i].tiles<<"("<<tileContainer[i].tileCounter<<")"<<" ";

		else
			cout<<tileContainer[i].tiles<<" "; }

	cout<<endl;
}

void tile::decrementTiles(int pos)
{
	tileContainer[pos].tileCounter--;

	if(tileContainer[pos].tileCounter <= 0)
		tileContainer[pos].tiles = '_';
}

bool tile::isTileAvailable(int pos)
{
	if(tileContainer[pos].tileCounter <= 0 && tileContainer[pos].tiles == '_')
		return false;
	else
		return true;
}

int tile::decodePosition(char choice)
{
	switch(choice) {
		case 'a': return 0;
			break;
		case 'b': return 1;
			break;
		case 'c': return 2;
			break;
		case 'd': return 3;
			break;
		case 'e': return 4;
			break;
		case 'f': return 5;
			break;
		case 'g': return 6;
			break;
		case 'h': return 7;
			break;
		case 'i': return 8;
			break;
		case 'j': return 9;
			break;
		case 'k': return 10;
			break;
		case 'l': return 11;
			break;
		case 'm': return 12;
			break;
		case 'n': return 13;
			break;
		case 'o': return 14;
			break;
		case 'p': return 15;
			break;
		case 'q': return 16;
			break;
		case 'r': return 17;
			break;
		case 's': return 18;
			break;
		case 't': return 19;
			break;
		case 'u': return 20;
			break;
		case 'v': return 21;
			break;
		case 'w': return 22;
			break;
		case 'x': return 23;
			break;
		case 'y': return 24;
			break;
		case 'z': return 25;
			break;
		default: return -1;
	}
}

