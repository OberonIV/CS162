#ifndef GAME_H
#define GAME_H 

#include "room.h"
#include "gold.h"
#include "stalactites.h"
#include "pool.h"
#include "wumpus.h"
#include "adventurer.h"
#include "armor.h"

#include <vector>
#include <iostream>
#include <ncurses.h>
using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:
	
	vector<vector<Room>> board;	//2D array of Rooms
	
	Adventurer a;

	//other member variables:
	int side; 				//side of the board
	int num_arrows; 		//keep track of number of errors remaining
	int oxygen;
	bool debug_view;		//debug mode or not


	//feel free to add more variables...

public:

	//suggested functions:
/*********************************************************************
** Function: Game();
** Description: Game constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Game is created
*********************************************************************/ 
	Game();
/*********************************************************************
** Function: ~Game()
** Description: Game destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Game is destroyed
*********************************************************************/
	~Game();
/*********************************************************************
** Function: set_up()
** Description: Initializes all integers
** Parameters: int
** Pre-Conditions: int exists
** Post-Conditions: Inits all variables, game board is created
*********************************************************************/	
	void set_up(int);
/*********************************************************************
** Function: display_game()
** Description: Prints game board and events
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Game board is printed
*********************************************************************/
	void display_game() const;
/*********************************************************************
** Function: check_win(const Adventurer&)
** Description: Checks if any win condition is fulfilled
** Parameters: Adventurer& a
** Pre-Conditions: Adventurer object is created
** Post-Conditions: Win conditions are achieved
*********************************************************************/
	bool check_win(const Adventurer&) const;
/*********************************************************************
** Function: get_dir()
** Description: Gets the direction of movement
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: dir is defined
*********************************************************************/
	char get_dir();
/*********************************************************************
** Function: wumpus_move()
** Description: Handles wumpus movement
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The wumpus is moved to specified board position
*********************************************************************/
	void wumpus_move();
/*********************************************************************
** Function: fire_arrow(int, int)
** Description: Handles logic for firing arrow
** Parameters: int, int
** Pre-Conditions: Arrow event is called
** Post-Conditions: Arrow is fired
*********************************************************************/
	void fire_arrow(int, int);
/*********************************************************************
** Function: move_up
** Description: Handles logic for moving up
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Adventurer is moved up
*********************************************************************/
	void move_up();
/*********************************************************************
** Function: move_down
** Description: Handles logic for moving down
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Adventurer is moved down
*********************************************************************/
	void move_down();
/*********************************************************************
** Function: move_left
** Description: Handles logic for moving left
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Adventurer is moved left
*********************************************************************/
	void move_left();
/*********************************************************************
** Function: move_right
** Description: Handles logic for moving right
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Adventurer is moved right
*********************************************************************/
	void move_right();
/*********************************************************************
** Function: move(char)
** Description: Handles logic for moving adventurer
** Parameters: char
** Pre-Conditions: Direction of movement is defined
** Post-Conditions: Adventurer is moved in specified direction
*********************************************************************/
	void move(char);
/*********************************************************************
** Function: get_input()
** Description: Gets user input
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Input is taken
*********************************************************************/
	char get_input();
/*********************************************************************
** Function: play_game(int, bool)
** Description: Calls all game logic
** Parameters: Size, Debug
** Pre-Conditions: Size and Debug are defined
** Post-Conditions: Game is played
*********************************************************************/
	void play_game(int, bool);
/*********************************************************************
** Function: set_size(string&, int&)
** Description: Gets user defined cave size
** Parameters: String, Int
** Pre-Conditions: None
** Post-Conditions: Size is defined
*********************************************************************/
	//feel free (and you will need) to add more functions...
	void set_size(string&, int&);
/*********************************************************************
** Function: set_debug(bool&)
** Description: Sets debug status of game
** Parameters: bool&
** Pre-Conditions: None
** Post-Conditions: Debug status is set
*********************************************************************/
	void set_debug(bool&);
/*********************************************************************
** Function: create_events
** Description: Creates and initializes all events in the game
** Parameters: vector<vector<Room>>&, Gold*&, Wumpus*&, Pool*&, Pool*&, Stalactite*&, Stalactite*&, Armor*&
** Pre-Conditions: None
** Post-Conditions: All game events are created and initialized
*********************************************************************/
	void create_events(vector<vector<Room>>&, Gold*&, Wumpus*&, Pool*&, Pool*&, Stalactite*&, Stalactite*&, Armor*&);
/*********************************************************************
** Function: Shuffle
** Description: Function that randomizes integers so that events can be randomized
** Parameters: vector<pair<int,int>>&
** Pre-Conditions: None
** Post-Conditions: Random indecies are generated
*********************************************************************/
	void shuffle(vector<pair<int,int>>&);
/*********************************************************************
** Function: set_position
** Description: Sets initial and current position to radomized row and column 
** Parameters: vector<pair<int,int>>&
** Pre-Conditions: None
** Post-Conditions: Sets initial user position to random spot on game board
*********************************************************************/
	void set_position(vector<vector<Room>>&);
/*********************************************************************
** Function: randomize_events
** Description: Uses shuffle function to randomize events 
** Parameters: vector<vector<Room>>&, vector<Event*>&
** Pre-Conditions: None
** Post-Conditions: Events are set in random rooms
*********************************************************************/
	void randomize_events(vector<vector<Room>>&, vector<Event*>&);
/*********************************************************************
** Function: check_percepts()
** Description: Checks to see if any percepts are nearby
** Parameters: const vector<vector<Room>>&
** Pre-Conditions: Events are loaded into room
** Post-Conditions: Percepts are printed if they exist
*********************************************************************/
	void check_percepts(const vector<vector<Room>>&);
/*********************************************************************
** Function: pair<int,int> random_coordinates()
** Description: Initializes a random set of coordinates upon function call
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Random coordinates are set
*********************************************************************/
	pair<int, int> random_coordinates();
/*********************************************************************
** Function: fire_up
** Description: Logic that handles arrow firing upwards
** Parameters: int&, int&, const vector<vector<Room>>&
** Pre-Conditions: None
** Post-Conditions: Arrow is fired upwards
*********************************************************************/	
	void fire_up(int&, int&, const vector<vector<Room>>&);
/*********************************************************************
** Function: fire_down
** Description: Logic that handles arrow firing downwards
** Parameters: int&, int&, const vector<vector<Room>>&
** Pre-Conditions: None
** Post-Conditions: Arrow is fired downwards
*********************************************************************/	
	void fire_down(int&, int&, const vector<vector<Room>>&);
/*********************************************************************
** Function: fire_left
** Description: Logic that handles arrow firing left
** Parameters: int&, int&, const vector<vector<Room>>&
** Pre-Conditions: None
** Post-Conditions: Arrow is fired left
*********************************************************************/	
	void fire_left(int&, int&, const vector<vector<Room>>&);
/*********************************************************************
** Function: fire_right
** Description: Logic that handles arrow firing right
** Parameters: int&, int&, const vector<vector<Room>>&
** Pre-Conditions: None
** Post-Conditions: Arrow is fired right
*********************************************************************/	
	void fire_right(int&, int&, const vector<vector<Room>>&);
/*********************************************************************
** Function: wumpus_repos()
** Description: Logic that handles repositioning the wumpus upon failed shot
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Wumpus is repositioned
*********************************************************************/
	void wumpus_repos();
/*********************************************************************
** Function: oxygen_count()
** Description: Logic that handles oxygen counting down and resetting
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Oxygen is set and iterated if neccesary 
*********************************************************************/
	void oxygen_count();
};
#endif