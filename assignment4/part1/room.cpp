#include "room.h"
#include <iostream>
using namespace std;

//Room Implementation

Room::Room() : event(nullptr), has_player(false){
	cout << "Room made" << endl;
}

Room::~Room(){
	delete event;
	event = nullptr;
}

void Room::set_event(Event *e){
	event = e;
}

Event *Room::get_event() const{
	return event;
}

string Room::get_event_type() const{
	return event->get_type();
}
void Room::set_player_presence(bool presence){
	has_player = presence;
}

Room &Room::operator=(const Room &other){
	if(this == &other){
		return *this;
	}
	
	Event *new_event;
	
	new_event = event;
	
	delete event;
	event = new_event;
	
	has_player = other.has_player;
	return *this;
}

bool Room::has_event() const{
	return (event != nullptr);
}

bool Room::has_adventurer() const{
	return has_player;
}