#include "board.h"

board::board()
{
    for(int i = 0; i < (ROW - 1); i++)
			for(int j = 0; j < COL; j++) {
			  // label the columns
				gameboard[6][0] = '1';
				gameboard[6][1] = '2';
				gameboard[6][2] = '3';
				gameboard[6][3] = '4';
				gameboard[6][4] = '5';
				gameboard[6][5] = '6';
				gameboard[6][6] = '7';

			 // fill the other spaces with a period
				gameboard[i][j] = '.';
			}
}

board::~board()
{
    for(int i = 0; i < (ROW - 1); i++)
			for(int j = 0; j < COL; j++) {
				gameboard[i][j] = '.';
			}


}

void board::displayBoard()
{
    for(int i = 0; i < ROW; i++) {
         for(int j = 0; j < COL; j++) {
             cout<<gameboard[i][j];
       }
     cout<<endl;
     }
}

bool board::isFull(int columnChoice)
{
	if(gameboard[0][columnChoice] == '.')
		return false;

return true;
}

int board::dropTile(char tile, int columnChoice)
{
    int rowPosition = 5;

    if(isFull(columnChoice)) // checks to see if the column is full
        return -1;
    else {
        while(rowPosition >= 0) {
            if(gameboard[rowPosition][columnChoice] == '.') { // checks to see if the bottom of the column is empty
                gameboard[rowPosition][columnChoice] = tile;
                return rowPosition; }

            else
                rowPosition--; }// if the bottom of the column is full, check the space above
      }
   return -1;
}

bool board::checkBoundaries(int rowSelected, int column)
{
	if((rowSelected >= 0 && rowSelected < (ROW - 1)) && (column >= 0 && column < (COL - 1)))
		return true;
	else
		return false;
}

bool board::foundAMatch(int rowPosition, int column, char letter)
{
	if(gameboard[rowPosition][column] == letter)
		return true;
	else
		return false;
}

int board::searchUp(string claimedWord, int rowPosition, int columnChoice)
{
	wordClaimed wc;
	vector<wordClaimed> container;

	unsigned int findCounter = 1;
	unsigned int charPosition = 1;

	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(foundAMatch(i, j, claimedWord[0])) {
				wc.characterPositionX = i;
				wc.characterPositionY = j;
				container.push_back(wc);
				for(int k = i - 1; k >= 0 && charPosition < claimedWord.length(); k--, charPosition++)
					if(foundAMatch(k, j, claimedWord[charPosition])) {
						findCounter++;
						wc.characterPositionX = k;
						wc.characterPositionY = j;
						container.push_back(wc);
						if(findCounter == claimedWord.length()) {
							for(unsigned int pos = 0; pos < container.size(); pos++)
								if((container[pos].characterPositionX == rowPosition) && (container[pos].characterPositionY == columnChoice)) {
									return CAN_CLAIM; }
							return CANT_CLAIM; }

					 }
			}
			container.clear();
		}
	}
return NOT_FOUND;
}

int board::searchDown(string claimedWord, int rowPosition, int columnChoice)
{
	wordClaimed wc;
	vector<wordClaimed> container;

	unsigned int findCounter = 1;
	unsigned int charPosition = 1;

	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(foundAMatch(i, j, claimedWord[0])) {
				wc.characterPositionX = i;
				wc.characterPositionY = j;
				container.push_back(wc);
				for(int k = i + 1; k < ROW && charPosition < claimedWord.length(); k++, charPosition++) {
					if(foundAMatch(k, j, claimedWord[charPosition])) {
						findCounter++;
						wc.characterPositionX = k;
						wc.characterPositionY = j;
						container.push_back(wc);
						if(findCounter == claimedWord.length()) {
							for(unsigned int pos = 0; pos < container.size(); pos++)
								if((container[pos].characterPositionX == rowPosition) && (container[pos].characterPositionY == columnChoice)) {
									return CAN_CLAIM; }
							return CANT_CLAIM; }
					}
				}
				return NOT_FOUND;
			}
			container.clear();
		}
	}
return NOT_FOUND;
}

int board::searchRight(string claimedWord, int rowPosition, int columnChoice)
{
	wordClaimed wc;
	vector<wordClaimed> container;

	unsigned int findCounter = 1;
	unsigned int charPosition = 1;

	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(foundAMatch(i, j, claimedWord[0])) {
				wc.characterPositionX = i;
				wc.characterPositionY = j;
				container.push_back(wc);
				for(int l = j + 1; l < ROW && charPosition < claimedWord.length(); l++, charPosition++)
					if(foundAMatch(i, l, claimedWord[charPosition])) {
						findCounter++;
						wc.characterPositionX = i;
						wc.characterPositionY = l;
						container.push_back(wc);
						if(findCounter == claimedWord.length()) {
							for(unsigned int pos = 0; pos < container.size(); pos++)
								if((container[pos].characterPositionX == rowPosition) && (container[pos].characterPositionY == columnChoice)) {
									return CAN_CLAIM; }
							return CANT_CLAIM; }
					}
			}
			container.clear();
		}
	}
return NOT_FOUND;
}

int board::searchLeft(string claimedWord, int rowPosition, int columnChoice)
{
	wordClaimed wc;
	vector<wordClaimed> container;

	unsigned int findCounter = 1;
	unsigned int charPosition = 1;

	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(foundAMatch(i, j, claimedWord[0])) {
				wc.characterPositionX = i;
				wc.characterPositionY = j;
				container.push_back(wc);
				for(int l = j - 1; l >= 0 && charPosition < claimedWord.length(); l--, charPosition++)
					if(foundAMatch(i, l, claimedWord[charPosition])) {
						findCounter++;
						wc.characterPositionX = i;
						wc.characterPositionY = l;
						container.push_back(wc);
						if(findCounter == claimedWord.length()) {
							for(unsigned int pos = 0; pos < container.size(); pos++)
								if((container[pos].characterPositionX == rowPosition) && (container[pos].characterPositionY == columnChoice)) {
									return CAN_CLAIM; }
							return CANT_CLAIM; }
					}
			}
			container.clear();
		}
	}
return NOT_FOUND;
}

int board::searchDiagonalUpRight(string claimedWord, int rowPosition, int columnChoice)
{
	wordClaimed wc;
	vector<wordClaimed> container;

	unsigned int findCounter = 1;
	unsigned int charPosition = 1;

		for(int i = 0; i < ROW; i++) {
			for(int j = 0; j < COL; j++) {
				if(foundAMatch(i, j, claimedWord[0])) {
					wc.characterPositionX = i;
					wc.characterPositionY = j;
					container.push_back(wc);
					for(int k = i - 1, l = j + 1; k >= 0 && l < COL && charPosition < claimedWord.length(); k--, l++, charPosition++)
						if(foundAMatch(k, l, claimedWord[charPosition])) {
							findCounter++;
							wc.characterPositionX = k;
							wc.characterPositionY = l;
							container.push_back(wc);
							if(findCounter == claimedWord.length()) {
								for(unsigned int pos = 0; pos < container.size(); pos++)
									if((container[pos].characterPositionX == rowPosition) && (container[pos].characterPositionY == columnChoice)) {
										return CAN_CLAIM; }
								return CANT_CLAIM; }
						}
				}
				container.clear();
			}
		}
return NOT_FOUND;
}

int board::searchDiagonalUpLeft(string claimedWord, int rowPosition, int columnChoice)
{
	wordClaimed wc;
	vector<wordClaimed> container;

	unsigned int findCounter = 1;
	unsigned int charPosition = 1;

		for(int i = 0; i < ROW; i++) {
			for(int j = 0; j < COL; j++) {
				if(foundAMatch(i, j, claimedWord[0])) {
					wc.characterPositionX = i;
					wc.characterPositionY = j;
					container.push_back(wc);
					for(int k = i - 1, l = j - 1; k >= 0 && l >= 0 && charPosition < claimedWord.length(); k--, l--, charPosition++)
						if(foundAMatch(k, l, claimedWord[charPosition])) {
							findCounter++;
							wc.characterPositionX = k;
							wc.characterPositionY = l;
							container.push_back(wc);
							if(findCounter == claimedWord.length()) {
								for(unsigned int pos = 0; pos < container.size(); pos++)
									if((container[pos].characterPositionX == rowPosition) && (container[pos].characterPositionY == columnChoice)) {
										return CAN_CLAIM; }
								return CANT_CLAIM; }
						}
				}
				container.clear();
			}
		}
return NOT_FOUND;
}

int board::searchDiagonalDownRight(string claimedWord, int rowPosition, int columnChoice)
{
	wordClaimed wc;
	vector<wordClaimed> container;

	unsigned int findCounter = 1;
	unsigned int charPosition = 1;

		for(int i = 0; i < ROW; i++) {
			for(int j = 0; j < COL; j++) {
				if(foundAMatch(i, j, claimedWord[0])) {
					wc.characterPositionX = i;
					wc.characterPositionY = j;
					container.push_back(wc);
					for(int k = i + 1, l = j + 1; k < ROW && l < COL && charPosition < claimedWord.length(); k++, l++, charPosition++)
						if(foundAMatch(k, l, claimedWord[charPosition])) {
							findCounter++;
							wc.characterPositionX = k;
							wc.characterPositionY = l;
							container.push_back(wc);
							if(findCounter == claimedWord.length()) {
								for(unsigned int pos = 0; pos < container.size(); pos++) {
									if((container[pos].characterPositionX == rowPosition) && (container[pos].characterPositionY == columnChoice)) {
										return CAN_CLAIM; }
								}
								return CANT_CLAIM; }

						 }
				}
				container.clear();
			}
		}
return NOT_FOUND;
}

int board::searchDiagonalDownLeft(string claimedWord, int rowPosition, int columnChoice)
{
	wordClaimed wc;
	vector<wordClaimed> container;

	unsigned int findCounter = 1;
	unsigned int charPosition = 1;

		for(int i = 0; i < ROW; i++) {
			for(int j = 0; j < COL; j++) {
				if(foundAMatch(i, j, claimedWord[0])) {
					wc.characterPositionX = i;
					wc.characterPositionY = j;
					container.push_back(wc);
					for(int k = i + 1, l = j - 1; k < ROW && l >= 0 && charPosition < claimedWord.length(); k++, l--, charPosition++)
						if(foundAMatch(k, l, claimedWord[charPosition])) {
							findCounter++;
							wc.characterPositionX = k;
							wc.characterPositionY = l;
							container.push_back(wc);
							if(findCounter == claimedWord.length()) {
								for(unsigned int pos = 0; pos < container.size(); pos++)
									if((container[pos].characterPositionX == rowPosition) && (container[pos].characterPositionY == columnChoice)) {
										return CAN_CLAIM; }
								return CANT_CLAIM; }
						 }
				}
				container.clear();
			}
		}
return NOT_FOUND;
}

bool board::isEmpty(int posX, int posY)
{
	if(gameboard[posX][posY] == '.')
		return true;
	else
		return false;
}

bool board::tileIsTouching(int posX, int posY)
{
	if(checkBoundaries(posX - 1, posY)) { // make sure the position to the left is within boundaries
		if(!isEmpty(posX - 1, posY)) // check if a tile is touching to the left
			return true; }
	if(checkBoundaries(posX + 1, posY)) { // make sure the position to the right is within boundaries
		if(!isEmpty(posX + 1, posY)) // check if a tile is touching to the right
			return true; }
	if(checkBoundaries(posX, posY - 1)) { // make sure the position above is within boundaries
		if(!isEmpty(posX, posY - 1)) // check if a tile is touching above
			return true; }
	if(checkBoundaries(posX, posY + 1)) { // make sure the position below is within boundaries
		if(!isEmpty(posX, posY + 1)) // check if a tile is touching below
			return true; }

	return false;
}

void board::undoMove(int pos, int column)
{
	gameboard[pos][column] = '.';
}

int board::wordSearch(string claimedWord, int rowPosition, int columnChoice)
{
	int searchU, searchD, searchL, searchR, searchDUL, searchDUR, searchDDL, searchDDR;

	searchU = searchUp(claimedWord, rowPosition, columnChoice);
	searchD = searchDown(claimedWord, rowPosition, columnChoice);
	searchL = searchLeft(claimedWord, rowPosition, columnChoice);
	searchR = searchRight(claimedWord, rowPosition, columnChoice);
	searchDUL = searchDiagonalUpLeft(claimedWord, rowPosition, columnChoice);
	searchDUR = searchDiagonalUpRight(claimedWord, rowPosition, columnChoice);
	searchDDL = searchDiagonalDownLeft(claimedWord, rowPosition, columnChoice);
	searchDDR = searchDiagonalDownRight(claimedWord, rowPosition, columnChoice);

	if((searchU == CAN_CLAIM) || (searchD == CAN_CLAIM) || (searchL == CAN_CLAIM) || (searchR == CAN_CLAIM)
			|| (searchDUL == CAN_CLAIM) || (searchDUR == CAN_CLAIM) || (searchDDL == CAN_CLAIM) || (searchDDR == CAN_CLAIM))
		return CAN_CLAIM;

	else if((searchU == CANT_CLAIM) || (searchD == CANT_CLAIM) || (searchL == CANT_CLAIM) || (searchR == CANT_CLAIM)
			|| (searchDUL == CANT_CLAIM) || (searchDUR == CANT_CLAIM) || (searchDDL == CANT_CLAIM) || (searchDDR == CANT_CLAIM))
		return CANT_CLAIM;
	else
		return NOT_FOUND;
}
