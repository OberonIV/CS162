#ifndef FLIGHT_H
#define FLIGHT_H 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Flight
{
private: 
	string flight_num;		//flight number
	string curr_loc;		//current airport
	string dest;			//destination 
	int num_pilots;			//number of pilots
	string* pilots;			//pilot array

public:
/*********************************************************************
** Function: Flight constructor
** Description: Initializes Flight objects
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: All private variables initialized
*********************************************************************/ 
	Flight();
	/*********************************************************************
** Function: Flight Destructor
** Description: Deallocates all memory used
** Parameters: None
** Pre-Conditions: Object exists
** Post-Conditions: Object memory is cleared
*********************************************************************/ 
	~Flight(void);

	Flight(int size){
		this->num_pilots = size;
		this->pilots = new string [size];
	}
/*********************************************************************
** Function: Flight AOO
** Description: Copy assignment operator for flight
** Parameters: References other flight object
** Pre-Conditions: None
** Post-Conditions: Deep copies one object to another
*********************************************************************/ 
	Flight& operator=(const Flight& other);
	/*********************************************************************
** Function: Flight CC
** Description: Copy constructor for flight
** Parameters: References other flight object
** Pre-Conditions: None
** Post-Conditions: Shallow copies flight object to new object
*********************************************************************/ 
	Flight (const Flight& other);
	/*********************************************************************
** Function: Populate Flight
** Description: Populates array from input file stream
** Parameters: File
** Pre-Conditions: File exists
** Post-Conditions: Array is populated
*********************************************************************/ 
	void populate_flight(ifstream&);
	/*********************************************************************
** Function: Print Flight
** Description: Prints flight info to console
** Parameters: f_arr
** Pre-Conditions: Flights are populated
** Post-Conditions: Flights are printed to console
*********************************************************************/ 
	void print_flight() const;
	/*********************************************************************
** Function: Set Flight Name 
** Description: Sets the flight number
** Parameters:flight_num
** Pre-Conditions: None
** Post-Conditions: Updates the flight number
*********************************************************************/ 
	void set_flight_num(string);
	/*********************************************************************
** Function: Set Current Location
** Description: Sets the current locatoin
** Parameters: curr_loc
** Pre-Conditions: None
** Post-Conditions: Updates the current location
*********************************************************************/ 
	void set_curr_loc(string);
	/*********************************************************************
** Function: Set Destination
** Description: Sets the destination of a flight
** Parameters: dest
** Pre-Conditions: None
** Post-Conditions: Destination of flight is set
*********************************************************************/ 
	void set_dest(string);
	/*********************************************************************
** Function: Set Number of Pilots
** Description: Sets the number of pilots in a flight
** Parameters: num_pilots
** Pre-Conditions: None
** Post-Conditions: Number of pilots is set
*********************************************************************/ 
	void set_num_pilots(const int);
	/*********************************************************************
** Function: Sets Pilots
** Description: Allocates the pilot memory in array
** Parameters: pilots
** Pre-Conditions: None
** Post-Conditions: Flight is updated with num_pilots slots for pilots
*********************************************************************/ 
	void set_pilots(string*);
	/*********************************************************************
** Function: Set Pilot Name
** Description: Sets the pilot name in allocated memory
** Parameters: idx
** Pre-Conditions: Pilot memory is allocated
** Post-Conditions: Memory is filled with strings containing pilot names
*********************************************************************/ 
	void set_pilot_name(int, string&);
	/*********************************************************************
** Function: Get Flight Number
** Description: Returns the flight number of flight object
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns flight_num
*********************************************************************/ 
	string get_flight_num() const;
	/*********************************************************************
** Function: Get Current Location
** Description: Returns the current location
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns curr_loc
*********************************************************************/ 
	string get_curr_loc() const;
	/*********************************************************************
** Function: Get Destination
** Description: Returns Destination
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns dest
*********************************************************************/ 
	string get_dest() const;
	/*********************************************************************
** Function: Get Number of Pilots
** Description:  Returns the number of pilots
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns num_pilots
*********************************************************************/ 
	int get_num_pilots() const;
	/*********************************************************************
** Function: Get Pilots
** Description: Returns pointed to array location of pilots
** Parameters: None
** Pre-Conditions: None 
** Post-Conditions: Returns pointer to array
*********************************************************************/ 
	string* get_pilots() const;
	/*********************************************************************
** Function: Flight to File
** Description: Writes flight data to provided file
** Parameters: fout - output file stream
** Pre-Conditions: The file stream must be open
** Post-Conditions: Writes information to file
*********************************************************************/ 
	void flight_to_file(ofstream&);
};

#endif
