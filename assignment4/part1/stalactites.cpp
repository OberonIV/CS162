#include "stalactites.h"

#include <iostream>

using namespace std;
Stalactite::Stalactite() : Event("S"){}

Stalactite::~Stalactite(){}

void Stalactite::percept(){
	cout << "\n------------------" << endl;
	cout << "You hear water dripping..." << endl;
	cout << "\n------------------" << endl;
}

bool Stalactite::event_outcome(){
	if(rand() % 2 == 0){
		return false;
	}
	else{
		return true;
	}
}

void Stalactite::encounter(Adventurer &a){
	cout << "\n------------------" << endl;
	cout << "Oh no! You enter the room with the stalactitle, and it falls on your head!" << endl;
	cout << "\n------------------" << endl;
	
	if(event_outcome()){
		cout << "\n------------------" << endl;
		cout << "You dodge it! You get to live another day." << endl;
		cout << "------------------" << endl;
	}
	else{
		if(a.has_armour && a.armour_hit > 0){
			--a.armour_hit;
			
			cout << "\n------------------" << endl;
			cout << "Ouch! You get hit, but your armor saves your life!" << endl;
			cout << "------------------" << endl;
		}
		else if(!a.has_armour || a.armour_hit == 0){
			cout << "\n------------------" << endl;
			cout << "The stalactite claims your life. Yet another adventurer has fallen." << endl;
			cout << "YOU" << endl;
			cout << "DIED" << endl;
			cout << "------------------" << endl;
			a.is_alive = false;
		}
	}
}

void Stalactite::set_type(const string some_type){
	type = some_type;
}

string Stalactite::get_type(){
	return type;
}
//Stalactites Implementation
