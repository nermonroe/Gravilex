/*
 * computer.cpp
 *
 *  Created on: Jan 4, 2016
 *      Author: Nerissa
 */

#include "computer.h"

bool computer::isConsonant(char choice)
{
	if((choice == 'a') || (choice == 'e') || (choice == 'i') || (choice == 'o') || (choice == 'u'))
		return false;
	else
		return true;
}

int computer::determineScore(string claimedWord)
{
	if(claimedWord.length() == 3)
		return 1;
	else if(claimedWord.length() == 4)
		return 2;
	else if(claimedWord.length() == 5)
		return 4;
	else if(claimedWord.length() == 6)
		return 8;
	else if(claimedWord.length() == 7)
		return 16;
	else
		return 0;
}

bool computer::findMatch(board& b, string dictionary[], int pos, int column, int size)
{
	for(int i = 0; i < size; i++) {
		if(b.wordSearch(dictionary[i], pos, column) == true)
			return true; }
return false;
}

void computer::determineMoves(board& b, tile& t, string dictionary[], int size)
{
	computerMoves cm;
	int pos, counter;
	int score, arrayPos;
	int wordSearchResult;

	for(char alphabet = 'a'; alphabet <= 'z'; alphabet++) { // outer loop to go through each letter
		for(int column = 0; column < COL; column++) {  // inner loop to drop each letter into each column
			if(t.isTileAvailable(t.decodePosition(alphabet)) == true) { // check if the letter can be used, else go to next letter
				score = 0;
				arrayPos = 0;
				counter = 0;
				pos = b.dropTile(alphabet, column);
				for(int i = 0; i < size; i++) {
					wordSearchResult = b.wordSearch(dictionary[i], pos, column);
					if(wordSearchResult == 1) { // try to claim all of the words in the dictionary to gather best move
						cm.letter = alphabet;
						cm.column = column;
						cm.row = pos;
						cm.pushWords(arrayPos, dictionary[i]);
						score += determineScore(dictionary[i]);
						cm.score = score;
						arrayPos++;
						counter++; }
					if(counter > 0 && i == size - 1)
						bestMoves.push_back(cm); }
				b.undoMove(pos, column);
				cm.clearArray(); }
			}
		}
}

int computer::findMaxScore()
{
	int MAX = bestMoves[0].score;

	for(unsigned int i = 0; i < bestMoves.size(); i++) {
		if(bestMoves[i].score > MAX)
			MAX = bestMoves[i].score; }

	return MAX;
}

char computer::findEarlierLetter()
{
	char earlierLetter = bestMoves[0].letter;

	for(unsigned int i = 0; i < bestMoves.size(); i++) {
		if(bestMoves[i].letter < earlierLetter)
			earlierLetter = bestMoves[i].letter; }

	return earlierLetter;
}

int computer::findLowerColumn()
{
	int lowerColumn = bestMoves[0].column;

	for(unsigned int i = 0; i < bestMoves.size(); i++) {
		if(bestMoves[i].column < lowerColumn)
			lowerColumn = bestMoves[i].column; }

	return lowerColumn;
}

void computer::eliminateLowScoringMoves()
{
	vector<computerMoves> temp;

	for(unsigned int i = 0; i < bestMoves.size(); i++) {
		if(!lessThanMax(bestMoves[i].score))
			temp.push_back(bestMoves[i]); }
		bestMoves.swap(temp);
		temp.clear();
}

void computer::eliminateVowelMoves()
{
	vector<computerMoves> temp;
	int counter = 0;

	for(unsigned int i = 0; i < bestMoves.size(); i++)
		if(isConsonant(bestMoves[i].letter)) {
			counter++;
			if(counter > 0) {
				temp.push_back(bestMoves[i]);
				bestMoves.swap(temp);
				temp.clear(); }
	}
}

void computer::eliminateIsolatedTileMoves(board& b)
{
	vector<computerMoves> temp;

	for(unsigned int i = 0; i < bestMoves.size(); i++) {
		if(b.tileIsTouching(bestMoves[i].row, bestMoves[i].column))
			temp.push_back(bestMoves[i]); }
		bestMoves.swap(temp);
		temp.clear();
}

void computer::elimateLatterLetterMoves()
{
	vector<computerMoves> temp;

	for(unsigned int i = 0; i < bestMoves.size(); i++) {
		if(bestMoves[i].letter == findEarlierLetter())
			temp.push_back(bestMoves[i]); }
		bestMoves.swap(temp);
		temp.clear();
}

void computer::eliminateHighColumnMoves()
{
	vector<computerMoves> temp;

	for(unsigned int i = 0; i < bestMoves.size(); i++) {
		if(bestMoves[i].column == findLowerColumn())
			temp.push_back(bestMoves[i]); }
		bestMoves.swap(temp);
		temp.clear();
}

void computer::determineBestMove(board& b)
{
	if(checkBestMovesSize() >= 2) {
		eliminateLowScoringMoves();
		if(checkBestMovesSize() >= 2) {
			eliminateVowelMoves();
			if(checkBestMovesSize() >= 2) {
				eliminateIsolatedTileMoves(b);
				if(checkBestMovesSize() >= 2) {
					elimateLatterLetterMoves();
					if(checkBestMovesSize() >= 2)
						eliminateHighColumnMoves(); }
			}
		}
	}
}

void computer::lemmeSee()
{
	computerMoves cm;

	for(unsigned int i = 0; i < bestMoves.size(); i++) {
		cout<<bestMoves[i].letter<<" "<<bestMoves[i].column<<" "<<bestMoves[i].score<<" ";
		for(int j = 0; j < 7; j++)
			cout<<bestMoves[i].eligibleWords[j]<<" ";
		cout<<endl; }
}

void computer::tilesRemaining(tile& t)
{
	cout<<"Letters remaining for me:"<<endl;
	t.displayTiles();
}

void computer::announceMove()
{
	cout<<"I will put "<<bestMoves[0].letter<<" in column "<<(bestMoves[0].column + 1)<<endl;
}

void computer::announceWords()
{
	for(int i = 0; i < 4; i++)
		if(bestMoves[0].eligibleWords[i] != erase) {
			cout<<"I claim the word: "<<bestMoves[0].eligibleWords[i]<<endl; }
}

void computer::announceScore()
{
	cout<<"Points scored on this turn: "<<bestMoves[0].score<<endl;
}

void computer::computerPlayer(board& b, tile& t, string dictionary[], int size)
{
	b.displayBoard();
	tilesRemaining(t);
	determineMoves(b, t, dictionary, size);
	determineBestMove(b);
	announceMove();
	b.dropTile(getLetter(), getColumn());
	b.displayBoard();
	announceWords();
	announceScore();
	t.decrementTiles(t.decodePosition(getLetter()));
	bestMoves.clear();
}
