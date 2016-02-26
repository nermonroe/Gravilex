#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

    const int ROW = 7;
    const int COL = 7;

// signals for searching the board for the claimed word
    const int NOT_FOUND = 0;
    const int CAN_CLAIM = 1;
    const int CANT_CLAIM = 2;

// includes all of the board functions including creation of the board,
// clearing of the board, displaying the board, dropping of the tile, and search functions
class board
{
public:
    board();  // initializes the board
    ~board(); // clears the board

    void displayBoard();
    int dropTile(char, int); // drops the tile and returns the position
    bool isFull(int); // check if the selected column is full
    int wordSearch(string, int, int); // combines all the search functions for a final result
   	bool checkBoundaries(int, int); // checks if the desired position is within boundaries
	bool isEmpty(int, int); // checks if neighboring spots are empty
    bool tileIsTouching(int, int); // check if a neighboring tile is touching
    void undoMove(int, int);

private:
	char gameboard[ROW][COL];
	struct wordClaimed
	    {
	    	int characterPositionX;
	    	int characterPositionY;
	    };
	bool foundAMatch(int, int, char);

	// search functions in all plausible directions; returns NOT_FOUND, CAN_CLAIM, CANT_CLAIM
	 int searchUp(string, int, int);
	 int searchDown(string, int, int);
	 int searchRight(string, int, int);
	 int searchLeft(string, int, int);
	 int searchDiagonalUpRight(string, int, int);
	 int searchDiagonalUpLeft(string, int, int);
	 int searchDiagonalDownRight(string, int, int);
	 int searchDiagonalDownLeft(string, int, int);
};


#endif /* BOARD_H_ */
