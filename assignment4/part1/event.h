#ifndef EVENT_H
#define EVENT_H 

#include "adventurer.h"
#include <iostream>
using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{

protected:
	string type = " ";
public:
/*********************************************************************
** Function: Event()
** Description: Event Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Event is created
*********************************************************************/
	Event();
/*********************************************************************
** Function: ~Event()
** Description: Event destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Event is destroyed
*********************************************************************/
	Event(const string);
/*********************************************************************
** Function: Event(const string)
** Description: Parametrized event constructor
** Parameters: string
** Pre-Conditions: string
** Post-Conditions: Event with name is constructed
*********************************************************************/
	virtual ~Event();
/*********************************************************************
** Function: encounter(Adventurer&)
** Description: Encounter function that handles actions
** Parameters: Adventurer& a
** Pre-Conditions: Adventurer object
** Post-Conditions: Event encounter logic is handled
*********************************************************************/
	virtual void encounter(Adventurer&) = 0;
/*********************************************************************
** Function: percept()
** Description: Handles getting percepts
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Percepts are printed
*********************************************************************/
	virtual void percept() = 0;
/*********************************************************************
** Function: get_type()
** Description: Gets the type of event
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Event type is returned
*********************************************************************/
	virtual string get_type() = 0;
/*********************************************************************
** Function: set_type()
** Description: Sets the event type
** Parameters: string
** Pre-Conditions: Event exists
** Post-Conditions: Event type is returned
*********************************************************************/
	virtual void set_type(const string) = 0;
	bool play_again(Adventurer& a);
};
#endif