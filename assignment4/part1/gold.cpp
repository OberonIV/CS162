#include "gold.h"
#include "adventurer.h"
#include <iostream>

using namespace std;
Gold::Gold() : Event("G"){}

Gold::~Gold(){}

void Gold::percept(){
	cout << "\n------------------" << endl;
	cout << "You see a glimmer nearby..." << endl;
	cout << "\n------------------" << endl;
}

void Gold::encounter(Adventurer &a){
	cout << "\n------------------" << endl;
	cout << "You found the gold! Return back to the escape room to win!" << endl;
	cout << "------------------" << endl;
	a.has_gold = true;
}
void Gold::set_type(const string some_type){
	type = some_type;
}

string Gold::get_type(){
	return type;
}
//Gold Implementation
