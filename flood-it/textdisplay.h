#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <sstream>

class TextDisplay {
	char **theDisplay;  // a grid to display to the screen
	unsigned const int gridSize;  // dimension size of the grid
	unsigned int colours[5];  // container that tracking the total number of 
							 // each colour appearing in the grid.
public:
	TextDisplay(int n); 
	~TextDisplay();

	void notify(int r, int c, char ch);  // called by a cell, to notify a new colour 
										// the cell and its location.
	bool filled();  // check if the grid is filled with any one colour
	void print();  // print out the grid to the screen
};

#endif
