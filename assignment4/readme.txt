Name: Carl Jeffri Resurreccion
ID: 934472117

Description: The first part of the assignment is my implementation of the game "Hunt the Wumpus". My game is reminicisent of old DOS text games or top down RPGS, in which a text prompt is given and the user inputs commands. The game board is created based on the size the user chooses, and special events are hidden throughout the cave that the player must overcome to win. The player must find hidden gold and escape while avoiding the monster, stalagtites, and pools. The second part of the assignment implements a program that can count how many different ways someone can walk up a set of stairs, provided they take one, two, or three steps. While the program outputs a few test outputs, it can be easily modified to take in any manner of steps.

Instructions:
	For Part 1: 
		1. Navigate to the part 1 directory
		2. For best results, type in "make clean" in order to completely reset everything
		3. Type in "make" in order to generate the game file
		4. Type in "./wumpus" to run the game, and play!
	For Part 2:
		1. Navigate to the part 2 directory
		2. For best results, type in "make clean" in order to completely reset
		everything
		3. Type in "make" in order to generate the file
		4. Type in "./stairs" to see the results!


Limitations:
	For Part 1:
		1. One limitations the program has is that it must be ran again, and does not
		impliment any "play-again" functionality.
		*********
		NOTE: During valgrind, there is an error that only occurs the first time the player enters the left-most room. Although there's an error, all memory is freed and none of 		the functionality is impacted.
		I do not know why this happens, and no one I asked could figure it out, but everything still works.
		*********
	For Part 2:
		1. The program only shows the provided test cases, and does not support user input.

Extra Credit:
	1. I only implemented the Armour class as extra credit in this assignment. This was relatively simple to implement as it was another event. This event allows the player
	to pick up armour in order to protect the usser from two hits. I attempted to implement other extra credit options, but broke the program and I did not have enough time to debug.
	2. The play again functions are defined but are not implemented due to memory errors.

Questions:
	1. The Event has-a Gold, Pool, Stalactite, Wumpus, Armour.
	Gold, Pool, Stalactite, Wumpus, Armour is-a Event, is an Event.
	2. I made the Event Encounter, Percept, Get_Type, and Set_Type events virtual. This is because I can then define these functions in the base class Event, and override 	the 	functions in each individual Event. These are pure virtuals, as they do not
	have any initial definitions.
	3. Yes. There are destructors in order to clear all memory, and the program often
	copies data from one object (room) to another, and clear the old data.
	4. I was able to draw the logic of the recursive function with a tree. The
	recursive function will call itself until any base cases are called, and will add
	up each time it hits the base case. I tried to simplify the base cases as much as possible in order to minimize any failure, as I had that occure to me in lab, where
	a certain exception happs.
	5. The most challenging part of the assignment was randomizing the Events onto the grid. It took a lot of time finding solutions of forums and implementing them. If 
	done differently, I would try to implement a simplier and more consise solution,
	as opposed to four different functions to randomize everything.

Thank you to the TA who grades this! 