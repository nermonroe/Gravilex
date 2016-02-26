/*
 * player.h
 *
 *  Created on: Jan 19, 2016
 *      Author: Nerissa
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "tile.h"
#include <stdio.h>

using std::cin;

class player
{
public:
	player(){ letter = '0'; column = 0; score = 0; }

	char getLetter() { return letter; }
	int getColumn() { return column; }
	int getScore() { return score; }
	string getWord() { return word; }
	void humanPlayer(board& b, tile &t, string dictionary[], int size); // combines all of the function to gather the necessary information from the player


private:
	char letter;
	string word;
	int column;
	int score;

	void setLetter(char l) { letter = l; }
	void setColumn(int c) { column = c; }
	void setScore(int s) { score = s; }
	void setWord(string w) { word = w; }
	int charConversion(char); // converts a character to an integer
	string upperCaseConvert(string);
	int determineScore(string);
	void getLetterChoice(); // asks the player for the letter of their choice
	void getColumnChoice(); // asks the player for the column of their choice
	void getWords(); // asks the player for the word(s) they want to claim
	bool searchDictionary(string dictionary[], int, string);
	void tilesRemainingToPlayer(tile& t);
	void announceScore();
	void checkIfValidColumnChoice(board& b);
	void loopForGettingWords(board& b, string dictionary[], int, int); // keep asking player what words they want to claim
};



#endif /* PLAYER_H_ */
