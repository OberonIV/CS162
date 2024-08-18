#ifndef WUMPUS_H
#define WUMPUS_H 
#include "event.h"
#include "adventurer.h"
#include <iostream>
using namespace std;
//Wumpus Interface
class Wumpus : public Event{
public:
	// All function headers and descriptions inherited from Event.h unless otherwise specified.
	Wumpus();
	~Wumpus();
	void percept() override;
	void encounter(Adventurer &a) override;
	void set_type(string) override;
	string get_type() override;
};
#endif