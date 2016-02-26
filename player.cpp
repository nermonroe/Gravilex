/*
 * player.cpp
 *
 *  Created on: Jan 19, 2016
 *      Author: Nerissa
 */
#include "player.h"

int player::charConversion(char character)
{
	return character - '0';
}

string player::upperCaseConvert(string word)
{
	for(unsigned int i = 0; i < word.size(); i++) {
		if(isupper(word[i]))
			word[i] = tolower(word[i]);
	}

return word;
}

int player::determineScore(string claimedWord)
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

void player::getLetterChoice()
{
	char tileChoice;

	cout<<"What letter would you like to drop? ";
	cin>>tileChoice;

	if(isupper(tileChoice))
		tileChoice = (tolower(tileChoice));

	setLetter(tileChoice);
}

void player::getColumnChoice()
{
	char columnChoice;
	int integer;

	cout<<"What column would you like to drop that in? (1-7) ";
	cin>>columnChoice;

	if(isalpha(columnChoice)) {
		integer = -1;
		setColumn(integer); }
	else {
		integer = charConversion(columnChoice);;
		setColumn(integer); }
}

void player::getWords()
{
	string wordToClaim;

	cout<<"Enter a word that you would like to claim (empty line to end): ";
	getline(cin, wordToClaim);

	setWord(wordToClaim);
}

bool player::searchDictionary(string dictionary[], int size, string word)
{
	for(int i = 0; i < size; i++) {
		if(dictionary[i] == word)
			return true; }

return false;
}

void player::tilesRemainingToPlayer(tile& t)
{
	bool valid;

		do {
		cout<<"The letters remaining to you:"<<endl;
		t.displayTiles();
		getLetterChoice();
			if(t.isTileAvailable(t.decodePosition(getLetter())) == true)
				valid = true;
			else
				valid = false;
		}while(!valid);
}

void player::announceScore()
{
	cout<<"Points scored on this turn: "<<getScore()<<endl;
}

void player::checkIfValidColumnChoice(board& b)
{
	bool valid;

	do {
		getColumnChoice();
		if((getColumn() < 1 || getColumn() > 7) || b.isFull(getColumn()))
			valid = false;
		else
			valid = true;
	}while(!valid);
}

void player::loopForGettingWords(board& b, string dictionary[], int size, int rowPosition)
{
	string word = "May2016";
	int search;
	int score = 0;
	char answer;

	while(word != "") { // while the player is still trying to claim words
		getWords();
		word = getWord();
		search = b.wordSearch(word, rowPosition, (getColumn() - 1));
		if(word != "") {
			if(search == 1) {
				if(searchDictionary(dictionary, size, word) == true) {
					score += determineScore(word);
					setScore(score); }
				else {
					cout<<"I don't know that word. Are you sure you spelled it correctly? (y/n) ";
					cin>>answer;
					cin.ignore();
					if(answer == 'y' || answer == 'Y') {
						score += determineScore(word);
						setScore(score); }
				}
			}
			else if(search == 2)
				cout<<"Sorry, you cannot claim that word"<<endl;
			else if(search == 0)
				cout<<"Sorry, I cannot find that word"<<endl;
		}
	}
}

void player::humanPlayer(board& b, tile& t, string dictionary[], int size)
{
	int row;

	b.displayBoard();
	tilesRemainingToPlayer(t);
	checkIfValidColumnChoice(b);
	row = b.dropTile(getLetter(), (getColumn() - 1));
	b.displayBoard();
	loopForGettingWords(b, dictionary, size, row);
	t.decrementTiles(t.decodePosition(getLetter()));
	announceScore();
}

