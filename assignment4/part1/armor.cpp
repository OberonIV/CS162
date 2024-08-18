#include "armor.h"
#include "adventurer.h"
#include <iostream>

using namespace std;
Armor::Armor() : Event("A"){}

Armor::~Armor(){}

void Armor::percept(){
	cout << "\n------------------" << endl;
	cout << "You feel the power!" << endl;
	cout << "\n------------------" << endl;
}

void Armor::encounter(Adventurer& a){
	cout << "\n------------------" << endl;
	cout << "You find a nice suit of armour! Probably left here by an adventurer that wasn't as lucky as you." << endl;
	cout << "\n------------------" << endl;
	a.has_armour = true;
}

void Armor::set_type(const string some_type){
	type = some_type;
}

string Armor::get_type(){
	return type;
}