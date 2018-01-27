#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "textdisplay.h"

static const int MAX_NEIGHBOURS = 4;
static const int NO_PREVIOUS = -1;


class Cell {
	static TextDisplay* display; // pointer to grid of TextDisplay
	bool inProgress;  
	int state;  // current colour
	int prevState;  // previous colour
	int numNeighbours;  // number of neighbour of this cell
	Cell* neighbours[MAX_NEIGHBOURS];  // container to store pointers to neighbours
	int row, col;
	// Add other private members if necessary

	void notifyNeighbours();   // Tell all of my neighbours that I have been
	// switched.
	void notifyDisplay();  // notify grid of textDisplay new colour of this cell

public:
	Cell();  // Default constructor

	int getState();  // initialize initial colour of this cell
	void setState(int change);         // Changes state to state
	void setCoords(int row, int col);  // initialize of location info. of this cell.

	void addNeighbour(Cell* neighbour);  // add neighbours of this cell to the container.
	static void addDisplay(TextDisplay* display);  // subscribe the grid of TextDisplay
												   // to each Cell.
	void notify(int current, int previous = NO_PREVIOUS); // notify to a neighbour cell
														// the change of colour of this cell.
};
#endif
