#include "textdisplay.h"

using namespace std;

/*********** TextDisplay::TextDisplay ***********
     Purpose: A constructor to initialized all the required
     		 fields of TextDisplay Class

     Returns: n.a


     Errors: n.a


     Globals: n.a
************************************/
TextDisplay::TextDisplay(int n): gridSize(n){
	for (int i = 0; i < 5; i++){ // initialize the numbers of colors in the gird
		colours[i] = 0;
	}
	theDisplay = new char*[n]; // create rows of grid
	for (int i = 0; i < n; i++){
		theDisplay[i] = new char[n]; // create each cell in each columns
		for (int j = 0; j < n; j++) {
			theDisplay[i][j] = '5';  // intentionally initialize with number 
									// that is out of range to distinguish 
									// calling notify member function between when 
									// initializing grid and when playing game   
		}
	}
}



/*********** TextDisplay::~TextDisplay ***********
     Purpose: A destructor to delete all the required
     		 fields of TextDisplay Class

     Returns: n.a


     Errors: n.a


     Globals: n.a
************************************/
TextDisplay::~TextDisplay(){
	for (unsigned int i = 0; i < gridSize ; i++){
		delete [] theDisplay[i];
	}
	delete [] theDisplay;
}
	


/*********** TextDisplay::notify ***********
     Purpose: update new colour of the cell notifying to the display

     Returns: void


     Errors: n.a


     Globals: n.a
************************************/
void TextDisplay::notify(int r, int c, char ch){
	int cur = theDisplay[r][c] - '0';// transforming character to number
	if (cur != 5) {  // deduct the number of colour only when playing game
		colours[cur] -= 1;	// colours is an array keeping track of the number 
	}
	theDisplay[r][c] = ch; // updating the grid with the new colour.
	// of each color appearing in the grid, need to -1 for original colors
	colours[ch - '0'] += 1; // + 1 for new updated colour
}



/*********** TextDisplay::filled ***********
     Purpose: A constructor to initialized all the required
     		 fields of TextDisplay Class

     Returns: bool


     Errors: n.a


     Globals: n.a
************************************/
// check if the game state is over with winning
bool TextDisplay::filled(){
	unsigned int total = gridSize * gridSize; // the total number of each colour
											 // in the grid
	for (unsigned int i = 0; i < 5; i++ ){
		if (colours[i] == total){ // grid is filled with colour i
			return true; // player won
		}
	}
	return false; // didn't win yet
}



/*********** TextDisplay::print ***********
     Purpose: A constructor to initialized all the required
     		 fields of TextDisplay Class

     Returns: void


     Errors: n.a


     Globals: n.a
************************************/
void TextDisplay::print(){
	for (unsigned int i = 0; i < gridSize; i++){
		for (unsigned int j = 0; j < gridSize; j++){
			cout << theDisplay[i][j]; // print out columns in row i
		}
		cout << endl; // make new line to print out next row
	}
}


