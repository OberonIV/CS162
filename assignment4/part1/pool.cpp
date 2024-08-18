#include "pool.h"
#include <iostream>

using namespace std;
Pool::Pool() : Event("P"){}

Pool::~Pool(){}

void Pool::percept(){
	cout << "\n------------------" << endl;
	cout << "You hear wind blowing." << endl;
	cout << "\n------------------" << endl;
}

void Pool::encounter(Adventurer &a){
	cout << "\n------------------" << endl;
	cout << "You take a deep breath, and you dive deep underneath the water." << endl;
	cout << "\n------------------" << endl;
	
}

void Pool::set_type(const string some_type){
	type = some_type;
}

string Pool::get_type(){
	return type;
}
//Pool Implementation
