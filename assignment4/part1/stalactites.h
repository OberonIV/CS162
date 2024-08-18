#ifndef STALACTITES_H
#define STALACTITES_H
#include "event.h"
#include "adventurer.h"
#include <iostream>
using namespace std;
//Stalactites Interface
class Stalactite : public Event{
public:
	// All function headers and descriptions inherited from Event.h unless otherwise specified.
	Stalactite();
	~Stalactite();
	void percept() override;
	void encounter(Adventurer&) override;
	void set_type(string) override;
	string get_type() override;
/*********************************************************************
** Function: event_outcome();
** Description: Determines whether the stalactite falls
** Parameters: None
** Pre-Conditions: Stalctite event is triggered
** Post-Conditions: None
*********************************************************************/
	bool event_outcome();
};

#endif
