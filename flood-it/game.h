#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include "cell.h"
#include "textdisplay.h"

class Game {
	Cell** grid;  				 // The actual grid.
	const int gridSize;    // Size of the grid.
	int turns;						 // Number of turns remaining
	TextDisplay* display;  // The text display.

public:
	Game(int size, int turns);
	~Game();

	int getTurns();  // return the remain turn
	bool isWon();  // check if the player win the game
	void change(int state);  // Changes (0,0) and all appropriate neighbours to state

	void print();  // print out the grid to the screen
};

#endif
