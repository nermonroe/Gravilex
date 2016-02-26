/*
 * computer.h
 *
 *  Created on: Jan 4, 2016
 *      Author: Nerissa
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_

#include "board.h"
#include "tile.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::remove_if;
using std::cin;

	const string erase = "";

class computer
{
public:
	void computerPlayer(board& b, tile& t, string dictionary[], int);
	char getLetter() { return bestMoves[0].letter; }
	int getColumn() { return bestMoves[0].column; }
	int getRow() { return bestMoves[0].row; }
	int getScore() { return bestMoves[0].score; }

private:
	struct computerMoves
	{
		computerMoves() { letter = 'a'; column = 0; row = 0; score = 0; }
		char letter;
		int column;
		int row;
		int score;
		string eligibleWords[7];

		void pushWords(int pos, string word) { eligibleWords[pos] = word; }
		void clearArray() { for(int i = 0; i < 7; i++) eligibleWords[i] = erase; }
	};
	vector<computerMoves> bestMoves;

	int findMaxScore(); // finds the highest score of all the saved moves
	char findEarlierLetter(); // finds the letter move to the beginning of the alphabet
	int findLowerColumn(); // finds the column move closest to the left
	bool lessThanMax(int num) { return num < findMaxScore(); }
	int checkBestMovesSize() { return bestMoves.size(); }
	void determineMoves(board& b, tile &t, string dictionary[], int); // finds all the viable moves the computer player can make
	//*********************************************************
	void eliminateLowScoringMoves();
	void eliminateVowelMoves();
	void eliminateIsolatedTileMoves(board& b);			// These moves involve a temporary vector used to store the remaining moves after elimination, and is then
	void elimateLatterLetterMoves();					// swapped with the bestMoves vector and cleared
	void eliminateHighColumnMoves();
	//**********************************************************
	void determineBestMove(board& b); // used to determine the best move after all of the eliminations
	void tilesRemaining(tile& t);
	void announceMove(); // announces the computer player's move
	void announceWords(); // announces the words it claims
	void announceScore(); // announces the score
	bool isConsonant(char); // used to determine consonant moves for the elimination of vowel moves
	int determineScore(string);
	void lemmeSee();
	bool findMatch(board& b, string dictionary[], int, int, int); // looks for matches in the provided dictionary
};

 #endif /* COMPUTER_H_ */
