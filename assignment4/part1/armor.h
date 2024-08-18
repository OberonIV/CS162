#ifndef ARMOR_H
#define ARMOR_H
#include "event.h"
#include "adventurer.h"
#include <iostream>
using namespace std;

class Armor : public Event{
public:
	// All function headers and descriptions inherited from Event.h unless otherwise specified.
	Armor();
	~Armor();
	void percept() override;
	void encounter(Adventurer& a);
	void set_type(string) override;
	string get_type() override;
};
#endif