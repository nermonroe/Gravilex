/*
 * main.cpp
 *
 *  Created on: Dec 24, 2015
 *      Author: Nerissa
 */

#include <fstream>

#include "game.h"

using std::ifstream;
using namespace std;

	const int DICT_SIZE = 100;

int main(int argc, char *argv[])
{
//read in the file into an array
 /*****************************************************************************************************************/
	string dictionary[100];
	ifstream fileIn;
	fileIn.open("C:/words.txt", ios::in);

	if(!fileIn.is_open()) // if the file is missing, corrupt, or simply could not be opened, warn the user
		cout<<"Could not open file"<<endl;
	else{
		while(!fileIn.eof()) { // while the end of the file has not been reached, put all of the words into the array
			for(int i = 0; i < DICT_SIZE; i++)
				fileIn >> dictionary[i];
			}
	}
	fileIn.close();
/******************************************************************************************************************/
	board b;
	tile ct, pt;
	game g;

	g.gamePlay(b, pt, ct, dictionary, DICT_SIZE);

	return 0;
}


