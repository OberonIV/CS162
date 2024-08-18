#include "event.h"

#include <iostream>

using namespace std;

Event::Event() : type(""){}

Event::Event(const string type) : type(type){}

Event::~Event(){}

bool Event::play_again(Adventurer& a){
	char play_again;
	
	while(true){
		cout << "Would you like to play again?" << endl;
		
		cout << "Enter (y/n): ";
		cin >> play_again;
		
		if(play_again == 'y'){
			return true;
		}
		else if(play_again == 'n'){
			return false;
		}
		else{
			cout << "Please enter a valid input." << endl;
		}
		
	}
}
//Event Implementation
