#include "wumpus.h"

#include <iostream>

using namespace std;
Wumpus::Wumpus() : Event("W"){}

Wumpus::~Wumpus(){}

void Wumpus::percept(){
	cout << "\n------------------" << endl;
	cout << "You smell a terrible stench." << endl;
	cout << "\n------------------" << endl;
}

void Wumpus::encounter(Adventurer &a){
	cout << "\n------------------" << endl;
	cout << "You enter the room and come face to face with the wumpus!" << endl;
	cout << "\n------------------" << endl;
	
	if(a.has_armour && a.armour_hit > 0){
			--a.armour_hit;
			
			cout << "\n------------------" << endl;
			cout << "The wumpus swipes at your armour, but you swiftly exit! You live to tell the tale." << endl;
			cout << "------------------" << endl;
	}
	else if(!a.has_armour || a.armour_hit == 0){
			cout << "\n------------------" << endl;
			cout << "The wumpus gets the better of you, and another adventurer perishes. Who knows what it'll do with your body." << endl;
			cout << "YOU" << endl;
			cout << "DIED" << endl;
			cout << "------------------" << endl;
			a.is_alive = false;
	}
}

void Wumpus::set_type(const string some_type){
	type = some_type;
}

string Wumpus::get_type(){
	return type;
}
//Wumpus Implementation
