/****************************************************** 
** Program: wumpus.cpp 
** Author: Carl Jeffri Resurrecion 
** Date: 3/10/2024 
** Description: This is an implementation of the classic game
** "Hunt the Wumpus". This program displays a grid, and allows the user
** to control an adventurer that is navigating a cave in order to get the
** gold and win the game.
** Input: The user will first input the size of the cave, then if they want to 
** play in debug mode or not. Once the game is displayed, the program will prompt
** the user on their current move.
** Output: The program will output the game code, the precepts, and options, and if the user
** chooses debug mode, the events on the screen. It will output the outcomes of each event.
******************************************************/ 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <ncurses.h>
#include "game.h"

using namespace std;


int main()
{
	//set the random seed
	srand(time(NULL));
	
	//side length: hardcoded value for now
	Game g;
	string size_input;
	int size = 5;
	g.set_size(size_input, size);
	bool debug = false;
	g.set_debug(debug);
	
	//get one input: side length of the cave


	//get the 2nd input --> debug mode or not

	//Play game
	g.play_game(size, debug);

	endwin();
	return 0;
}