# Flood-It
Flood-it Thinking Game

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