#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "pool.h"
#include "wumpus.h"
#include "adventurer.h"
#include "armor.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ncurses.h>
#include <random>

using namespace std;

//Game Implementation

Game::Game(){
	//Game constructor
	//Your code here:
}

Game::~Game(){
	//Game destructor
	//Your code here:

}

void Game::set_up(int s){
	//set up the game
	this->side = s;

	this->num_arrows = 3; 	//start with 3 arrows
	if(!a.in_pool){
		this->oxygen = side * 2;
	}
	// Finish the remaining...
	//Your code here:
	Gold *gold;
	Wumpus *wumpus;
	Pool *pool1, *pool2;
	Stalactite *stalactite1, *stalactite2;
	Armor *armor;
	// Create the game board: 2D vector of Room objects
	board.resize(side, vector<Room>(side));
	// randomly insert events (2 pool accesses, 2 stalactites, 1 wumpus, 1 gold)
	// into the board
	create_events(board, gold, wumpus, pool1, pool2, stalactite1, stalactite2, armor);

}

//Note: you need to modify this function
void Game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;

	//print oxygen level:
	cout << "Oxygen level: " << this->oxygen << endl;
	string line = "";
	for (int i = 0; i < this->side; ++i)
		line += "-----";

	for (int i = 0; i < this->side; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->side; ++j)
		{
			if(i == a.initial_x && j == a.initial_y && board[i][j].has_adventurer() && debug_view){
				cout << "E*";
			}
			else if(i == a.initial_x && j == a.initial_y && debug_view){
				cout << "E";
			}
			else if(board[i][j].has_event() && board[i][j].get_event_type() == "G" && a.has_gold){
				cout << " ";
			}
			else if(board[i][j].has_adventurer()){
				cout << "*";
			}
			else if(board[i][j].has_event() && debug_view){
				cout << board[i][j].get_event_type();
			}
			else{
				cout << " ";
			}
			cout << "  ||";
		}
		cout << endl;
	}
	cout << line << endl;

	//example output (when finished): 
	// --------------------
	//  P || G || P ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------   
	//    ||   ||   || S ||
	// --------------------   
	// *  ||   ||   ||   ||
	// --------------------
}

bool Game::check_win(const Adventurer &a) const{
	//check if game over/win
	//Your code here:
	if(!a.is_alive){
		return true;
	}
	
	else if(a.is_alive && a.has_gold && a.current_x == a.initial_x && a.current_y == a.initial_y){
		cout << "------------------" << endl;
		cout << "You win!!!" << endl;
		cout << "------------------" << endl;
		return true;
	}
	return false;
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	//Your code here:
	cout << "Fire an arrow...." << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	

	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');

	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room

	//How to get 75%? 
	//Hint: generate a random number from 0-3, if the number is not 0, then move

	//Your code here:
	cout << "\n------------------" << endl;
	cout << "Oh no! You missed!" << endl;
	cout << "------------------" << endl;
	// Randomization Logic
	if(rand()% 4 < 3){
		cout << "\n------------------" << endl;
		cout << "The wumpus noticed you and is on the prowl! " << endl;
		cout << "------------------" << endl;
		wumpus_repos();
		return;
	}
	else{
		cout << "\n------------------" << endl;
		cout << "Phew! The wumpus didn't notice you!" << endl;
		cout << "------------------" << endl;		
		return;
	}
}

void Game::wumpus_repos(){
	// Sets pair of ints that is current coordinates
	pair<int,int> current_coordinate;
	bool found_wumpus = false;
	// Logic for moving wumpus
	for(int i = 0; i < side; i++){
		for(int j = 0; j < side; j++){
			if(board[i][j].has_event() && board[i][j].get_event_type() == "W"){
				// Sets wumpus coordinates, deletes wumpus from old room
				current_coordinate = make_pair(i, j);
				delete board[i][j].get_event();
				board[i][j].set_event(nullptr);
				found_wumpus = true;
				break;
			}
		}
		if(found_wumpus){
			break;
		}
	}
	
	if(found_wumpus){
		// Creates wumpus in randomized room
		pair<int, int> random_coordinate = random_coordinates();
		Wumpus *wumpus = new Wumpus;
		board[random_coordinate.first][random_coordinate.second].set_event(wumpus);
	}
}

void Game::fire_arrow(int x, int y){
	// The player may fire arrow...
	char dir = get_dir();
	//Your code here:
	int arrow_x = x;
	int arrow_y = y;
	// Logic for if adventurer is out of arrows
	if(num_arrows == 0){
		cout << "\n------------------" << endl;
		cout << "You're out of arrows!" << endl;
		cout << "\n------------------" << endl;		
		return;
	}
	// Logic if adventurer is in room
	else if(a.in_pool){
		cout << "\n------------------" << endl;
		cout << "You can't pull your bow out underwater!" << endl;
		cout << "\n------------------" << endl;
		return;
	}
	else{
		--num_arrows;
		switch(dir){
			case 'w':
				fire_up(x, y, board);
				break;
			case 's':
				fire_down(x, y, board);
				break;
			case 'a':
				fire_left(x, y, board);
				break;
			case 'd':
				fire_right(x, y, board);
				break;
		}
	}
	return;

}

void Game::fire_up(int &arrow_x, int &arrow_y, const vector<vector<Room>> &grid){
	// Logic for firing arrow
		cout << "\n------------------" << endl;
		cout << "\nShot an arrow up!\n" << endl;
		cout << "\n------------------" << endl;
		for(int i = 0; i < 3; i++){
			--arrow_x;
			if(arrow_x < 0){
				// Check if arrow hits wall
				cout << "\n------------------" << endl;
				cout << "\nArrow broke on a wall\n" << endl;
				cout << "\n------------------" << endl;
				break;
			}
			if(grid[arrow_x][arrow_y].has_event() && grid[arrow_x][arrow_y].get_event_type() == "W"){
				cout << "\n------------------" << endl;
				cout << " What's that!? You managed to slay the wumpus! Get the gold and escape!" << endl;
				cout << "------------------" << endl;
				a.killed_wumpus = true;
				break;
			}
		}
		
		if(!a.killed_wumpus){
			wumpus_move();
		}
}

void Game::fire_down(int &arrow_x, int &arrow_y, const vector<vector<Room>> &grid){
		cout << "\n------------------" << endl;
		cout << "\nShot an arrow down!\n" << endl;	
		cout << "\n------------------" << endl;
		for(int i = 0; i < 3; i++){
			++arrow_x;
			if(arrow_x >= side){
				cout << "\n------------------" << endl;
				cout << "\nArrow broke on a wall\n" << endl;
				cout << "\n------------------" << endl;
				break;
			}
			if(grid[arrow_x][arrow_y].has_event() && grid[arrow_x][arrow_y].get_event_type() == "W"){
				cout << "\n------------------" << endl;
				cout << " What's that!? You managed to slay the wumpus! Get the gold and escape!" << endl;
				cout << "------------------" << endl;
				a.killed_wumpus = true;
				break;
			}
		}
		
		if(!a.killed_wumpus){
			wumpus_move();
		}
}

void Game::fire_left(int &arrow_x, int &arrow_y, const vector<vector<Room>> &grid){
		cout << "\n------------------" << endl;
		cout << "\nShot an arrow up!\n" << endl;	
		cout << "\n------------------" << endl;
		for(int i = 0; i < 3; i++){
			--arrow_y;
			if(arrow_y < 0){
				cout << "\n------------------" << endl;
				cout << "\nArrow broke on a wall\n" << endl;
				cout << "\n------------------" << endl;
				break;
			}
			if(grid[arrow_x][arrow_y].has_event() && grid[arrow_x][arrow_y].get_event_type() == "W"){
				cout << "\n------------------" << endl;
				cout << " What's that!? You managed to slay the wumpus! Get the gold and escape!" << endl;
				cout << "------------------" << endl;
				a.killed_wumpus = true;
				break;
			}
		}
		
		if(!a.killed_wumpus){
			wumpus_move();
		}
}

void Game::fire_right(int &arrow_x, int &arrow_y, const vector<vector<Room>> &grid){
		cout << "\n------------------" << endl;
		cout << "\nShot an arrow up!\n" << endl;
		cout << "\n------------------" << endl;
		for(int i = 0; i < 3; i++){
			++arrow_y;
			if(arrow_y >= side){
				cout << "\n------------------" << endl;
				cout << "\nArrow broke on a wall\n" << endl;
				cout << "\n------------------" << endl;
				break;
			}
			if(grid[arrow_x][arrow_y].has_event() && grid[arrow_x][arrow_y].get_event_type() == "W"){
				cout << "\n------------------" << endl;
				cout << " What's that!? You managed to slay the wumpus! Get the gold and escape!" << endl;
				cout << "------------------" << endl;
				a.killed_wumpus = true;
				break;
			}
		}
		
		if(!a.killed_wumpus){
			wumpus_move();
		}
}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow(a.current_x, a.current_y);
		return;
	}
	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
	}
}

void Game::move_up() {
	//move player up
	//Your code here:
	if(a.in_pool){
		--oxygen;
	}
	int new_x;
	new_x = a.current_x - 1 < 0 ? side - 1 : a.current_x - 1;
	
	board[a.current_x][a.current_y].set_player_presence(false);
	
	a.current_x = new_x;
	
	board[a.current_x][a.current_y].set_player_presence(true);
	
	return;
}

void Game::move_down() {
	//move player down
	//Your code here:
	if(a.in_pool){
		--oxygen;
	}
	int new_x;
	new_x = a.current_x + 1 == side ? 0 : a.current_x + 1;
	
	board[a.current_x][a.current_y].set_player_presence(false);
	
	a.current_x = new_x;
	
	board[a.current_x][a.current_y].set_player_presence(true);
	
	return;
}

void Game::move_left() {
	//move player left
	//Your code here:
	if(a.in_pool){
		--oxygen;
	}
	int new_y;
	new_y = a.current_y - 1 < 0 ? side - 1 : a.current_y - 1;
	
	board[a.current_x][a.current_y].set_player_presence(false);
	
	a.current_y = new_y;
	
	board[a.current_x][a.current_y].set_player_presence(true);
	
	return;

}

void Game::move_right() {
	//move player right
	//Your code here:
	if(a.in_pool){
		--oxygen;
	}
	int new_y;
	new_y = a.current_y + 1 == side ? 0 : a.current_y + 1;
	
	board[a.current_x][a.current_y].set_player_presence(false);
	
	a.current_y = new_y;
	
	board[a.current_x][a.current_y].set_player_presence(true);
	
	return;
}

char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');

	
	return c;
}

//Note: you need to modify this function
void Game::play_game(int s, bool d){
	Game::set_up(s);
	this->debug_view = d;
	set_position(board);
	char input, arrow_input;
	while (Game::check_win(a) == false){
		//print game board
		Game::display_game();

		//display percerts around player's location
		//Your code here:
		check_percepts(board);
		//Player move...
		//1. get input
		input = Game::get_input();

		//2. move player
		Game::move(input);

		//3. may or may not encounter events
		//Your code here:
		if(board[a.current_x][a.current_y].has_event() && !a.in_pool){
			board[a.current_x][a.current_y].get_event()->encounter(a);
		}
		// Removes G and A if encountered
		if(board[a.current_x][a.current_y].has_event() && board[a.current_x][a.current_y].get_event_type() == "G" && !a.in_pool){
			delete board[a.current_x][a.current_y].get_event();
			board[a.current_x][a.current_y].set_event(nullptr);
		}
		
		if(board[a.current_x][a.current_y].has_event() && board[a.current_x][a.current_y].get_event_type() == "A" && !a.in_pool){
			delete board[a.current_x][a.current_y].get_event();
			board[a.current_x][a.current_y].set_event(nullptr);
		}
		// Oxygen resetting
		if(board[a.current_x][a.current_y].has_event() && board[a.current_x][a.current_y].get_event_type() == "P"){
			if(!a.in_pool){
				a.in_pool = true;
			}
			else{
				this-> oxygen = side * 2;
				a.in_pool = false;
			}
		}
		// Delete wumpus from board if killed
		if(a.killed_wumpus){
			for(int i = 0; i < side; i++){
				for(int j = 0; j < side; j++){
					if(board[i][j].has_event() && board[i][j].get_event_type() == "W"){
						delete board[i][j].get_event();
						board[i][j].set_event(nullptr);
					}
				}
			}
		}
		oxygen_count();
	}
	
	
	return;

}

void Game::set_size(string& size_input, int& size){
	// Logic for getting size
	while(true){
		cout << "Enter the cave's size from 4 - 50 (inclusive)" << endl;
		getline(cin,size_input);
		try{
			size = stoi(size_input);
			if(size <= 0){
				throw invalid_argument("size must be a positive integer");
			}
			if(size < 4 || size >50){
				throw invalid_argument("Please enter an integer between 4-50");
			}
		break;
		} 
		catch(const invalid_argument&){
			cerr << "Invalid input" << endl;
		}
	}
}

void Game::set_debug(bool& debug){
	// Logic for getting debug input
	char input;
	while(true){
		cout << "Play in debug mode? (y/n)" << endl;
		cin >> input;
		if(input == 'Y' || input == 'y'){
			debug = true;
			this->debug_view = true;
			break;
		}
		else if(input == 'N' || input == 'n'){
			debug = false;
			this->debug_view = false;
			break;
		}
	}
}

void Game::create_events(vector<vector<Room>>& grid, Gold*& gold, Wumpus*& wumpus, Pool*& pool1, Pool*& pool2, Stalactite*& stalactite1, Stalactite*& stalactite2, Armor*& armor){
	//Logic for initializing events
	gold = new Gold;
	wumpus = new Wumpus;
	pool1 = new Pool;
	pool2 = new Pool;
	stalactite1 = new Stalactite;
	stalactite2 = new Stalactite;
	armor = new Armor;
	// Create event vector and randomizes
	vector<Event *> event_list;
	event_list.assign({gold, wumpus, pool1, pool2, stalactite1, stalactite2, armor});
	randomize_events(grid, event_list);
}

void Game::shuffle(vector<pair<int,int>> &array){
	// Logic found on https://en.cppreference.com/w/cpp/numeric/random
	random_device rd;
	mt19937 g(rd());
	
	for(int i = array.size()- 1; i > 0; i--){
		uniform_int_distribution<> dis(0, i);
		int j = dis(g);
		swap(array[i], array[j]);
	}
}

void Game::randomize_events(vector<vector<Room>>& grid, vector<Event*>& event_list){
	// Logic for randomizing event coordinates
	int num_rows = grid.size();
	if(num_rows ==0) return;
	int num_cols = grid[0].size();
	if(num_cols == 0) return;
	
	vector<pair<int, int>> cell_indices;
	
	for(int i = 0; i < num_rows; i++){
		for(int j = 0; j < num_cols; j++){
			cell_indices.emplace_back(i, j);
		}
	}
	
	shuffle(cell_indices);
	// Sets events in randomized coordinates
	for(int i = 0; i < event_list.size(); i++){
		int row = cell_indices[i].first;
		int col = cell_indices[i].second;
		grid[row][col].set_event(event_list[i]);
	}
}

pair<int, int> Game::random_coordinates(){
	// Logic for generating a randomized coordinate
	pair<int, int> random_coordinate;
	
	random_coordinate.first = rand() % side;
	random_coordinate.second = rand() % side;
	// Error checking
	if(board[random_coordinate.first][random_coordinate.second].has_event()){
		// Calls recursively if event exists to generate a new random coordinate
		// so that two events cant spawn on the same square
		return random_coordinates();
	}
	else{
		return random_coordinate;
	}
	
}

void Game::set_position(vector<vector<Room>> &room_list){
	// Sets current and inital position
	// Initial and current are set to keep track of escape room
	pair<int, int> random_coordinate = random_coordinates();
	
	a.initial_x = random_coordinate.first;
	a.initial_y = random_coordinate.second;
	
	a.current_x = random_coordinate.first;
	a.current_y = random_coordinate.second;
	// Sets player presence in inital room
	room_list[a.initial_x][a.initial_y].set_player_presence(true);
}

void Game::check_percepts(const vector<vector<Room>> &grid){
	// Logic for printing precepts
	int row = a.current_x;
	int col = a.current_y;
	// Checks for percepts in each direction
	if(row > 0 && grid[row - 1][col].has_event()){
		grid[row - 1][col].get_event()->percept();
	}
	
	if(row < grid.size() - 1&& grid[row + 1][col].has_event()){
		grid[row + 1][col].get_event()->percept();
	}
	
	if(row > 0 && grid[row][col - 1].has_event()){
		grid[row][col - 1].get_event()->percept();
	}
	
	if(col < grid[row].size() - 1&& grid[row][col + 1].has_event()){
		grid[row][col + 1].get_event()->percept();
	}
}

void Game::oxygen_count(){
	// Logic for counting
	if(this->oxygen == 0){
			cout << "\n------------------" << endl;
			cout << "You drown deep under the water, and no one hears your final cries for help." << endl;
			cout << "YOU" << endl;
			cout << "DIED" << endl;
			cout << "------------------" << endl;
			a.is_alive = false;
	}
}
