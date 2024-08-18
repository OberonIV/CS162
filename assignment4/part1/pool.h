#ifndef POOL_H
#define POOL_H 
#include "event.h"
#include "adventurer.h"
#include <iostream>
//Pool Interface
class Pool : public Event{
public:
	// All function headers and descriptions inherited from Event.h unless otherwise specified.
	Pool();
	~Pool();
	void percept() override;
	void encounter(Adventurer&) override;
	void set_type(string) override;
	string get_type() override;
};

#endif