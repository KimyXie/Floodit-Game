#include "game.h"
#include "PRNG.h"

extern PRNG prng;

using namespace std;


/*********** Game::Game ***********
     Purpose: A constructor to initialized all the required
     		 fields of Game Class

     Returns: n.a


     Errors: n.a


     Globals: n.a
************************************/
Game::Game(int size, int turns): gridSize(size), turns(turns){
	display = new TextDisplay(size);// create a new TextDisplay
	grid = new Cell* [size];// create rows of grid
	for (int i = 0; i < size; i++){
		grid[i] = new Cell[size]; // create cells in each column
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			grid[i][j].addDisplay(display);  // subscribe display to each cell
			grid[i][j].setCoords(i, j);  // initialze coordinate
			grid[i][j].setState(prng(4)); // initialize state and prveState
		} // for
	} // for
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == 0 && j == 0){// left top cells having two neighbours
				grid[i][j].addNeighbour(&grid[0][j+1]);
				grid[i][j].addNeighbour(&grid[i+1][0]);
			}//if
			else if (i == 0 && j == size-1){// right top cells having two neighbours
				grid[i][j].addNeighbour(&grid[0][j-1]);
				grid[i][j].addNeighbour(&grid[i+1][j]);
			}//else if
			else if (i == size - 1 && j == 0){// left bottom cells having two neighbours
				grid[i][j].addNeighbour(&grid[i - 1][0]);
				grid[i][j].addNeighbour(&grid[i][j+1]);
			}//else if
			else if (i == size-1 && j == size-1){// right bottom cells having two neighbours
				grid[i][j].addNeighbour(&grid[i][j-1]);
				grid[i][j].addNeighbour(&grid[i-1][j]);
			}//else if
			else if (j == 0){// left most column cells having three neighbours
				grid[i][j].addNeighbour(&grid[i-1][0]);
				grid[i][j].addNeighbour(&grid[i][j+1]);
				grid[i][j].addNeighbour(&grid[i+1][j]);
			}//else if
			else if (i == 0){// top most row cells having three neighbours
				grid[i][j].addNeighbour(&grid[i][j-1]);
				grid[i][j].addNeighbour(&grid[i+1][j]);
				grid[i][j].addNeighbour(&grid[i][j+1]);
			}//else if
			else if (i == size - 1){// bottom most row cells having three neighbours
				grid[i][j].addNeighbour(&grid[i][j-1]);
				grid[i][j].addNeighbour(&grid[i-1][j]);
				grid[i][j].addNeighbour(&grid[i][j+1]);
			}//else if
			else if (j == size - 1){// right most column cells having three neighbours
				grid[i][j].addNeighbour(&grid[i+1][j]);
				grid[i][j].addNeighbour(&grid[i-1][j]);
				grid[i][j].addNeighbour(&grid[i][j-1]);
			}//else if
			else {// normal centre cells having four neighbours
				grid[i][j].addNeighbour(&grid[i][j-1]);
				grid[i][j].addNeighbour(&grid[i+1][j]);
				grid[i][j].addNeighbour(&grid[i][j+1]);
				grid[i][j].addNeighbour(&grid[i-1][j]);
			}//else 
		} // for
	} //for
}



/*********** Game::~Game ***********
     Purpose: A destructor to delete all the required
     		 fields of Game Class

     Returns: n.a


     Errors: n.a


     Globals: n.a
************************************/
Game::~Game(){
	for (int i = 0; i < gridSize; i++){
		delete [] grid[i];
	}
	delete [] grid;
	delete display;
}


/*********** Game::getTurns ***********
     Purpose: return the number of turns remaining 

     Returns: int


     Errors: n.a


     Globals: n.a
************************************/
int Game::getTurns(){
	return turns;
}


/*********** Game::isWon ***********
     Purpose: to check whether the user is won within the turns

     Returns: bool


     Errors: n.a


     Globals: n.a
************************************/
bool Game::isWon(){
	return display->filled();
}



/*********** Game::change ***********
     Purpose: to perform changes on grid[0][0] with given state


     Returns: void

     Errors: n.a


     Globals: n.a
************************************/
void Game::change(int state){
	grid[0][0].notify(state);
	turns--; // count down the turns.

}  // Changes (0,0) and all appropriate neighbours to state


/*********** Game::print ***********
     Purpose: to print the grid and information about remaining turns

     Returns: void


     Errors: n.a


     Globals: n.a
************************************/
void Game::print(){
	display->print(); // print the grid
	if (getTurns() == 1) { // check if remain turn is 1.
		cout << getTurns() << " move left" << endl;  // print move as singular.
	} else { 
		cout << getTurns() << " moves left" << endl;
	}
}



