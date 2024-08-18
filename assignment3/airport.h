#ifndef AIRPORT_H
#define AIRPORT_H 

#include <iostream>
#include <string>
#include <fstream>

#include "flight.h"

using namespace std;

class Airport
{
private:
	string name;		//airport name
	int num_flights;	//number of flights
	int cap;			//capacity
	Flight *f_arr;		//flight array

public:
/*********************************************************************
** Function: Airport Constructor
** Description: Initializes Airport object
** Parameters: None
** Pre-Conditions: None 
** Post-Conditions: Create airport object
*********************************************************************/ 
	Airport();
	/*********************************************************************
** Function: Airport Destructor
** Description: Deallocates all memory that is used by object
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Deallocates all memory
*********************************************************************/ 
	~Airport();
	/*********************************************************************
** Function: Populate Airport
** Description: Populates airport object from file input
** Parameters: fin file
** Pre-Conditions: The file should be open
** Post-Conditions: Airport object is populated
*********************************************************************/ 
	void populate_airport(ifstream&);
	/*********************************************************************
** Function: Add a flight
** Description: Adds a new flight to airport object
** Parameters: p - new flight object
** Pre-Conditions: None
** Post-Conditions: Flight is added to airport object
*********************************************************************/ 
	void add_a_flight(Flight&);
	/*********************************************************************
** Function: Remove a flight
** Description: Removes a flight from object
** Parameters: idx - array index that will be removed
** Pre-Conditions: idx must be within array
** Post-Conditions: Flight is removed
*********************************************************************/ 
	Flight remove_a_flight(int);
	/*********************************************************************
** Function: Print Airport
** Description: Prints airport data to console
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Airport data is printed to console
*********************************************************************/ 
	void print_airport();
	/*********************************************************************
** Function: Get Name
** Description: Gets the airport name
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns airport name
*********************************************************************/ 
	string get_name();
	/*********************************************************************
** Function: Get Number of Flights
** Description: Gets the number of flights at airport
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the number of flights
*********************************************************************/ 
	int get_num_flights();
	/*********************************************************************
** Function: Get capacity
** Description: Gets the capacity of the airport
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the capacity of the airport
*********************************************************************/ 
	int get_cap();
	/*********************************************************************
** Function: Get flight number
** Description: Returns the flight number at specified index
** Parameters: Idx
** Pre-Conditions: Flight object must exist
** Post-Conditions: Returns flight number
*********************************************************************/ 
	string get_flight_num(int);
	/*********************************************************************
** Function: Get destination
** Description: Returns the destination at specified index
** Parameters: Idx
** Pre-Conditions: Flight object must exist
** Post-Conditions: Returns dest
*********************************************************************/ 
	string get_dest(int);
	/*********************************************************************
** Function: Get Number of Pilots
** Description: Returns the number of pilots at specified index
** Parameters: Idx
** Pre-Conditions: Flight object must exist
** Post-Conditions: Returns num_pilots
*********************************************************************/ 
	int get_num_pilots(int);
	/*********************************************************************
** Function: Get pilots
** Description: Returns the pilots at specified index
** Parameters: Idx
** Pre-Conditions: Flight object must exist
** Post-Conditions: Returns pilots
*********************************************************************/ 
	string* get_pilots(int);
	/*********************************************************************
** Function: Get flight
** Description: Returns the flight at specified index
** Parameters: Idx
** Pre-Conditions: Flight object must exist
** Post-Conditions: Returns flight
*********************************************************************/ 
	Flight& get_flight(int);
	/*********************************************************************
** Function: Airport to file
** Description: Prints airport information to file
** Parameters: ofstream fout
** Pre-Conditions: File must exist
** Post-Conditions: Airport is written to file
*********************************************************************/ 
	void airport_to_file(ofstream&);
};
#endif