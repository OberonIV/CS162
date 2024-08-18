#ifndef MANAGER_H
#define MANAGER_H 

#include "airport.h"
#include <iostream>
#include <fstream>

using namespace std;

class Manager
{
private:
	int num_airports;	//number of airports
	Airport* a_arr;		//airport array

public:
/*********************************************************************
** Function: Manager constructor
** Description: Initializes manager object
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: All private variables are initialized
*********************************************************************/ 
	Manager();
	/*********************************************************************
** Function: Manager destructor
** Description: Deallocates all manager memory
** Parameters: None
** Pre-Conditions: Manager objects exist
** Post-Conditions: All memory is cleared
*********************************************************************/ 
	~Manager();
	/*********************************************************************
** Function: Populate
** Description: Populates manager object with information from file
** Parameters: Fin file
** Pre-Conditions: File should exist
** Post-Conditions: Manager is populated
*********************************************************************/ 
	void populate(ifstream&);
	/*********************************************************************
** Function: init
** Description: Initializes manager object with information from file
** Parameters: None
** Pre-Conditions: airport.txt exists and is in the proper format
** Post-Conditions: Manager is initialized
*********************************************************************/ 
	int init();
	/*********************************************************************
** Function: Print Menu
** Description: Prints menu
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Menu options are printed to console
*********************************************************************/ 
	void print_menu();
	/*********************************************************************
** Function: Get Menu Choice
** Description: Gets menu choice from user
** Parameters: None
** Pre-Conditions: Print menu is called
** Post-Conditions: Users choice is returned 
*********************************************************************/ 
	int get_menu_choice();
	/*********************************************************************
** Function: Print all
** Description: All flight information is printed to console
** Parameters: None
** Pre-Conditions: Everything is populated correctly
** Post-Conditions: Airport and Flight information are printed to console
*********************************************************************/ 
	void print_all();
	/*********************************************************************
** Function: Check Flight control
** Description: Allows user to check for specific flight
** Parameters: None
** Pre-Conditions: Everything is populated correctly
** Post-Conditions: If flight exists, prints, if not, error
*********************************************************************/ 
	void check_flight_control();
	/*********************************************************************
** Function: Get airport choice
** Description: Gets airport choice from user
** Parameters: int airport_choice
** Pre-Conditions: Menu option is called
** Post-Conditions: Airport choice is returned
*********************************************************************/ 
	int get_airport_choice(int&);
	/*********************************************************************
** Function: Get flight choice
** Description: Gets flight choice from user
** Parameters: int airport_choice
** Pre-Conditions: Menu option is called
** Post-Conditions: Flight choice is returned
*********************************************************************/ 
	int get_flight_choice(int&, int);
	/*********************************************************************
** Function: Add flight control
** Description: Adds a flight to array based on user input
** Parameters: None
** Pre-Conditions: Everything is populated correctly, menu option is called
** Post-Conditions: Flight is added to airport object
*********************************************************************/ 
	void add_flight_control();
	/*********************************************************************
** Function: Cancel flight control
** Description: Removes a flight from array based on user input
** Parameters: None
** Pre-Conditions: Everything is populated correctly, menu option is called
** Post-Conditions: Flight is removed from airport object
*********************************************************************/ 
	void cancel_flight_control();
	/*********************************************************************
** Function: Take off control
** Description: Moves flight from current airport to destination airport
** Parameters: None
** Pre-Conditions:Everything is populated correctly, menu option is called
** Post-Conditions: Flight is moved from current location to destination
*********************************************************************/ 
	void take_off_control();
	/*********************************************************************
** Function: Stats control
** Description: Prints airport statistics
** Parameters: None
** Pre-Conditions: Everything is populated correctly, menu option is called
** Post-Conditions: Airport statistics are printed. 
*********************************************************************/ 
	void stats_control();
	/*********************************************************************
** Function: Get Flight
** Description: Gets a reference to a flight object inside airport objects
** Parameters: airport_index, flight_index
** Pre-Conditions: get_flight is called
** Post-Conditions: Reference to flight object is returned.
*********************************************************************/ 
	Flight& get_flight(int airport_index, int flight_index);	
	/*********************************************************************
** Function: Run
** Description: runs different function based on user choice. Once ended, write all data to file
** Parameters: None
** Pre-Conditions: All methods are correctly implemented
** Post-Conditions: Program runs until quit is selected, saves data to file
*********************************************************************/ 
	void run();
	/*********************************************************************
** Function: save_to_file
** Description: Writes all data to file by calling flight and airport write to file functions
** Parameters: None
** Pre-Conditions: All objects are filled
** Post-Conditions: The data is written to file
*********************************************************************/ 
	void save_to_file();
};
#endif