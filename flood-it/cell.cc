#include "cell.h"
#include <iostream>
#include <string>
using namespace std;

TextDisplay* Cell::display = NULL;


/*********** Cell::Cell ***********
     Purpose: A constructor to initialized all the required
     		 fields of Cell Class

     Returns: n.a


     Errors: n.a


     Globals: n.a
************************************/
Cell::Cell(){
	inProgress = true;
	numNeighbours = 0;

}  

/*********** Cell::notifyNeighbours ***********
     Purpose: to notify all neighbours of the cell about the change

     Returns: void


     Errors: n.a


     Globals: n.a
************************************/
void Cell::notifyNeighbours(){
	for (int i = 0; i < numNeighbours; i++){
		neighbours[i]->notify(state, prevState);
	}

}   // Tell all of my neighbours that I have been switched.



/*********** Cell::notifyDisplay ***********
     Purpose: to notify grid of textDisplay new colour of this cell

     Returns: void


     Errors: n.a


     Globals: None
************************************/
void Cell::notifyDisplay(){
	display->notify(row, col, state+'0'); // change state from number to character type
}


/*********** Cell::getState ***********
     Purpose: to return current state

     Returns: int


     Errors: n.a


     Globals: None
************************************/
int Cell::getState(){
	return state;
}


/*********** Cell::setState ***********
     Purpose: to initialize the state and previous state
     
     Returns: void


     Errors: n.a


     Globals: None
************************************/
void Cell::setState(int change){
	state = change;
	prevState = change;
	notifyDisplay();
}   // Changes state to state


/*********** Cell::setCoords ***********
     Purpose: initialize location information
     		  row and col of this cell.
     
     Returns: void


     Errors: n.a


     Globals: None
************************************/
void Cell::setCoords(int row, int col){
	this->row = row;
	this->col = col;
}

/*********** Cell::addNeighbour ***********
     Purpose: add neighbours of this cell to the container.
     
     Returns: void


     Errors: n.a


     Globals: None
************************************/
void Cell::addNeighbour(Cell* neighbour){
	neighbours[numNeighbours] = neighbour;
	numNeighbours++;
}

/*********** Cell::addDisplay ***********
     Purpose: subscribe the grid of TextDisplay to each Cell.
     
     Returns: void


     Errors: n.a


     Globals: None
************************************/
void Cell::addDisplay(TextDisplay* display){
	Cell::display = display;
}

/*********** Cell::notify ***********
     Purpose: notify to a neighbour cell the change of colour of this cell.
     
     Returns: void


     Errors: n.a


     Globals: None
************************************/
void Cell::notify(int current, int previous){
	if (state == previous){ // check whether a neighbour cell of the celling notifying change
							// has same colour with previous colour of the notitying cell.
		notify(current);// the neighbour need to change its colour.
	} else if (previous == -1){  // either called by the game or called while 
								 // notifying neighbours.
		if (state != current) {  // change colour only when different colour is notified
			prevState = state;  // current colour becomes previous colour
			state = current;  // the notified colour becomes current colour
			//inProgress = false;
			notifyDisplay();  // update display the new colour
			notifyNeighbours();  // continue to notify neighbours.
		}
	}
}





