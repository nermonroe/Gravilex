/*
 * game.h
 *
 *  Created on: Jan 19, 2016
 *      Author: Nerissa
 */

#ifndef GAME_H_
#define GAME_H_

#include "player.h"
#include "computer.h"

	const int ROUNDS = 13;

class game
{
public:
	game() { computerScore = 0; playerScore = 0; }
	~game() { cout<<"Thanks for playing!"<<endl; }

	int getPlayerScore() { return playerScore; }
	int getComputerScore() { return computerScore; }
	void setPlayerScore(int ps) { playerScore = ps; }
	void setComputerScore(int cs) { computerScore = cs; }
	void addScore() { computerScore += c.getScore(); playerScore += p.getScore(); }
	void announceScore() { cout<<"Score so far: "<<"You = "<<playerScore<<" "<<"Me = "<<computerScore<<endl; }
	void gamePlay(board& b, tile& playerTiles, tile& computerTiles, string dictionary[], int);

private:
	int computerScore;
	int playerScore;
	computer c;
	player p;
};



#endif /* GAME_H_ */
