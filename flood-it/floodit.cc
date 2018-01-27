#include <sstream>
#include <iostream>
#include <unistd.h>
#include "PRNG.h"
#include "game.h"

using namespace std;

/*
	Floodit

	Purpose of the game:
		To prompt users to input numbers each time to make the gird 
		flooded with the same color; users win if they accomplish above
		within given turns/moves; otherwise, they lose. 
	
	Explanation of Implementation of the program:

	1. Usage: to take care of all the possible range errors

	2. How game works:
		- The user will input one number [0-4] each time, 
		each number represent a color, the input color will affect
		the flooding range starting from top left cell origin (0,0)

		- Each cell has its coordinates. Once the origin cell changes
		its color, it will notify its neighbours to change accordingly.
		But the change only happens when the neighbour has the
		same color as the origin. Once relating neighbours finished
		their change, recursively, they will inform their neighbours.

		- Program ends with either won or lost. Won happens when users
		flood the whole grid into one colour within moves; If user is 
		out of moves and the grid is not completely flooded, user lost.
	
	Demostration of the program:

	./Floodit -size 5 -moves 20 -seed 7
	33340
	13332
	03244
	40244
	10133
	20 moves left
	1
	11140
	11112
	01244
	40244
	10133
	19 moves left
	2
	22240
	22222
	02244
	40244
	10133
	18 moves left
	0
	00040
	00000
	00044
	40044
	10133
	17 moves left
	4
	44444
	44444
	44444
	44444
	14133
	16 moves left
	1
	11111
	11111
	11111
	11111
	11133
	15 moves left
	3
	33333
	33333
	33333
	33333
	33333
	14 moves left
	Won
*/

PRNG prng;

void Usage(char *argv[]){
	cerr << "Usage: " << argv[0] << "[ -size N (width and height of game ) >= 2) ] |"
			" [ -moves M (number of moves until game is over) >= 1) ] |"
			" [ -seed S (seed for random-number generator (1..INT_MAX)) ]" << endl;
}



int main(int argc, char *argv[]){
	string s = "-size";
	string m = "-moves";
	string d = "-seed";
	int size = 10, moves = 20, seed = 1;
	// default values for size, moves and seed if users doesnt input anything
	
	if ((argc % 2) != 1) {	// check whether user input the correct number of inputs
		// as users must key in flag with a number attached to it as a pair.
		Usage(argv);
		return 0;
	}

	if (argc != 1) {  // flags are entered
		for (int i = 1; i < argc; i++) {
			string arg = argv[i];
			stringstream ss;
			if (arg == "-size") {	// get the size number
				++i;  // to read next arg
				ss.clear();  // clear eof flag
				ss.str(argv[i]); 
				if (!(ss >> size) || size < 2) { // the given arg is either non-number
												 // or nubmer that is on invalid range
					Usage(argv);  // print out right usage message and
					return 0;     // terminate program
				} // if
			} else if (arg == "-moves") {  // same algorithm with the case "-size"
				++i;
				ss.clear();
				ss.str(argv[i]);
				if (!(ss >> moves) || moves < 1) {
					Usage(argv);
					return 0;
				} // if
			} else if (arg == "-seed") {  // same algorithm with the case "-size"
				++i;
				ss.clear();
				ss.str(argv[i]);
				if (!(ss >> seed)  || seed < 1) {
					Usage(argv);
					return 0;
				} // if
			} else {  // other invalid input is entered
				Usage(argv);
				return 0;
			} // if
		} // for
	}//if

	// set a number to seed to generate a random number for initialize each cell in
	// the grid inside Game.
	if (seed == 1) {  // no seed flag was entered
		prng.seed(getpid()); // set random number to seed.
	} else {  // seed is specified
		prng.seed((uint32_t)seed); // set the specified number to seed 
	} // if

	Game game(size,moves);	// set up a game with given input of size of grid 
							// and moves for the game

	string input;	// to read in each color(represented by number [0-4])
					// every turn in the game
	int n;			
	game.print();	// display the grid generated when starting the game
	while (cin >> input) {
		stringstream ss(input);
		if (ss >> n && (n >= 0 && n <= 4)) {// when valid input is entered
			game.change(n);// pass number n to the game
			game.print();// print out the updated grid
			if (game.isWon()){// check whether game is over with winning
				cout << "Won" << endl;
				break;
			}// else if 
			if (game.getTurns() == 0){// check whether users are out of moves
				cout << "Lost" << endl;
				break;
			} // if
		} // if
		else {// invalid input is entered and prompted the user to key in valid inputs
			cerr<< "invalid input" << endl;
		}// else
	} // while

}

