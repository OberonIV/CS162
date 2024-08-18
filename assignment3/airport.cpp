#include "airport.h"

using namespace std;
// Constructor
Airport::Airport() : name(""), num_flights(0), cap(0), f_arr(nullptr) {
	
}
//Destrictor
Airport::~Airport() {
	delete[] f_arr;
}

void Airport::populate_airport(ifstream& fin){
	//Your code goes here:
	// Clears memory
	delete[] f_arr;
	// Creates array based on num_pilots
	fin >> name >> num_flights >> cap;
	f_arr = new Flight[cap];
	
	for(int i = 0; i < num_flights; i++){
		f_arr[i].populate_flight(fin);
	}
	return; 
}


void Airport::add_a_flight(Flight& p){
	//Your code goes here:
	// Adds flight
	f_arr[num_flights] = p;
	//Itterates flight by 1
	num_flights++;
	return; 
}

Flight Airport::remove_a_flight(int idx){
	//Your code goes here:
	//Removes flight
	Flight removed_flight = f_arr[idx];
	for(int i = idx; i < num_flights - 1; i++){
		f_arr[i] = f_arr[i + 1];
	}
	// Deiterates num_flights
	num_flights--;
	return removed_flight;
}

void Airport::print_airport() {
	//Your code goes here:
	//Calls print_flight for num_flights to print all flights
	for(int i = 0; i < num_flights; i++){
		f_arr[i].print_flight();
	}
	return; 
}
// Accessors
string Airport::get_name(){
	return name;
}

int Airport::get_num_flights(){
	return num_flights;
}
int Airport::get_cap(){
	return cap;
}

// Mutators
string Airport::get_flight_num(int idx){
	if(idx >= 0 && idx < num_flights){
		return f_arr[idx].get_flight_num();
	}
	return "Invalid Index";
}

string Airport::get_dest(int idx){
	if(idx >= 0 && idx < num_flights){
		return f_arr[idx].get_dest();
	}
	return "Invalid Index";
}

int Airport::get_num_pilots(int idx){
	if(idx >= 0 && idx < num_flights){
		return f_arr[idx].get_num_pilots();
	}
	return -1;
}

Flight& Airport::get_flight(int idx){
	// Returns array if within index
	if(idx >= 0 && idx < num_flights){
		return f_arr[idx];
	}
	throw out_of_range("Invalid Index");
}
// Prints airport to file
void Airport::airport_to_file(ofstream& fout){
	fout << name << " " << num_flights << " " << cap << endl;
	for(int i = 0; i < num_flights; i++){
		f_arr[i].flight_to_file(fout);
	}
}