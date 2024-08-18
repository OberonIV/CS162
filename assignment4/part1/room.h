#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 
	Event *event;
	bool has_player;
public:
/*********************************************************************
** Function: Room();
** Description: Room constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Room is created
*********************************************************************/
	Room();
/*********************************************************************
** Function: ~Room();
** Description: Room destructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Room is destroyed
*********************************************************************/
	~Room();	
/*********************************************************************
** Function: Room&operator=(const Room &other);
** Description: Room AOO
** Parameters: Room &other
** Pre-Conditions: None
** Post-Conditions: Room is copied
*********************************************************************/
	Room &operator=(const Room &other);
/*********************************************************************
** Function: set_event()
** Description: Sets event name
** Parameters: Event*
** Pre-Conditions: None
** Post-Conditions: Event is set
*********************************************************************/
	void set_event(Event*);
/*********************************************************************
** Function: *get_event()
** Description: Event Getter
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Event is returned
*********************************************************************/
	Event *get_event() const;
/*********************************************************************
** Function: set_player_presence
** Description: Sets whether or not the player is in a room
** Parameters: bool
** Pre-Conditions: Game is started
** Post-Conditions: Player presence is set
*********************************************************************/
	void set_player_presence(bool);
/*********************************************************************
** Function: get_event_type()
** Description: Gets the type of event so it can be displayed properly
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The event type is returned
*********************************************************************/
	string get_event_type() const;
/*********************************************************************
** Function: has_event()
** Description: Check if the room contains an event
** Parameters: None
** Pre-Conditions: Game is started, board is filled
** Post-Conditions: Event is returned if it exists in room
*********************************************************************/
	bool has_event() const;
/*********************************************************************
** Function: has_adventurer()
** Description: Check if room has adventurer
** Parameters: None
** Pre-Conditions: Game is started, board is filled
** Post-Conditions: Adventurer status is returned if it exists in room
*********************************************************************/
	bool has_adventurer() const;
};

#endif