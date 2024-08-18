#ifndef GOLD_H
#define GOLD_H 
#include "event.h"
#include "adventurer.h"
#include <iostream>

//Gold Interface
class Gold : public Event{
public:
	// All function headers and descriptions inherited from Event.h unless otherwise specified.
	Gold();
	~Gold();
	void percept() override;
	void encounter(Adventurer&) override;
	void set_type(string) override;
	string get_type() override;
};
#endif